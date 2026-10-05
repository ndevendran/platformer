#include "WalkingState.h"

WalkingState::WalkingState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void WalkingState::Update(float deltaTime)
{
	int frameCount = mOwner->GetFrameCount();
	int frame = 0;
	int frameDuration = 120;
	if (frameCount > 0) {
		frame = ((SDL_GetTicks() - frameStart) / frameDuration) % frameCount;
	}

	mOwner->SetFrame(frame);
}

void WalkingState::OnEnter()
{
	frameStart = SDL_GetTicks();
}

void WalkingState::OnExit()
{

}
