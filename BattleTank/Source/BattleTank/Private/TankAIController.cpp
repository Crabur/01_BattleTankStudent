// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
	
		// TODO Move towards the player

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		ControlledTank->Fire(); // TODO don't fire every frame, i.e. limit fire rate
	}
}



