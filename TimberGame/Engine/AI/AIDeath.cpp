#include "AIDeath.h"

AIDeath::AIDeath(AIComponent* owner)
	:AIState(owner)
{
}

void AIDeath::Update(float deltaTime)
{


}

void AIDeath::OnEnter()
{
	//mOwner->GetOwner()->setActorState(DEAD);
}

void AIDeath::OnExit()
{
}
