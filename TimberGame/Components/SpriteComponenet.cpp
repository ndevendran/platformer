#include "SpriteComponent.h"



SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	:Component(owner)
	,mDrawOrder(drawOrder)
	,mTexture(nullptr)
	,mTexHeight(0.0f)
	,mTexWidth(0.0f)
	,mScale(1.0f)
{
	mOwner->getGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::SetTexture(SDL_Texture* texture) {
	mTexture = texture;
	if (mTexture != nullptr) {
		float w, h;
		SDL_GetTextureSize(texture, &w, &h);
		mTexWidth = w * mScale;
		mTexHeight = h * mScale;
		SDL_Log("Scaled floor texture size: %f x %f", mTexWidth, mTexHeight);
	}
}

void SpriteComponent::Draw(SDL_Renderer* renderer) {
	SDL_FRect r;
	r.x = mOwner->GetPosition().x - mTexWidth / 2;
	r.y = mOwner->GetPosition().y - mTexHeight / 2;
	r.w = mTexWidth;
	r.h = mTexHeight;

	SDL_SetTextureBlendMode(mTexture, SDL_BLENDMODE_NONE);

	SDL_RenderTexture(
		renderer,
		mTexture,
		nullptr,
		&r
	);
}
