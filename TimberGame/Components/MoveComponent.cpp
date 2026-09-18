#include "MoveComponent.h"
#include "MyMath.h"


MoveComponent::MoveComponent(Actor* owner, int updateOrder):Component(owner)
{
	mForwardSpeed = 0.0f;
	mUpwardSpeed = 0.0f;
}

MoveComponent::~MoveComponent()
{
}

void MoveComponent::Update(float deltaTime)
{

	Vector2 pos = mOwner->GetPosition();

	if (true) {
		mUpwardSpeed += GRAVITY * deltaTime; // Apply gravity to upward speed
	}

	pos += Vector2(mForwardSpeed * deltaTime, mUpwardSpeed * deltaTime);

	if (pos.x < 0.0f) {
		pos.x = 0.0f; // Clamp position to the left boundary
	}
	else if (pos.x > 700.0f) {
		pos.x = 700.0f; // Clamp position to the right boundary
	}

	mOwner->SetPosition(pos);
		


}
