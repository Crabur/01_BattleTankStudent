// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"));
	}
	else
	{

		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player tank: %s"), *(PlayerTank->GetName()));

	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return	Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
