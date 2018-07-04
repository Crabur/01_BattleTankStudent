// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be last include

// Forward Declaration
class ATank;
class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public:

	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

	// Start the tank  moving the barrel towards the crosshair would hit where the crosshair is aiming
	void AimTowardCrosshair();
	
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	FVector HitLocation; // OUT parameter

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = (0.5f);

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = (0.333333f);
	
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;
	
	// Return hit for first visible body in range
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
