// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectIterator.h"

class AActor;


// Sets default values for this component's properties
UPhysicsMovementComponent::UPhysicsMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPhysicsMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPhysicsMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AddForces();

	if (NetForceVector == FVector::ZeroVector)
	{
		// if there is no net force 
		// update position
		AActor* OwningActor = GetOwner();
		//if (OwningActor)
		//{
		//	UE_LOG(LogTemp, Warning, TEXT("Found Owner"));

		//}
		//FTransform* OwningActorTransform = &(OwningActor->GetTransform());
		
		//if (OwningActor)
		//{
		//	//"MyCharacter's Location is %s"
		//	UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"),
		//		*OwningActor->GetActorLocation().ToString());
		//}

		OwningActor->SetActorLocation(OwningActor->GetActorLocation() + (VelocityVector * DeltaTime));
	}
	else
	{
		// if there is a net force 
		// log error for now
		UE_LOG(LogTemp, Warning, TEXT("Unbalanced Force Detected!!!"));

	}
}

void UPhysicsMovementComponent::AddForces()
{
	NetForceVector = FVector::ZeroVector;

	for (const FVector& ForceVector : ForceVectorArray)
	{
		//UE_LOG(LogTemp, Log, TEXT("Found UObject named: %s"), *CurrentObject->GetName());

		NetForceVector = NetForceVector + ForceVector;
	}


	
}

