#pragma once
#include "AnimatedSpriteComponent.h"

class AnimationState
{
public:
    AnimationState(AnimatedSpriteComponent* owner)
        : mOwner(owner),
        frameStart(0.0f)
    {
    }

    virtual ~AnimationState() = default;

    virtual void OnEnter() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void OnExit() = 0;
    virtual ActorStateType GetName() const = 0;

protected:
    AnimatedSpriteComponent* mOwner;
    Uint64 frameStart;
};