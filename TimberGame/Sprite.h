#pragma once
#include <SDL3/SDL.h>


class Sprite
{
public:
	Sprite(int frameWidth, int frameHeight, int frameCount, SDL_Texture* texture);
	Sprite();
	Sprite(const Sprite& other);
	~Sprite();
	SDL_Texture* getTexture() { return texture; };
	int getFrameWidth() { return frameWidth; };
	int getFrameHeight() { return frameHeight; };
	int getFrameCount() { return frameCount; };
protected:
	int frameWidth;
	int frameHeight;
	int frameCount;
	SDL_Texture* texture;
};