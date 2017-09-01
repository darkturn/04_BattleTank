// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//setta un throttle da -1 a +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	//Massima forza di ogni track, in Newton
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; //Assumendo che il peso del tank sia 40 ton e 1g di accelerazione

private:
	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();
	
	void DriveTrack();

	float CurrentThrottle = 0;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
