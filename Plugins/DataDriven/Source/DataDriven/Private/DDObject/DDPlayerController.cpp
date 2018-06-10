// Fill out your copyright notice in the Description page of Project Settings.

#include "DDPlayerController.h"



ADDPlayerController::ADDPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ADDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//×Ô¶¯×¢²á
	RegisterToModule(ModuleName, ObjectName, ClassName);
}
