#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class RisingState : public AnimationState {
public:
	RisingState(class AnimatedSpriteComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	ActorStateType GetName() const override {
		return RISING;
	}

};
