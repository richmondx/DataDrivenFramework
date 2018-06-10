// Fill out your copyright notice in the Description page of Project Settings.

#include "DDUserWidget.h"



bool UDDUserWidget::Initialize()
{
	//这里一定要判断一下父类
	if (!Super::Initialize()) return false;

	//自动注册
	RegisterToModule(ModuleName, ObjectName, ClassName);

	return true;
}

void UDDUserWidget::DDRelease()
{
	//再检查一次从父类移除
	RemoveFromParent();
	//立马回收资源
	ConditionalBeginDestroy();
}
