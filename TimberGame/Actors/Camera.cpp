#include "Camera.h"

Camera::Camera(float x, float y, Game* game)
	:Actor(x, y, game)
{

}

void Camera::UpdateActor(float deltaTime)
{
	SetPosition(mGame->GetPlayer()->GetPosition());
}
