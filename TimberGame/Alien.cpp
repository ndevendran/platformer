#include "Alien.h"
#include "Collidable.h"
#include "AIPatrol.h"

Alien::Alien(float x, float y, Game* game)
	:Collidable(x, y, game)
{
	alienSprite = new AnimSpriteComponent(this, 42, 42, 6);
	alienSprite->SetTexture(WALKING, 42, 42, 6, game->GetTexture("assets/AlienWalk.png"));
	alienSprite->SetFrameDuration(WALKING, 120);

	alienSprite->SetTexture(IDLE, 42, 42, 4, game->GetTexture("assets/AlienIdle.png"));


	alienSprite->SetScale(3.0f);

	setActorState(IDLE);

	alienMove = new AIComponent(this);

	alienMove->RegisterState(new AIPatrol(alienMove));
	alienMove->ChangeState("Patrol");

}

void Alien::UpdateActor(float deltaTime)
{
	alienMove->Update(deltaTime);
}
