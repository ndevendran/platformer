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
	
	//frame = (SDL_GetTicks() - frameStart) / frameDuration;


	if (true) {
		mOwner->ChangeState(RISING);
		return;
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
