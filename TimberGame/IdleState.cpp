#include "IdleState.h"
#include <SDL3/SDL.h>

IdleState::IdleState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void IdleState::Update(float deltaTime)
{
	int frameCount = mOwner->GetFrameCount();
	int frame = 0;
	int frameDuration = 120;
	if (frameCount > 0) {
		frame = ((SDL_GetTicks() - frameStart) / frameDuration) % frameCount;
	}

	mOwner->SetFrame(frame);
}

void IdleState::OnEnter()
{
	frameStart = SDL_GetTicks();
}

void IdleState::OnExit()
{
}
