// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declaration

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Setup") 
	float AcceptanceRadius = 8000; // How close the AI tank can get to the player, in cm.

private:

	UFUNCTION()
	void OnPossessedTankDeath();


	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;
};
