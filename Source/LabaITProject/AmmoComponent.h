// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LABAITPROJECT_API UAmmoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAmmoComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	bool DecreaseAmmo();

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	void IncreaseAmmo();

	UFUNCTION(BlueprintPure, Category = "Ammo")
	bool IsOutOfAmmo() const;

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	int32 GetAmmo();

private:
	UPROPERTY(EditAnywhere, Category = "Ammo")
	int32 MaxAmmo = 10;

	UPROPERTY(EditAnywhere, Category = "Ammo")
	int32 CurrentAmmo = 10;
};