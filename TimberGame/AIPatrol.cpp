#include "AIPatrol.h"

AIPatrol::AIPatrol(AIComponent* owner)
:AIState(owner)
{
	mSpeed = 30.0f;
}

void AIPatrol::Update(float deltaTime)
{
	mPatrolDuration += deltaTime;
	mOwner->GetOwner()->setActorState(WALKING);
	if (mPatrolDuration >= PATROL_TIME) {
		//Change direction
		bool facingRight = mOwner->GetOwner()->isFacingRight();
		mOwner->GetOwner()->setFacingRight(!facingRight);
		
		//Set speed
		if (facingRight) {
			mSpeed = -30.0f;
		}
		else {
			mSpeed = 30.0f;
		}

		mPatrolDuration = 0.0;
	}

	Vector2 pos = mOwner->GetOwner()->GetPosition();
	pos.x += mSpeed * deltaTime;

	mOwner->GetOwner()->SetPosition(pos);
}

void AIPatrol::OnEnter()
{
}

void AIPatrol::OnExit()
{
}
