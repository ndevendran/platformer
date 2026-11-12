#include "SpriteComponent.h"
#include "../Actors/Camera.h"



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
	mOwner->getGame()->RemoveSprite(this);
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
	Camera* camera = mOwner->getGame()->GetCamera();
	const Vector2& cameraPosition = camera->GetPosition();
	int windowWidth, windowHeight;

	float destWidth = mTexWidth;
	float destHeight = mTexHeight;

	SDL_GetCurrentRenderOutputSize(renderer, &windowWidth, &windowHeight);
	r.x = (mOwner->GetPosition().x - cameraPosition.x) + (windowWidth/2.0f) - (destWidth / 2);
	r.y = (mOwner->GetPosition().y - cameraPosition.y) + (windowHeight/2.0f) - (destHeight / 2);
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
