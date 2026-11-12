#pragma once
#include "Game.h"
#include "Actor.h"
#include "Sheep.h"

class Camera : public Actor {
public:
	Camera(float x, float y, Game* game);
	void UpdateActor(float deltaTime) override;


};