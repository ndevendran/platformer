#pragma once
#include "Actor.h"
#include "../Components/Sprites/SpriteComponent.h"
#include "Collidable.h"

class Floor : public Collidable {
	public:
		Floor(float x, float y, Game* game);

		void UpdateActor(float deltaTime) override;

	protected:
		SpriteComponent* floorSprite;
};