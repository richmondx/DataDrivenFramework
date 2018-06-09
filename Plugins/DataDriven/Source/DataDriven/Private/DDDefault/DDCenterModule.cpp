// Fill out your copyright notice in the Description page of Project Settings.

#include "DDCenterModule.h"




UDDCenterModule::UDDCenterModule() : Super()
{

}


void UDDCenterModule::IterPreModuleBeginPlay(UDDModule* Module)
{
	Module->PreModuleBeginPlay();
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterPreModuleBeginPlay(Cast<UDDModule>(Module->GetAttachChildren()[i]));
	}
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

bool UDDCenterModule::IterRegisterToModule(UDDModule* Module, IDDOO* Object)
{
	//如果注册成功,直接返回true
	if (Module->RegisterObject(Object)) return true;
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i) {
		if (Cast<UDDModule>(Module->GetAttachChildren()[i])) {
			if (IterRegisterToModule(Cast<UDDModule>(Module->GetAttachChildren()[i]), Object)) return true;
		}
	}
	return false;
}

void UDDCenterModule::IterChangeModuleType(UDDModule* Module, FString ModType)
{
	Module->ChangeModuleType(ModType);
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterChangeModuleType(Cast<UDDModule>(Module->GetAttachChildren()[i]), ModType);
	}
}

void UDDCenterModule::IterCreateManager(UDDModule* Module)
{
	Module->CreateManager();
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterCreateManager(Cast<UDDModule>(Module->GetAttachChildren()[i]));
	}
}

void UDDCenterModule::IterExecuteFunction(UDDModule* Module, DDModuleAgreement Agreement, DDParam* Param)
{
	Module->ExecuteFunction(Agreement, Param);
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterExecuteFunction(Cast<UDDModule>(Module->GetAttachChildren()[i]), Agreement, Param);
	}
}

void UDDCenterModule::IterExecuteFunction(UDDModule* Module, DDObjectAgreement Agreement, DDParam* Param)
{
	Module->ExecuteFunction(Agreement, Param);
	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i)
	{
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterExecuteFunction(Cast<UDDModule>(Module->GetAttachChildren()[i]), Agreement, Param);
	}
}
