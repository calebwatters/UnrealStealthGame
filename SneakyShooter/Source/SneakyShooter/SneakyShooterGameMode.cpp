// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SneakyShooterGameMode.h"
#include "SneakyShooterHUD.h"
#include "SneakyShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASneakyShooterGameMode::ASneakyShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASneakyShooterHUD::StaticClass();
}

void ASneakyShooterGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn) 
	{
		InstigatorPawn->DisableInput(nullptr);
	}

	OnMissionCompleted(InstigatorPawn);
}