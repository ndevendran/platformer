#include "Sheep.h"
#include "Collidable.h"
#include "WalkingState.h"
#include "IdleState.h"
#include "JumpState.h"
#include "AttackState.h"
#include "FallingState.h"
#include "RisingState.h"
#include "DeadState.h"
#include <fstream>


Sheep::Sheep(float x, float y, Game* game)
	:Collidable(x, y, game)
{
	sheepSprite = new AnimatedSpriteComponent(this, 42, 42, 6);
	sheepSprite->SetTexture(WALKING, 42, 42, 6, game->GetTexture("assets/SheepWalk.png"));
	sheepSprite->SetTexture(IDLE, 42, 42, 4, game->GetTexture("assets/SheepIdle.png"));
	sheepSprite->SetTexture(JUMPING, 42, 42, 8, game->GetTexture("assets/SheepJump.png"));
	sheepSprite->SetTexture(ATTACKING, 42, 42, 6, game->GetTexture("assets/SheepAttack1.png"));
	sheepSprite->SetTexture(RISING, 42, 42, 8, game->GetTexture("assets/SheepJump.png"));
	sheepSprite->SetTexture(FALLING, 42, 42, 8, game->GetTexture("assets/SheepJump.png"));
	sheepSprite->SetTexture(DEAD, 42, 42, 8, game->GetTexture("assets/SheepDeath.png"));

	sheepSprite->SetFrameDuration(WALKING, 120);
	sheepSprite->SetFrameDuration(IDLE, 200);
	sheepSprite->SetFrameDuration(JUMPING, 60);
	sheepSprite->SetFrameDuration(ATTACKING, 120);

	sheepSprite->RegisterState(new WalkingState(sheepSprite));
	sheepSprite->RegisterState(new IdleState(sheepSprite));
	sheepSprite->RegisterState(new JumpState(sheepSprite));
	sheepSprite->RegisterState(new AttackState(sheepSprite));
	sheepSprite->RegisterState(new FallingState(sheepSprite));
	sheepSprite->RegisterState(new RisingState(sheepSprite));
	sheepSprite->RegisterState(new DeadState(sheepSprite));

	sheepSprite->ChangeState(IDLE);

	sheepSprite->SetScale(3.0f);


	sheepMove = new InputComponent(this);

	//mSquare = new SquareComponent(this);
	//mSquare->SetHeight(sheepSprite->GetRenderedHeight());
	//mSquare->SetWidth(sheepSprite->GetRenderedWidth());
	GetSquare()->SetHeight(80.0f);
	GetSquare()->SetWidth(90.0f);
	GetSquare()->SetOffset(Vector2(0.0f, 24.0f));

	mDesignation = PLAYER;

}

void Sheep::UpdateActor(float deltaTime)
{
	if (!isActive) {
		return;
	}

	sheepSprite->Update(deltaTime);
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

			float sheepHalfWidth = GetSquare()->GetWidth() / 2;
			float collidableHalfWidth = otherSquare->GetWidth() / 2;

			float halfWidth = sheepHalfWidth + collidableHalfWidth;

			float sheepHalfHeight = GetSquare()->GetHeight() / 2;
			float collidableHalfHeight = otherSquare->GetHeight() / 2;

			float halfHeight = sheepHalfHeight + collidableHalfHeight;

			Vector2 diff = GetSquare()->GetCenter() - otherSquare->GetCenter();
			
			float overlapX = halfWidth - std::abs(diff.x);
			float overlapY = halfHeight - std::abs(diff.y);
			Vector2 collidableCenter = otherSquare->GetCenter();
			Vector2 sheepCenter = GetSquare()->GetCenter();


			//Horizontal collision happens when horizontal distance between centers is less than
			// the sum of their half widths
			// Horizontal collision
			Vector2 pos = GetPosition();

			if (otherSquare->GetOwner()->getActorDesignation() == ENEMY) {
				if (otherSquare->GetOwner()->getActorState() == DEAD) {
					continue;
				}

				//setActorState(DEAD);
				if (overlapX < overlapY)
				{
					//Hit from the side
					if (state != ATTACKING) {
						setActorState(DEAD);
					}
				} else {
					//Vertical Collision
					if (diff.y < 0) {
						//Jumped on enemy
						sheepMove->SetUpwardSpeed(-400.0f);
						setActorState(RISING);
						otherSquare->GetOwner()->setActorState(DEAD);
					}
					else {
						// Enemy jumped on player
						setActorState(DEAD);
					}
				}


			} else {
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
					sheepMove->SetUpwardSpeed(0.0f);

					if (diff.y < 0) {
						pos.y -= overlapY;
					}
					else {
						// Sheep is below the collidable
						pos.y += overlapY;
					}
				}

				SetPosition(pos);
			}

		}
	}

}

void Sheep::processInput(const bool* state)
{

}
