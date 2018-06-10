// Fill out your copyright notice in the Description page of Project Settings.

#include "DDCharacter.h"

// Sets default values
ADDCharacter::ADDCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADDCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//×Ô¶¯×¢²á
	RegisterToModule(ModuleName, ObjectName, ClassName);
}


