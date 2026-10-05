#include "AnimatedSpriteComponent.h"
#include "Actor.h"

AnimatedSpriteComponent::AnimatedSpriteComponent(Actor* owner, int frameWidth, int frameHeight, int frameCount, int drawOrder)
	:SpriteComponent(owner, drawOrder)
	, frameWidth(frameWidth)
	, frameHeight(frameHeight)
	, frameCount(frameCount)
	, drawOrder(drawOrder)
	, mFrame(0)
	, mCurrentState(nullptr)
{
	mOwner->getGame()->AddSprite(this);
}

AnimatedSpriteComponent::~AnimatedSpriteComponent()
{
}

void AnimatedSpriteComponent::Draw(SDL_Renderer* renderer) {
	// This function would contain the logic to draw the sprite using the texture and frame information.
	// It would typically involve setting up the source rectangle based on the current frame and rendering it to the screen.

	if (mTextures.find(mOwner->getActorState()) != mTextures.end()) {
		Sprite& currentSprite = mTextures[mOwner->getActorState()];
		
		//if (mFrameDurations.find(mOwner->getActorState()) != mFrameDurations.end()) {
		//	frameDuration = mFrameDurations[mOwner->getActorState()];
		//}
		//else {
		//	frameDuration = 120;
		//}

		frameWidth = currentSprite.getFrameWidth();
		frameHeight = currentSprite.getFrameHeight();
		frameCount = currentSprite.getFrameCount();

		//if (frameCount > 0) {
		//	frame = (SDL_GetTicks()/frameDuration) % frameCount;
		//}

		SDL_FRect src = { mFrame * frameWidth, 0.0f, frameWidth, frameHeight };

		float destWidth = frameWidth * mScale;
		float destHeight = frameHeight * mScale;

		SDL_FRect dest = { 
			mOwner->GetPosition().x - destWidth/2.0f, 
			mOwner->GetPosition().y - destHeight/2.0f, 
			destWidth, 
			destHeight
		};

		SDL_FlipMode flip = mOwner->isFacingRight() ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

		SDL_RenderTextureRotated(
			renderer,
			currentSprite.getTexture(),
			&src,
			&dest,
			0.0,        // angle
			NULL,       // center
			flip);
		//SDL_RenderTexture(renderer, mTexture, &src, &dest);
	}
	else {
		// Handle the case where the texture for the current state is not found
		SDL_Log("Texture for state %d not found!", mOwner->getActorState());
	}
}

void AnimatedSpriteComponent::SetTexture(ActorStateType state, int frameWidth, int frameHeight, int frameCount, SDL_Texture* texture)
{
	mTextures[state] = Sprite(frameWidth, frameHeight, frameCount, texture);
}

int AnimatedSpriteComponent::GetCurrentFrame(Uint32 speed)
{
	Sprite& currentSprite = mTextures[mOwner->getActorState()];
	frameCount = currentSprite.getFrameCount();
	
	return (SDL_GetTicks() / speed) % frameCount;
}

void AnimatedSpriteComponent::Update(float deltaTime)
{
	if (mCurrentState) {
		if (mCurrentState->GetName() != mOwner->getActorState()) {
			ChangeState(mOwner->getActorState());
		}

		mCurrentState->Update(deltaTime);
	}
}

void AnimatedSpriteComponent::ChangeState(const ActorStateType name)
{
	if (mCurrentState) {
		mCurrentState->OnExit();
	}
	auto iter = mStateMap.find(name);
	if (iter != mStateMap.end()) {
		mCurrentState = iter->second;
		mCurrentState->OnEnter();
	}
	else {
		SDL_Log("Could not find current state %s in state map", ActorStateToString(name));
		mCurrentState = nullptr;
	}
}

void AnimatedSpriteComponent::RegisterState(AnimationState* state)
{
	mStateMap.emplace(state->GetName(), state);
}
