#pragma once
#include <SDL3/SDL.h>
#include "Actor.h"
#include "Component.h"
#include "ActorStateType.h"
#include "Sprite.h"
#include "SpriteComponent.h"
#include "AnimationState.h"

class AnimatedSpriteComponent : public SpriteComponent
{
public:
	AnimatedSpriteComponent(Actor* owner, int frameWidth, int frameHeight, int frameCount, int drawOrder = 100);
	~AnimatedSpriteComponent();
	
	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(ActorStateType state, int frameWidth, int frameHeight, int frameCount, SDL_Texture* texture);
	

	int GetFrameHeight() const { return frameHeight; }
	int GetFrameWidth() const { return frameWidth; }
	int GetFrameCount() const { return frameCount; }
	int GetDrawOrder() const { return drawOrder; }
	int GetCurrentFrame(Uint32 speed);
	
	void setFrameHeight(int frameH){
		frameHeight = frameH;
	}
	void setFrameWidth(int frameW){
		frameWidth = frameW;
	}
	void setFrameCount(int frameC){
		frameCount = frameC;

	}

	void SetFrameDuration(ActorStateType state, Uint64 duration) {
		mFrameDurations[state] = duration;
	}

	float GetRenderedWidth() {
		return frameWidth * mScale;
	}

	float GetRenderedHeight() {
		return frameHeight * mScale;
	}

	int GetFrame() const {
		return mFrame;
	}

	void SetFrame(int frame) {
		mFrame = frame;
	}

	void Update(float deltaTime) override;
	void ChangeState(const ActorStateType name);

	void RegisterState(class AnimationState* state);

protected:
	// Change to a dictionary of textures for different states
	std::unordered_map<ActorStateType, Sprite> mTextures;
	std::unordered_map<ActorStateType, Uint64> mFrameDurations;

	int frameWidth;
	int frameHeight;
	int frameCount;
	int drawOrder;
	int mFrame;
private:
	std::unordered_map<ActorStateType, class AnimationState*> mStateMap;
	class AnimationState* mCurrentState;
};
