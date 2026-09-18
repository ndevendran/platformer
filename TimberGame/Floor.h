#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "Collidable.h"

class Floor : public Collidable {
	public:
		Floor(float x, float y, Game* game);

		void UpdateActor(float deltaTime) override;

	protected:
		SpriteComponent* floorSprite;
};