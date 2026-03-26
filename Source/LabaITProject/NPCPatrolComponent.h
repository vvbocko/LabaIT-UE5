// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NPCPatrolComponent.generated.h"

UENUM(BlueprintType)
enum class EPatrolType : uint8 // uint8 - WYMAGANE DLA ENUMÓW Z UPROPERTY (mówi ¿e enuum zajmnie ma³o pamiêci itp)
{
	Cyclic UMETA(DisplayName = "Cyclic"),
	BackNForth UMETA(DisplayName = "Back and Forth")
};

USTRUCT(BlueprintType)
struct FPatrolPointData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	AActor* PathPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	float WaitTime;

	FPatrolPointData()
	{
		PathPoint = nullptr;
		WaitTime = 0.0f;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABAITPROJECT_API UNPCPatrolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNPCPatrolComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	TArray<FPatrolPointData> PathPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	EPatrolType PatrolType;

	UFUNCTION(BlueprintCallable)
	FVector GetPathPointVector(AActor* PathPoint) const;

	UFUNCTION(BlueprintCallable)
	EPatrolType GetPatrolType();

	UFUNCTION(BlueprintCallable)
	void SetCurrentIndex(int32 newIndex);

	UPROPERTY(BlueprintReadWrite, Category = "Patrol")
	int32 currentIndex = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Patrol")
	int32 direction = 1;
};
