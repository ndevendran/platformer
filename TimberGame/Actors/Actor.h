#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "Game.h"
#include "ActorState.h"
#include "MyMath.h"

class Actor
{
public:
	Actor(float x, float y, Game* game);
	~Actor();

	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; }

	void Update(float deltaTime);

	class Game* getGame() const { return mGame; }

	bool isWalking() const { return walking; }
	void setWalking(bool walk) { walking = walk; }

	bool isFacingRight() const { return facingRight; }
	void setFacingRight(bool right) { facingRight = right; }

	ActorState getActorState() const { return state; }
	void setActorState(ActorState newState) { state = newState; }

	virtual void UpdateActor(float deltaTime);
	void UpdateComponents(float deltaTime);

	bool getIsActive() const { return isActive; }
	bool setActive(bool active) { isActive = active; }

	void ProcessInput(const bool* keyState);
	virtual void ActorInput(const bool* keyState);
	
	// Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
protected:
	float posX;
	float posY;
	Vector2 mPosition;
	enum ActorState state;
	bool isActive;
	bool walking = false;
	bool facingRight = true;
	std::vector<class Component*> mComponents;
	
	Game* mGame;
};
