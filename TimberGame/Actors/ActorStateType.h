#pragma once
#include <string>

enum ActorStateType {
	WALKING,
	JUMPING,
	ATTACKING,
	DYING,
	DEAD,
	IDLE,
	RISING,
	FALLING
};

std::string ActorStateToString(ActorStateType state);