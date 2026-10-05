#include "JumpState.h"

JumpState::JumpState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void JumpState::Update(float deltaTime)
{
	int frameCount = mOwner->GetFrameCount();
	int frame = 0;
	int frameDuration = 120;
	if (frameCount > 0) {
		frame = ((SDL_GetTicks() - frameStart) / frameDuration) % frameCount;
	}

	mOwner->SetFrame(frame);
}

void JumpState::OnEnter()
{
	frameStart = SDL_GetTicks();
}

void JumpState::OnExit()
{
}
