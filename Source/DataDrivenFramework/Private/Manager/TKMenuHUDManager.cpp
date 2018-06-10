// Fill out your copyright notice in the Description page of Project Settings.

#include "TKMenuHUDManager.h"



void UTKMenuHUDManager::HUDInfo(FString AcceptInfo, int32& InfoCount)
{
	DDHelper::Debug(AcceptInfo + FString::FromInt(InfoCount), 5.f);

	InfoCount = 100;
}

void UTKMenuHUDManager::SingleInfo()
{
	DDHelper::Debug(FString("SingleInfo"), 5.f);
}

