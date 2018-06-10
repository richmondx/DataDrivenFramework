// Fill out your copyright notice in the Description page of Project Settings.

#include "DDCommon.h"


UDDCommon* UDDCommon::DDInst = NULL;

UWorld* UDDCommon::DDWorld = NULL;

ADDGameMode* UDDCommon::DDGameMode = NULL;


UDDCommon* UDDCommon::Get()
{
	if(!DDInst) DDInst = Cast<UDDCommon>(GEngine->GameSingleton);
	return DDInst;
}

ADDGameMode* UDDCommon::GetDDGameMode()
{
	return DDGameMode;
}

UWorld* UDDCommon::GetDDWorld()
{
	return DDWorld;
}

void UDDCommon::SetDDWorld(UWorld* World)
{
	DDWorld = World;
}

void UDDCommon::SetDDGameMode(ADDGameMode* GameMode)
{
	DDGameMode = GameMode;
}

