// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SNEAKYSHOOTER_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private: 
//how far a head of the player can we reach in cm
float Reach = 500.f;

UPhysicsHandleComponent* PhysicsHandle = nullptr;
UInputComponent* InputComponent = nullptr;
//Ray-cast and grab in reach
void Grab();
void Release();
void FindPhysicsHandleComponent();
void SetupInputComponent();
const FHitResult GetFirstPhysicsBodyInReach();
//Return end of reach line
FVector GetReachLineEnd();
FVector GetReachLineStart();
};
