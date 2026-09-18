#pragma once
#include "MoveComponent.h"

class InputComponent :public MoveComponent {
public:
	InputComponent(class Actor* owner);
	void ProcessInput(const bool* keyState) override;
private:
	float maxForwardSpeed;
	float maxUpwardSpeed;

	int mForwardKey;
	int mBackwardKey;
	int mJumpKey;
};