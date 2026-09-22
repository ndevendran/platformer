#pragma once
#include "Collidable.h"
#include "AnimSpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "AIComponent.h"
#include "SquareComponent.h"


class Alien : public Collidable {
public:
	Alien(float x, float y, Game* game);
	void UpdateActor(float deltaTime) override;

protected:
	AnimSpriteComponent* alienSprite;
	AIComponent* alienMove;
};