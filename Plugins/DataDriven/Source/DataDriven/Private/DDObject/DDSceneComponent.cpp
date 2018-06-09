// Fill out your copyright notice in the Description page of Project Settings.

#include "DDSceneComponent.h"


// Sets default values for this component's properties
UDDSceneComponent::UDDSceneComponent()
{
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UDDSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	//×Ô¶¯×¢²á
	RegisterToModule(ModuleName);
}




