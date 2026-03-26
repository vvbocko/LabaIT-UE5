// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ChoosePatrolPoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPCPatrolComponent.h"

UBTT_ChoosePatrolPoint::UBTT_ChoosePatrolPoint()
{
	NodeName = "Update Patrol Location";
}

EBTNodeResult::Type UBTT_ChoosePatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComponent.GetAIOwner();
	if (!AIController) 
	{
		return EBTNodeResult::Failed;
	}

	APawn* NPC = AIController->GetPawn();
	if (!NPC) 
	{
		return EBTNodeResult::Failed;
	}

	UNPCPatrolComponent* PatrolComponent = NPC->FindComponentByClass<UNPCPatrolComponent>();
	if (!PatrolComponent || PatrolComponent->PathPoints.Num() == 0) 
	{
		return EBTNodeResult::Failed;
	}


	int32 currentIndex = PatrolComponent->currentIndex;
	int32 direction = PatrolComponent->direction;
	AActor* CurrentPathPoint = PatrolComponent->PathPoints[currentIndex].PathPoint;
	float CurrentWaitTime = PatrolComponent->PathPoints[currentIndex].WaitTime;
	EPatrolType PatrolType = PatrolComponent->GetPatrolType();

	if (!CurrentPathPoint)
	{
		return EBTNodeResult::Failed;
	}

	FVector CurrentPointLocation = PatrolComponent->GetPathPointVector(CurrentPathPoint);
	OwnerComponent.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), CurrentPointLocation);

	if (PatrolType == EPatrolType::Cyclic)
	{
		if (PatrolComponent->PathPoints.Num() == currentIndex + 1)
		{
			currentIndex = 0;
		}
		else
		{
			currentIndex++;
		}
	}
	else if (PatrolType == EPatrolType::BackNForth)
	{
		if (direction == 1 && currentIndex + 1 == PatrolComponent->PathPoints.Num() || direction == -1 && currentIndex == 0)
		{
			direction *= -1;
		}
		currentIndex += direction;
		PatrolComponent->direction = direction;
	}
	PatrolComponent->SetCurrentIndex(currentIndex);
	return EBTNodeResult::Succeeded;
}
