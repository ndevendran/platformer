#pragma once
#include "Actor.h"
#include "AnimSpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "InputComponent.h"
#include "SquareComponent.h"

class Sheep : public Actor {
public:
	Sheep(float x, float y, Game* game);


	void UpdateActor(float deltaTime) override;
	void processInput(const bool* keyState);
	SquareComponent* GetSquare() { return mSquare; };

protected:
	bool jumpStarted = false;
	const float Gravity = 1500.0f; // Gravity constant
	const float JUMP_SPEED = -500.0f; // Jump speed constant
	const float FLOOR = 400.0f; // Floor position
	AnimSpriteComponent* sheepSprite;
	SquareComponent* mSquare;
	InputComponent* sheepMove;
};