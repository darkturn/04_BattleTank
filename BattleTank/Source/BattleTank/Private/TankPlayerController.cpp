// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Il Player Controller non sta possedendo un tank"))
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Il Player Controller sta possedendo: %s"), *(ControlledTank->GetName()))
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector OutHitLocation; //OUT Parameter
	if (GetSightRayHitLocation(OutHitLocation)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Hai colpito:"), *OutHitLocation.ToString())
		// TODO Far mirare il tank controllato a questo punto
	}
}
//ottenere la posizione di dove punta il mirino, vero se colpisce il landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}



