#include "Alien.h"
#include "Collidable.h"
#include "AIPatrol.h"
#include "AIDeath.h"
#include "WalkingState.h"
#include "IdleState.h"
#include "JumpState.h"
#include "AttackState.h"
#include "DeadState.h"

Alien::Alien(float x, float y, Game* game)
	:Collidable(x, y, game)
{
	alienSprite = new AnimatedSpriteComponent(this, 42, 42, 6);
	alienSprite->SetTexture(WALKING, 42, 42, 6, game->GetTexture("assets/AlienWalk.png"));
	alienSprite->SetFrameDuration(WALKING, 120);

	alienSprite->SetTexture(IDLE, 42, 42, 4, game->GetTexture("assets/AlienIdle.png"));
	alienSprite->SetTexture(DEAD, 42, 42, 8, game->GetTexture("assets/AlienDeath.png"));


	alienSprite->SetScale(3.0f);

	alienSprite->RegisterState(new WalkingState(alienSprite));
	alienSprite->RegisterState(new IdleState(alienSprite));
	alienSprite->RegisterState(new JumpState(alienSprite));
	alienSprite->RegisterState(new AttackState(alienSprite));
	alienSprite->RegisterState(new DeadState(alienSprite));

	alienSprite->ChangeState(IDLE);

	setActorState(IDLE);

	alienAI = new AIComponent(this);

	alienAI->RegisterState(new AIPatrol(alienAI));
	alienAI->RegisterState(new AIDeath(alienAI));
	alienAI->ChangeState("Patrol");

	alienMove = new MoveComponent(this);

	//GetSquare()->SetHeight(alienSprite->GetRenderedHeight());
	//GetSquare()->SetWidth(alienSprite->GetRenderedWidth());
	GetSquare()->SetHeight(80.0f);
	GetSquare()->SetWidth(90.0f);
	GetSquare()->SetOffset(Vector2(0.0f, 24.0f));

	mDesignation = ENEMY;

}

void Alien::UpdateActor(float deltaTime)
{
	//alienAI->ChangeState("Death");


	//Collision logic
	for (auto collidable : getGame()->GetCollidables())
	{
		if (collidable == this) {
			continue;
		}

		SquareComponent* otherSquare = collidable->GetSquare();

		if (!otherSquare) {
			continue;
		}


		if (Intersect(*GetSquare(), *otherSquare))
		{

			//float halfWidth = (mSquare->GetWidth() + otherSquare->GetWidth()) / 2.0f;
			//float halfHeight = (mSquare->GetHeight() + otherSquare->GetHeight()) / 2.0f;

			float alienHalfWidth = GetSquare()->GetWidth() / 2;
			float collidableHalfWidth = otherSquare->GetWidth() / 2;

			float halfWidth = alienHalfWidth + collidableHalfWidth;

			float alienHalfHeight = GetSquare()->GetHeight() / 2;
			float collidableHalfHeight = otherSquare->GetHeight() / 2;

			float halfHeight = alienHalfHeight + collidableHalfHeight;

			Vector2 diff = GetSquare()->GetCenter() - otherSquare->GetCenter();

			float overlapX = halfWidth - std::abs(diff.x);
			float overlapY = halfHeight - std::abs(diff.y);
			Vector2 collidableCenter = otherSquare->GetCenter();
			Vector2 sheepCenter = GetSquare()->GetCenter();


			//Horizontal collision happens when horizontal distance between centers is less than
			// the sum of their half widths
			// Horizontal collision
			Vector2 pos = GetPosition();

			if (otherSquare->GetOwner()->getActorDesignation() == PLAYER) {
				if (overlapX < overlapY)
				{
					//Hit from the side
					if (otherSquare->GetOwner()->getActorState() == ATTACKING) {
						alienAI->ChangeState("Death");
					}
				}
				else {
					//Vertical Collision
					if (diff.y < 0) {
						//Jumped on player
						alienMove->SetUpwardSpeed(-400.0f);
						otherSquare->GetOwner()->setActorState(DEAD);
					}
					else {
						// Player jumped on enemy
						alienAI->ChangeState("Death");
						setActorState(DEAD);
					}
				}


			}
			else {
				if (overlapX < overlapY)
				{
					if (diff.x > 0) {
						//Hit right side
						pos.x += overlapX;

					}
					else {
						//Hit left side
						pos.x -= overlapX;
					}
				}

				// Vertical collision
				else {
					alienMove->SetUpwardSpeed(0.0f);

					if (diff.y < 0) {
						pos.y -= overlapY;
					}
					else {
						// Alien is below the collidable
						pos.y += overlapY;
					}
				}

				SetPosition(pos);
			}

		}
	}
}
