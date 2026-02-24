// Fill out your copyright notice in the Description page of Project Settings.


#include "RangeDetector.h"

// Sets default values for this component's properties
URangeDetector::URangeDetector()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URangeDetector::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URangeDetector::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CheckDistanceToTarget(DeltaTime);
}


void URangeDetector::CheckDistanceToTarget(float DeltaTime)
{
	float DistanceToTarget = 0.0f;
	FVector targetLocation;
	FVector thisLocation = GetOwner()->GetActorLocation();							//this.transform.position

	APawn* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (PlayerPawn == nullptr) return;

	targetLocation = PlayerPawn->GetActorLocation();
	DistanceToTarget = FVector::Distance(thisLocation, targetLocation);			//Vector3.Distance(A, B)

	if (DistanceToTarget > DetectionRange) return;

	FVector DirectionToPlayer = (targetLocation - thisLocation).GetSafeNormal(); // .normalize w unity - kierunek
	FVector ForwardVector = GetOwner()->GetActorForwardVector();

	if (FVector::DotProduct(ForwardVector, DirectionToPlayer) <= 0.0f) return; // po³owa calego zasiêgu za plecami jest ignorowana

	FHitResult Result;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(GetOwner()); // zeby nie wykrywa³ uderzenia w samego siebie
			
	bool bHit = GetWorld()->LineTraceSingleByChannel(Result, thisLocation, targetLocation, ECC_Pawn, TraceParams);

	if (bHit && Result.GetActor() == PlayerPawn)
	{
		RotateToTarget(thisLocation, targetLocation, DeltaTime);
	}
}


void URangeDetector::RotateToTarget(FVector thisLocation, FVector targetLocation, float DeltaTime)
{
	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(thisLocation, targetLocation);
	FRotator CurrentRotation = GetOwner()->GetActorRotation();

	FRotator YLookRotation = FRotator(CurrentRotation.Pitch, TargetRotation.Yaw, CurrentRotation.Roll);

	FRotator SmoothRotation = FMath::RInterpTo(CurrentRotation, YLookRotation, DeltaTime, RotationSpeed); //InterpolateTo - bezpieczniejsza wersja Lerpa do obracania obiektami
	GetOwner()->SetActorRotation(SmoothRotation);
}
