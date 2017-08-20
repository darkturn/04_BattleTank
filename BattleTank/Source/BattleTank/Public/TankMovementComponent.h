// Copyright darkturn 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsabile per il movimento delle track
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMove(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurn(float Throw);

private:
	//preso dalla superclasse UNavMovementComponent
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
