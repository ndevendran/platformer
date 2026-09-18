#pragma once

#include "Component.h"
#include "Actor.h"

class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);
	~MoveComponent();
	void Update(float deltaTime) override;
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
	float GetForwardSpeed() const { return mForwardSpeed; }

	void SetUpwardSpeed(float speed) { mUpwardSpeed = speed; }
	float GetUpwardSpeed() const { return mUpwardSpeed; }

	bool HasJumpStarted() const { return jumpStarted; }
	void SetJumpStarted(bool started) { jumpStarted = started; }


private:
	float mForwardSpeed;
	float mUpwardSpeed;
	const float GRAVITY = 1500.0f; // Gravity constant
	bool jumpStarted = false; // Flag to check if the jump has started
};
