#include "Alien.h"
#include "Collidable.h"
#include "AIPatrol.h"

Alien::Alien(float x, float y, Game* game)
	:Collidable(x, y, game)
{
	alienSprite = new AnimSpriteComponent(this, 42, 42, 6);
	alienSprite->SetTexture(WALKING, 42, 42, 6, game->GetTexture("assets/AlienWalk.png"));
	alienSprite->SetFrameDuration(WALKING, 120);

	alienSprite->SetTexture(IDLE, 42, 42, 4, game->GetTexture("assets/AlienIdle.png"));


	alienSprite->SetScale(3.0f);

	setActorState(IDLE);

	alienAI = new AIComponent(this);

	alienAI->RegisterState(new AIPatrol(alienAI));
	alienAI->ChangeState("Patrol");

	alienMove = new MoveComponent(this);

	//GetSquare()->SetHeight(alienSprite->GetRenderedHeight());
	//GetSquare()->SetWidth(alienSprite->GetRenderedWidth());
	GetSquare()->SetHeight(80.0f);
	GetSquare()->SetWidth(90.0f);
	GetSquare()->SetOffset(Vector2(0.0f, 24.0f));

}

void Alien::UpdateActor(float deltaTime)
{
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

			//Vertical collision happens when vertical distance between centers is less than
			// the sum of their half heights
			// Vertical collision
			else {
				alienMove->SetUpwardSpeed(0.0f);

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
