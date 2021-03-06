// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//forward declaration
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

virtual void BeginPlay() override;

void SetPawn(APawn * InPawn);

virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	
	UFUNCTION()
	void OnPossessedTankDeath();

private:
//Muove il barrel del tank in modo che segua la posizione del mirino
void AimTowardsCrosshair();

//Ritorna un OUT parameter, vero se colpisce il landscape
bool GetSightRayHitLocation(FVector& HitLocation) const;

UPROPERTY(EditDefaultsOnly)
float CrossHairXLocation = 0.5;

UPROPERTY(EditDefaultsOnly)
float CrossHairYLocation = 0.3333;

UPROPERTY(EditDefaultsOnly)
float LineTraceRange = 1000000;

bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
