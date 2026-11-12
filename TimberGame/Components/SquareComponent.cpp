#include "SquareComponent.h"
#include "../Actors/Camera.h"

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
    Camera* camera = mOwner->getGame()->GetCamera();
    const Vector2& cameraPosition = camera->GetPosition();

    int windowWidth, windowHeight;

    SDL_GetCurrentRenderOutputSize(renderer, &windowWidth, &windowHeight);

    SDL_Log("Debug Viewport: %d x %d", windowWidth, windowHeight);

    rect.w = GetWidth();
    rect.h = GetHeight();

    // GetCenter() is the center, but SDL_RenderRect expects
    // the top-left corner.
    rect.x = (center.x - cameraPosition.x) + (windowWidth/2.0f) - rect.w / 2.0f;
    rect.y = (center.y - cameraPosition.y) + (windowHeight/2.0f) - rect.h / 2.0f;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
}
