#include "Sprite.h"

Sprite::Sprite(int frameWidth, int frameHeight, int frameCount, SDL_Texture* texture)
	: frameWidth(frameWidth), frameHeight(frameHeight), frameCount(frameCount), texture(texture)
{
}

Sprite::Sprite()
	: frameWidth(0), frameHeight(0), frameCount(0), texture(nullptr)
{
}

Sprite::Sprite(const Sprite& other)
{
	texture = other.texture;

	SDL_Log("Copying sprite %p -> %p", &other, this);
}

Sprite::~Sprite()
{
}