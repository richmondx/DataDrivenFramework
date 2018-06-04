// Fill out your copyright notice in the Description page of Project Settings.

#include "DDPawn.h"


// Sets default values
ADDPawn::ADDPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADDPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADDPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADDPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

