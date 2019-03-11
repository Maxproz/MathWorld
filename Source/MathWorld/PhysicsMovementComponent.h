// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsMovementComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MATHWORLD_API UPhysicsMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPhysicsMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Mass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector VelocityVector; // [m s^-1] // average veclocity this tick
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector NetForceVector; // N [kg m s^-2]
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FVector> ForceVectorArray;
	

	void UpdatePosition(const float& DeltaTime);

	UFUNCTION(BlueprintCallable)
	void AddForce(const FVector& InForceVector);

	// TODO: Move this code to another class?
	// DrawDebug Code class
	
public:
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
	//bool ShowTrails = true;
	////UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
	////TArray<FVector> forceVectorList;
	////private LineRenderer lineRenderer;
	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
	//int NumberOfForces;

	/*DrawDebugPoint(
	//in a non-Static class
	//Draw the Line!
	DrawDebugLine(
	GetWorld(),
	LinkStart,
	LinkEnd,
	FColor(255,0,0),
	false, -1, 0,
	12.333
	);
);*/

	
};
