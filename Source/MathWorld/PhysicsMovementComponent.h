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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> ForceVectorArray;
	
	//FTransform Transform;
	UFUNCTION(BlueprintCallable)
	void AddForces();
};
