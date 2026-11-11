#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class WalkingState : public AnimationState {
public:
	WalkingState(class AnimatedSpriteComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	ActorStateType GetName() const override {
		return WALKING;
	}

protected:

};