#include "Sheep.h"
#include "Collidable.h"
#include <fstream>


Sheep::Sheep(float x, float y, Game* game)
	:Actor(x, y, game)
	,mSquare(nullptr)
{
	sheepSprite = new AnimSpriteComponent(this, 42, 42, 6);
	sheepSprite->SetTexture(WALKING, 42, 42, 6, game->GetTexture("assets/SheepWalk.png"));
	sheepSprite->SetTexture(IDLE, 42, 42, 4, game->GetTexture("assets/SheepIdle.png"));
	sheepSprite->SetTexture(JUMPING, 42, 42, 8, game->GetTexture("assets/SheepJump.png"));
	sheepSprite->SetTexture(ATTACKING, 42, 42, 6, game->GetTexture("assets/SheepAttack1.png"));

	sheepSprite->SetFrameDuration(WALKING, 120);
	sheepSprite->SetFrameDuration(IDLE, 200);
	sheepSprite->SetFrameDuration(JUMPING, 60);
	sheepSprite->SetFrameDuration(ATTACKING, 120);

	sheepSprite->SetScale(3.0f);


	sheepMove = new InputComponent(this);

	mSquare = new SquareComponent(this);
	//mSquare->SetHeight(sheepSprite->GetRenderedHeight());
	//mSquare->SetWidth(sheepSprite->GetRenderedWidth());
	mSquare->SetHeight(80.0f);
	mSquare->SetWidth(90.0f);
	mSquare->SetOffset(Vector2(0.0f, 24.0f));

}

void Sheep::UpdateActor(float deltaTime)
{
	for (auto collidable : getGame()->GetCollidables())
	{
		SquareComponent* otherSquare = collidable->GetSquare();

		if (!otherSquare) {
			continue;
		}




		if (Intersect(*mSquare, *otherSquare))
		{

			//float halfWidth = (mSquare->GetWidth() + otherSquare->GetWidth()) / 2.0f;
			//float halfHeight = (mSquare->GetHeight() + otherSquare->GetHeight()) / 2.0f;

			float sheepHalfWidth = mSquare->GetWidth() / 2;
			float collidableHalfWidth = otherSquare->GetWidth() / 2;

			float halfWidth = sheepHalfWidth + collidableHalfWidth;

			float sheepHalfHeight = mSquare->GetHeight() / 2;
			float collidableHalfHeight = otherSquare->GetHeight() / 2;

			float halfHeight = sheepHalfHeight + collidableHalfHeight;

			Vector2 diff = mSquare->GetCenter() - otherSquare->GetCenter();
			
			float overlapX = halfWidth - std::abs(diff.x);
			float overlapY = halfHeight - std::abs(diff.y);
			Vector2 collidableCenter = otherSquare->GetCenter();
			Vector2 sheepCenter = mSquare->GetCenter();


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

void Sheep::processInput(const bool* state)
{

}
