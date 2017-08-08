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
		//UE_LOG(LogTemp, Warning, TEXT("Direzione mirino: %s"), *OutHitLocation.ToString())
		// TODO Far mirare il tank controllato a questo punto
	}
}
//ottenere la posizione di dove punta il mirino, vero se colpisce il landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Trovare la direzione del mirino
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//"deprogettare" la posizione del mirino sullo schermo in una direzione del mondo
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Direzione mirino: %s"), *LookDirection.ToString())
	}
	
	//Line-trace su LookDirection, e vedere cosa colpisce
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; //da togliere
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}


