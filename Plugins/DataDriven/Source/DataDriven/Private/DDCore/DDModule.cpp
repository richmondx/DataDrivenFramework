// Fill out your copyright notice in the Description page of Project Settings.

#include "DDModule.h"
#include "DDManager.h"


// Sets default values for this component's properties
UDDModule::UDDModule()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//允许运行函数
	bWantsInitializeComponent = true;

}


void UDDModule::ModuleBeginPlay()
{

}

void UDDModule::ModuleTick(float DeltaSeconds)
{

}



void UDDModule::Init()
{
	//实例化管理器
	Manager = NewObject<UDDManager>(ManagerClass);

	Manager->MessageClass = MessageClass;
	Manager->ModelClass = ModelClass;
}

void UDDModule::Register()
{
	//实例化模型和消息组件
	Manager->Register();

}


void UDDModule::Active()
{
	Manager->Active();
}

void UDDModule::Disable()
{
	Manager->Disable();
}

void UDDModule::UnRegister()
{
	Manager->UnRegister();
}

void UDDModule::Release()
{
	Manager->Release();
}

void UDDModule::IterCallFunction(UDDModule* Module, FString FunctionName, void* Param)
{
	UFunction* ExeFunction = Module->FindFunction(FName(*FunctionName));
	if (ExeFunction) Module->ProcessEvent(ExeFunction, Param);

	for (int i = 0; i < Module->GetAttachChildren().Num(); ++i) {
		if (Cast<UDDModule>(Module->GetAttachChildren()[i]))
			IterCallFunction(Cast<UDDModule>(Module->GetAttachChildren()[i]), FunctionName, Param);
	}
}



