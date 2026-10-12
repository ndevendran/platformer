#include "FallingState.h"

FallingState::FallingState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void FallingState::Update(float deltaTime)
{
	int frame = 5;

	mOwner->SetFrame(frame);
}

void FallingState::OnEnter()
{
}

void FallingState::OnExit()
{
}
