// Fill out your copyright notice in the Description page of Project Settings.

#include "DDModule.h"
#include "DDManager.h"
#include "DDBaseObject.h"


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
	////在模组自己内部的BeginPlay进行子类父类模组的注册
	//for (int i = 0; i < GetAttachChildren().Num(); ++i)
	//{
	//	if (Cast<UDDModule>(GetAttachChildren()[i]))
	//		Manager->RegisterChildModule(Cast<UDDModule>(GetAttachChildren()[i]));
	//}
	////注册父类
	//if (Cast<UDDModule>(GetAttachParent())) Manager->RegisterSuperModule(Cast<UDDModule>(GetAttachParent()));
	//在这里调用一次Manger的BeginPlay函数,可以确认模组已经加载,但是对象不一定已经加载
	Manager->ManagerBeginPlay();
}

void UDDModule::ModuleTick(float DeltaSeconds)
{
	//调用Manager的Tick函数
	Manager->ManagerTick(DeltaSeconds);
}


bool UDDModule::RegisterObject(DDBaseObject* Object)
{
	//如果这个Module的ID和物品的ID不相同,直接返回false
	if (Object->GetModuleIndex() != ModuleIndex) return false;
	//告诉管理器添加对象到数据
	Manager->RegisterObject(Object);
	//把自己注册到对象的模组
	Object->AssignModule(this);
	return true;
}

void UDDModule::CreateManager()
{
	//实例化管理器组件
	if (ManagerClass) Manager = NewObject<UDDManager>(this, ManagerClass);
}

void UDDModule::ChangeModuleType(FString ModuleType)
{
	ModuleIndex = DDHelper::GetEnumIndexFromString(ModuleType, GetName());

	if (ModuleIndex < 0) {
		DDHelper::Debug(FString("Generate Module Index Error --> ") + GetName(), 120.f);
	}
	/*else {
		DDHelper::Debug(GetName() + FString(" Generate Module Index As --> ") + FString::FromInt(ModuleIndex), 120.f);
	}*/
}

void UDDModule::ExecuteFunction(FDDModuleAgreement* Agreement, FDDParam* Param)
{
	//如果不是本地模组,直接返回
	if (Agreement->ModuleIndex != ModuleIndex) return;
	//调用Manager的UFunction
	UFunction* ExeFunc = Manager->FindFunction(FName(*Agreement->FunctionName));
	//如果方法存在就执行
	if (ExeFunc) {
		Manager->ProcessEvent(ExeFunc, Param);
	}
	else {
		//方法不存在就设置结果为NoModFunc
		Param->Result = ECallResult::NoFunction;
	}
}

void UDDModule::ExecuteFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//如果不是本地模组,直接返回
	if (Agreement->ModuleIndex != ModuleIndex) return;
	//直接执行Manger的执行对象方法
	Manager->ExecuteObjectFunction(Agreement, Param);
}

