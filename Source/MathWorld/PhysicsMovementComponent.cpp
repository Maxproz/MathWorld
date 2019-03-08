// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/UObjectIterator.h"

#include "Runtime/Engine/Public/DrawDebugHelpers.h"

class AActor;


// Sets default values for this component's properties
UPhysicsMovementComponent::UPhysicsMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	Mass = 1;
	// ...
}


// Called when the game starts
void UPhysicsMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	// CODE FOR SHOWTRAILS INITIALIZATION
	//forceVectorList = GetComponent<PhysicsEngine>().forceVectorList;

	//lineRenderer = gameObject.AddComponent<LineRenderer>();
	//lineRenderer.material = new Material(Shader.Find("Sprites/Default"));
	//lineRenderer.SetColors(Color.yellow, Color.yellow);
	//lineRenderer.SetWidth(0.2F, 0.2F);
	//lineRenderer.useWorldSpace = false;

}


// Called every frame
void UPhysicsMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AddForces();
	UpdateVelocity(DeltaTime);

	// We dont need the unbalanced force detected code anymore because we 
	// make changes to the velocity vector inside UpdateVelocityNow?
	
	AActor* OwningActor = GetOwner();
	// Update Position
	OwningActor->SetActorLocation(OwningActor->GetActorLocation() + (VelocityVector * DeltaTime));

	//if (NetForceVector == FVector::ZeroVector)
	//{
	//	// if there is no net force 
	//	// update position
	//
	//	//if (OwningActor)
	//	//{
	//	//	UE_LOG(LogTemp, Warning, TEXT("Found Owner"));

	//	//}
	//	//FTransform* OwningActorTransform = &(OwningActor->GetTransform());
	//	
	//	//if (OwningActor)
	//	//{
	//	//	//"MyCharacter's Location is %s"
	//	//	UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Location is %s"),
	//	//		*OwningActor->GetActorLocation().ToString());
	//	//}


	//}
	//else
	//{
	//	// if there is a net force 
	//	// log error for now
	//	UE_LOG(LogTemp, Warning, TEXT("Unbalanced Force Detected!!!"));

	//}

	if (ShowTrails)
	{
		//lineRenderer.enabled = true;
		NumberOfForces = ForceVectorArray.Num();
		//lineRenderer.SetVertexCount(NumberOfForces * 2);
		//int i = 0;
		AActor* OwningActor = GetOwner();
		for (FVector FrceVector : ForceVectorArray)
		{
			DrawDebugLine(
				GetWorld(),
				FVector(OwningActor->GetActorLocation()),// FVector::ZeroVector
				FVector(-FrceVector), // -ForceVector
				FColor(255, 255, 0),
				false, -1, 0,
				15
			);
			//lineRenderer.SetPosition(i, Vector3.zero);
			//lineRenderer.SetPosition(i + 1, );
			//i = i + 2;
		}
	}
	else
	{
		//lineRenderer.enabled = false;
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

void UPhysicsMovementComponent::UpdateVelocity(const float& DeltaTime)
{
	FVector AccelerationVector = NetForceVector / Mass;
	VelocityVector = VelocityVector + (AccelerationVector * DeltaTime);

}

