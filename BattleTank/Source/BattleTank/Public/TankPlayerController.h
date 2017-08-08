// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

virtual void BeginPlay() override;

virtual void Tick(float DeltaTime) override;

private:

ATank* GetControlledTank() const;

//Muove il barrel del tank in modo che segua la posizione del mirino
void AimTowardsCrosshair();

//Ritorna un OUT parameter, vero se colpisce il landscape
bool GetSightRayHitLocation(FVector& OutHitLocation) const;

UPROPERTY(EditAnywhere)
float CrossHairXLocation = 0.5;

UPROPERTY(EditAnywhere)
float CrossHairYLocation = 0.3333;

bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

};
