#include "AttackState.h"

AttackState::AttackState(AnimatedSpriteComponent* owner)
	:AnimationState(owner)
{
}

void AttackState::Update(float deltaTime)
{
	int frameCount = mOwner->GetFrameCount();
	int frame = 0;
	int frameDuration = 120;
	if (frameCount > 0) {
		frame = ((SDL_GetTicks() - frameStart) / frameDuration) % frameCount;
	}

	mOwner->SetFrame(frame);
}

void AttackState::OnEnter()
{
	frameStart = SDL_GetTicks();
}

void AttackState::OnExit()
{
}
