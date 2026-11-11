#pragma once
#include "Component.h"
#include <SDL3/SDL.h>
#include "Actor.h"

class SpriteComponent:public Component {
	public:
		SpriteComponent(class Actor* owner, int drawOrder = 100);
		~SpriteComponent();
		virtual void Draw(SDL_Renderer* renderer);
		virtual void SetTexture(SDL_Texture* texture);

		int GetDrawOrder() { return mDrawOrder;  }
		float GetTexHeight() { return mTexHeight;  }
		float GetTexWidth() { return mTexWidth;  }
		SDL_Texture* GetTexture() { return mTexture; }
		float GetScale() { return mScale;  }
		void SetScale(float scale) { mScale = scale; }
	protected:
		SDL_Texture* mTexture;
		int mDrawOrder;
		float mTexWidth;
		float mTexHeight;
		float mScale;
};