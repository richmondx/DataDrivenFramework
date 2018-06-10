// Fill out your copyright notice in the Description page of Project Settings.

#include "TKMenuHUD.h"

//#include "UserWidget.h"
#include "Public/UI/Widget/TKMenuWidget.h"



void ATKMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	UTKMenuWidget* MenuWidget = CreateWidget<UTKMenuWidget>(GetDDWorld(), MenuWidgetClass);
	MenuWidget->AddToViewport();
}

