// Fill out your copyright notice in the Description page of Project Settings.


#include "HasLineOfSight.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UHasLineOfSight::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AAIController* AIController = OwnerComp.GetAIOwner())
	{
		if (UBlackboardComponent* Blackboard = AIController->GetBlackboardComponent())
		{
			if (AActor* Target = Cast<AActor>(Blackboard->GetValueAsObject(KeySelector.SelectedKeyName)))
			{

				return AIController->LineOfSightTo(Target);
			}
		}
	}
	return false;
}