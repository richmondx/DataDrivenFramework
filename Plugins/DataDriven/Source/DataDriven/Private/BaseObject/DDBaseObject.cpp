// Fill out your copyright notice in the Description page of Project Settings.

#include "DDBaseObject.h"
#include "UObject/NoExportTypes.h"
#include "DDGameMode.h"
#include "DDModule.h"
#include "Kismet/GameplayStatics.h"


void DDBaseObject::RegisterToModule(UObject* ObjectBody, FString ModName)
{
	//如果模组名为空,直接返回
	if (ModName.IsEmpty()) return;
	//获取UObject主体
	Body = Cast<UObject>(ObjectBody);
	//获取GameMode
	DDGameMode = DDHelper::DDGameMode;
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
		if (!DDHelper::GetDDGameMode()->RegisterToModule(this))
			DDHelper::Debug(Body->GetName() + FString(" Register To ") + ModName + FString(" Failed !"), 120.f);
	}
	else {
		DDHelper::Debug(Body->GetName() + FString(" Get DDGameMode Failed !"), 120.f);
	}
}


void DDBaseObject::AssignModule(UDDModule* Mod)
{
	Module = Mod;
}

UObject* DDBaseObject::GetObjectBody() const
{
	return Body;
}

int32 DDBaseObject::GetModuleIndex() const
{
	return ModuleIndex;
}

FString DDBaseObject::GetObjectName() const
{
	return Body->GetName();
}

FString DDBaseObject::GetClassName() const
{
	FString ObjectClassName;
	FString TempLeftStr;
	if (GetObjectName().Contains(FString("_")))
	{
		GetObjectName().Split(FString("-"), &ObjectClassName, &TempLeftStr);
		return ObjectClassName;
	}
	return GetObjectName();
}


bool DDBaseObject::ActiveLife()
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
		return true;
	}
	return false;
}

bool DDBaseObject::DestroyLife()
{
	switch (LifeState)
	{
	case EBaseObjectLife::Enable:
		DDDisable();
		LifeState = EBaseObjectLife::Disable;
		break;
	case EBaseObjectLife::Disable:
		DDUnRegister();
		LifeState = EBaseObjectLife::UnRegister;
		break;
	case EBaseObjectLife::UnRegister:
		DDUnLoading();
		LifeState = EBaseObjectLife::UnLoading;
		break;
	case EBaseObjectLife::UnLoading:
		DDRelease();
		LifeState = EBaseObjectLife::Release;
		return true;
	}
	return false;
}

void DDBaseObject::ExecuteLocalFunction(FDDModuleAgreement* Agreement, FDDParam* Param)
{
	Module->ExecuteFunction(Agreement, Param);
}

void DDBaseObject::ExecuteLocalFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	Module->ExecuteFunction(Agreement, Param);
}

void DDBaseObject::ExecuteRemoteFunction(FDDModuleAgreement* Agreement, FDDParam* Param)
{
	DDGameMode->ExecuteFunction(Agreement, Param);
}

void DDBaseObject::ExecuteRemoteFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	DDGameMode->ExecuteFunction(Agreement, Param);
}

void DDBaseObject::ObjectTick(float DeltaSeconds) {}

//生命周期系列函数
void DDBaseObject::DDInit() {}
void DDBaseObject::DDLoading() {}
void DDBaseObject::DDRegister() {}
void DDBaseObject::DDEnable() {}
void DDBaseObject::DDDisable() {}
void DDBaseObject::DDUnRegister() {}
void DDBaseObject::DDUnLoading() {}
void DDBaseObject::DDRelease() {}

