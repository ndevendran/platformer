#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class FallingState : public AnimationState {
public:
	FallingState(class AnimatedSpriteComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	ActorStateType GetName() const override {
		return FALLING;
	}

};