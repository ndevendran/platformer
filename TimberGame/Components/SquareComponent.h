#pragma once
#include "Component.h"
#include "MyMath.h"
#include "Actor.h"

class SquareComponent : public Component {
public:
	SquareComponent(class Actor* owner);
	void SetHeight(float h) { height = h; }
	float GetHeight() const { return height; }

	void SetWidth(float w) { width = w; }
	float GetWidth() const { return width; }
	const Vector2 GetCenter() const;
	void DrawDebug(SDL_Renderer* renderer);
	void SetOffset(Vector2 offset) { mOffset = offset; }
private:
	float height;
	float width;
	Vector2 mOffset;
};

bool Intersect(const SquareComponent& a, const SquareComponent& b);