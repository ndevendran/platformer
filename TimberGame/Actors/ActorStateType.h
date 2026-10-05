#pragma once
#include <string>

enum ActorStateType {
	WALKING,
	JUMPING,
	ATTACKING,
	DEAD,
	IDLE
};

std::string ActorStateToString(ActorStateType state);