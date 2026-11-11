#pragma once
#include "AnimationState.h"
#include "ActorStateType.h"

class IdleState : public AnimationState {
	public:
		IdleState(class AnimatedSpriteComponent* owner);

		void Update(float deltaTime) override;
		void OnEnter() override;
		void OnExit() override;

		ActorStateType GetName() const override {
			return IDLE;
		}

	protected:

};