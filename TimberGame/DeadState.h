#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class DeadState : public AnimationState {
public:
	DeadState(class AnimatedSpriteComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	ActorStateType GetName() const override {
		return DEAD;
	}

};
