#include "RisingState.h"

RisingState::RisingState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void RisingState::Update(float deltaTime)
{
	int frame = 3;

	mOwner->SetFrame(frame);
}

void RisingState::OnEnter()
{
}

void RisingState::OnExit()
{
}
