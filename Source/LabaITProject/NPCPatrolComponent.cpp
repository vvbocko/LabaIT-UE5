// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCPatrolComponent.h"

// Sets default values for this component's properties
UNPCPatrolComponent::UNPCPatrolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UNPCPatrolComponent::BeginPlay()
{
	Super::BeginPlay();


	
}


// Called every frame
void UNPCPatrolComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UNPCPatrolComponent::SetCurrentIndex(int32 newIndex)
{
	currentIndex = newIndex;
}

EPatrolType UNPCPatrolComponent::GetPatrolType()
{
	return PatrolType;
}


FVector UNPCPatrolComponent::GetPathPointVector(AActor* PathPoint) const
{
	if (PathPoint)
	{
		return PathPoint->GetActorLocation();
	}
	return FVector::ZeroVector;
}
