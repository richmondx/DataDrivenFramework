// Fill out your copyright notice in the Description page of Project Settings.

#include "DDCenterModule.h"




UDDCenterModule::UDDCenterModule() : Super()
{

}

void UDDCenterModule::InitializeComponent()
{
	Super::InitializeComponent();

	//调用初始化函数
	Init();
}

void UDDCenterModule::IterModuleBeginPlay(UDDModule* Module)
{
	Module->ModuleBeginPlay();
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterModuleBeginPlay(Cast<UDDModule>(Module->GetAttachChildren()[i]));
	}
}

void UDDCenterModule::IterModuleTick(UDDModule* Module, float DeltaSeconds)
{
	Module->ModuleTick(DeltaSeconds);
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterModuleTick(Cast<UDDModule>(Module->GetAttachChildren()[i]), DeltaSeconds);
	}
}
