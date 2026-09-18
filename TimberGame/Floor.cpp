#include "Floor.h"
#include "SquareComponent.h"

Floor::Floor(float x, float y, Game* game)
	:Collidable(x, y, game) {
	floorSprite = new SpriteComponent(this);

	SDL_Texture* texture = game->GetTexture("assets/tile_0022_rgb.png");

	if (texture == nullptr)
	{
		SDL_Log("Floor failed to get texture!");
		return;
	}
	
	float w, h;
	SDL_GetTextureSize(texture, &w, &h);

	SDL_Log("Floor texture size: %f x %f", w, h);
	
	floorSprite->SetScale(3.0f);
	floorSprite->SetTexture(texture);

	GetSquare()->SetHeight(floorSprite->GetTexHeight());
	GetSquare()->SetWidth(floorSprite->GetTexWidth());
}

void Floor::UpdateActor(float deltaTime)
{
}
