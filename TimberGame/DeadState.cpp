#include "DeadState.h"

DeadState::DeadState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void DeadState::Update(float deltaTime)
{
	int frameCount = mOwner->GetFrameCount();
	int frame = 0;
	int frameDuration = 120;
	if (frameCount > 0) {
		frame = (SDL_GetTicks() - frameStart) / frameDuration;
	}

	if (frame >= frameCount) {
		//mOwner->GetOwner()->setActive(false);
		return;
	}

	mOwner->SetFrame(frame);
}

void DeadState::OnEnter()
{
	frameStart = SDL_GetTicks();
}

void DeadState::OnExit()
{
}
