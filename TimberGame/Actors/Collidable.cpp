#include "Collidable.h"
#include "../Components/Sprites/AnimatedSpriteComponent.h"
#include "SquareComponent.h"
#include "../Engine/Animation/AnimationState.h"

Collidable::Collidable(float x, float y, Game* game)
	:Actor(x, y, game)
	,mSquare(nullptr)
	,alienSprite(nullptr)
{
	// Add self to list of collidables in game
	game->GetCollidables().push_back(this);


	mSquare = new SquareComponent(this);
	//mSquare->SetHeight(84.0f);
	//mSquare->SetWidth(84.0f);
}

Collidable::~Collidable()
{
	mGame->RemoveCollidable(this);
}
