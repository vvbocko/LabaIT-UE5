// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "HasLineOfSight.generated.h"

/**
 * 
 */
UCLASS()
class LABAITPROJECT_API UHasLineOfSight : public UBTDecorator
{
	GENERATED_BODY()

public:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector KeySelector;
};
