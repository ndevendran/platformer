#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class AttackState : public AnimationState {
public:
	AttackState(class AnimatedSpriteComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	ActorStateType GetName() const override {
		return ATTACKING;
	}

protected:

};