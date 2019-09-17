// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SneakyShooterGameMode.generated.h"

UCLASS(minimalapi)
class ASneakyShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASneakyShooterGameMode();

	void CompleteMission(APawn* InstigatorPawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void OnMissionCompleted(APawn* InstigatorPawn);
};



