#include "InputComponent.h"
#include "Actor.h"

InputComponent::InputComponent(class Actor* owner)
	:MoveComponent(owner)
	, mForwardKey(SDL_SCANCODE_RIGHT)
	, mBackwardKey(SDL_SCANCODE_LEFT)
	, mJumpKey(SDL_SCANCODE_SPACE)
	, maxUpwardSpeed(-800.0f)
	, maxForwardSpeed(200.0f)
{

}

void InputComponent::ProcessInput(const bool* keyState)
{
	float forwardSpeed = 0.0f;

	if (GetUpwardSpeed() == 0.0f) {
		mOwner->setActorState(IDLE);
	}

	if (keyState[mForwardKey])
	{
		if (GetUpwardSpeed() == 0.0f) {
			mOwner->setActorState(WALKING);
		}

		mOwner->setFacingRight(true);
		forwardSpeed = maxForwardSpeed;
	}
	if (keyState[mBackwardKey])
	{
		if (GetUpwardSpeed() == 0.0f) {
			mOwner->setActorState(WALKING);
		}

		mOwner->setFacingRight(false);
		forwardSpeed = -maxForwardSpeed;
	}

	if (keyState[mJumpKey] && GetUpwardSpeed() == 0.0f)
	{
		mOwner->setActorState(JUMPING);
		SetUpwardSpeed(maxUpwardSpeed);
	}

	SetForwardSpeed(forwardSpeed);
}
