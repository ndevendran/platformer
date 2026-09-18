#pragma once
#include "Actor.h"

class Collidable : public Actor
{
public:
	Collidable(float x, float y, class Game* game);
	~Collidable();

	class SquareComponent* GetSquare() { return mSquare; }
private:
	class SquareComponent* mSquare;
	class AnimSpriteComponent* alienSprite;
};