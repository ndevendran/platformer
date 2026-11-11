#pragma once
#include "AIState.h"

class AIPatrol :public AIState {
public:
	AIPatrol(class AIComponent* owner);

	void Update(float deltaTime) override;
	void OnEnter() override;
	void OnExit() override;

	const char* GetName() const override {
		return "Patrol";
	}
protected:
	float mPatrolDuration = 0.0;
	float PATROL_TIME = 7.0;
	float mSpeed = 0.0;
};