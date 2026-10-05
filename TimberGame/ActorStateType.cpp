#include "ActorStateType.h"

std::string ActorStateToString(ActorStateType state)
{
    switch (state)
    {
    case WALKING:
        return "WALKING";
    case JUMPING:
        return "JUMPING";
    case ATTACKING:
        return "ATTACKING";
    case DEAD:
        return "DEAD";
    case IDLE:
        return "IDLE";
    default:
        return "UNKNOWN";
    }
}