// Fill out your copyright notice in the Description page of Project Settings.

#include "TKMenuHUD.h"
#include "Public/UI/Widget/TKMenuWidget.h"



void ATKMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	UTKMenuWidget* MenuWidget = CreateWidget<UTKMenuWidget>(DDHelper::GetDDWorld(), MenuWidgetClass);
	MenuWidget->AddToViewport();
}

