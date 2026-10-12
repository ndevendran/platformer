#pragma once
#include <string>

enum ActorStateType {
	WALKING,
	JUMPING,
	ATTACKING,
	DEAD,
	IDLE,
	RISING,
	FALLING
};

std::string ActorStateToString(ActorStateType state);