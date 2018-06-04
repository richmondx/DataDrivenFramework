// Fill out your copyright notice in the Description page of Project Settings.

#include "DDUserWidget.h"




//UDDUserWidget::UDDUserWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
//{
//
//}

bool UDDUserWidget::Initialize()
{
	//这里一定要判断一下父类
	if (!Super::Initialize()) return false;

	return true;
}
