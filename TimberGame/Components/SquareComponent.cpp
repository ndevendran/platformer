#include "SquareComponent.h"

SquareComponent::SquareComponent(Actor* owner)
	:Component(owner)
	,height(0.0f)
	,width(0.0f)
{
}

const Vector2 SquareComponent::GetCenter() const
{
	return mOwner->GetPosition() + mOffset;
}

bool Intersect(const SquareComponent& a, const SquareComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float halfWidth = (a.GetWidth() + b.GetWidth())/ 2.0f;
	float halfHeight = (a.GetHeight() + b.GetHeight()) / 2.0f;

    return std::abs(diff.y) < halfHeight && std::abs(diff.x) < halfWidth;
}

void SquareComponent::DrawDebug(SDL_Renderer* renderer)
{
    Vector2 center = GetCenter();

    SDL_FRect rect;
    rect.w = GetWidth();
    rect.h = GetHeight();

    // GetCenter() is the center, but SDL_RenderRect expects
    // the top-left corner.
    rect.x = center.x - rect.w / 2.0f;
    rect.y = center.y - rect.h / 2.0f;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
}
