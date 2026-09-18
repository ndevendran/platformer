#pragma once
#include <SDL3/SDL.h>
#include "Actor.h"
#include "Component.h"
#include "ActorState.h"
#include "Sprite.h"
#include "SpriteComponent.h"

class AnimSpriteComponent : public SpriteComponent
{
public:
	AnimSpriteComponent(Actor* owner, int frameWidth, int frameHeight, int frameCount, int drawOrder = 100);
	~AnimSpriteComponent();
	
	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(ActorState state, int frameWidth, int frameHeight, int frameCount, SDL_Texture* texture);
	

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

	void SetFrameDuration(ActorState state, Uint64 duration) {
		mFrameDurations[state] = duration;
	}

	float GetRenderedWidth() {
		return frameWidth * mScale;
	}

	float GetRenderedHeight() {
		return frameHeight * mScale;
	}

protected:
	// Change to a dictionary of textures for different states
	std::unordered_map<ActorState, Sprite> mTextures;
	std::unordered_map<ActorState, Uint64> mFrameDurations;

	int frameWidth;
	int frameHeight;
	int frameCount;
	int drawOrder;
	Actor* owner;
};
