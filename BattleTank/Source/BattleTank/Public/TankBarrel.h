// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 � la massima velocit� verso il basso, +1 verso l'alto
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; //valore sensato default

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0;
};
