// Fill out your copyright notice in the Description page of Project Settings.

#include "DDOO.h"
#include "UObject/NoExportTypes.h"
#include "DDGameMode.h"
#include "DDModule.h"



void IDDOO::RegisterToModule(FString ModName, FString ObjectName /*= FString()*/, FString ClassName /*= FString()*/)
{
	//如果GameMode已经存在,说明已经注册过了,直接返回,避免重复存贮
	if (DDGameMode) return;
	//如果模组名为空,直接返回
	if (ModName.IsEmpty()) return;
	//注册类名和对象名
	if (!ObjectName.IsEmpty()) IObjectName = ObjectName;
	if (!ClassName.IsEmpty()) IClassName = ClassName;
	//获取UObject主体
	Body = Cast<UObject>(this);
	//获取GameMode
	DDGameMode = DDHelper::GetDDGameMode();
	//注册到模组
	if (DDGameMode)
	{
		//如果获得的ID为负直接返回
		ModuleIndex = DDHelper::GetEnumIndexFromString(DDGameMode->ModuleType, ModName);
		if (ModuleIndex < 0) {
			DDHelper::Debug(Body->GetName() + FString(" Get ") + ModName + FString(" ModuleID Failed !"), 120.f);
			return;
		}
		//如果注册不成功说明还没有实例化对应的Module
		if (!DDGameMode->RegisterToModule(this))
			DDHelper::Debug(Body->GetName() + FString(" Register To ") + ModName + FString(" Failed !"), 120.f);
	}
	else {
		DDHelper::Debug(Body->GetName() + FString(" Get DDGameMode Failed !"), 120.f);
	}
}


void IDDOO::AssignModule(UDDModule* Mod)
{
	Module = Mod;
}

UObject* IDDOO::GetObjectBody() const
{
	return Body;
}

int32 IDDOO::GetModuleIndex() const
{
	return ModuleIndex;
}

FString IDDOO::GetObjectName() const
{
	return IObjectName.IsEmpty() ? Body->GetName() : IObjectName;
}

FString IDDOO::GetClassName() const
{
	return IClassName;
}


bool IDDOO::ActiveLife()
{
	switch (LifeState)
	{
	case EBaseObjectLife::None:
		DDInit();
		LifeState = EBaseObjectLife::Init;
		break;
	case EBaseObjectLife::Init:
		DDLoading();
		LifeState = EBaseObjectLife::Loading;
		break;
	case EBaseObjectLife::Loading:
		DDRegister();
		LifeState = EBaseObjectLife::Register;
		break;
	case EBaseObjectLife::Register:
		DDEnable();
		LifeState = EBaseObjectLife::Enable;
		//设置运行状态为稳定
		RunState = EBaseObjectState::Stable;
		return true;
	}
	return false;
}

bool IDDOO::DestroyLife()
{
	switch (LifeState)
	{
	case EBaseObjectLife::Enable:
		DDDisable();
		LifeState = EBaseObjectLife::Disable;
		//设置运行状态为销毁
		RunState = EBaseObjectState::Destroy;
		break;
	case EBaseObjectLife::Disable:
		DDUnRegister();
		LifeState = EBaseObjectLife::UnRegister;
		break;
	case EBaseObjectLife::UnRegister:
		DDUnLoading();
		LifeState = EBaseObjectLife::UnLoading;
		return true;
	}
	return false;
}

void IDDOO::ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param)
{
	if (Agreement.ModuleIndex == ModuleIndex) {
		Module->ExecuteFunction(Agreement, Param);
	}
	else {
		DDGameMode->ExecuteFunction(Agreement, Param);
	}
}

void IDDOO::ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param)
{
	if (Agreement.ModuleIndex == ModuleIndex) {
		Module->ExecuteFunction(Agreement, Param);
	}
	else {
		DDGameMode->ExecuteFunction(Agreement, Param);
	}
}

void IDDOO::OnRealse()
{
	//运行DD框架的释放函数
	DDRelease();
}

void IDDOO::OnEnable()
{
	//一般运行一下DDEnable函数,可以重写
	DDEnable();
	//设置状态为激活状态
	LifeState = EBaseObjectLife::Enable;
}

void IDDOO::OnDisable()
{
	//一般运行一下DDDisable函数,可以重写
	DDDisable();
	//设置状态为失活状态
	LifeState = EBaseObjectLife::Disable;
}

void IDDOO::ObjectTick(float DeltaSeconds) {}

//生命周期系列函数
void IDDOO::DDInit() {}
void IDDOO::DDLoading() {}
void IDDOO::DDRegister() {}
void IDDOO::DDEnable() {}
void IDDOO::DDDisable() {}
void IDDOO::DDUnRegister() {}
void IDDOO::DDUnLoading() {}
void IDDOO::DDRelease() {}
