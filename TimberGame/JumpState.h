#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class JumpState : public AnimationState {
public:
	JumpState(class AnimatedSpriteComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	ActorStateType GetName() const override {
		return JUMPING;
	}

protected:

};