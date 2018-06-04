// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DDBaseObject.h"
#include "DDPawn.generated.h"

UCLASS()
class DATADRIVEN_API ADDPawn : public APawn, public DDBaseObject
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADDPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	
	
};
