// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDTypes.generated.h"

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDTypes : public UObject
{
	GENERATED_BODY()


};

//默认模组枚举
UENUM()
enum class EDefaultModule : uint8 {
	Center = 0,      //中央模组
	Resource,        //资源模组
	UI,              //UI模组
};




//通信协议,只用于对象通信
UENUM()
enum class EAgreementType : uint8 {
	SelfObject,        //给传入的对象通信
	OtherObject,       //给传入的对象之外的对象通信
	ClassOtherObject,  //给传入的对象的相同类的其他对象通信,调用这个方法要确保传过来的对象都是同一类的,如果不同类就多次通信
	SelfClass,         //给这个类的对象通信
	OtherClass         //给这个类之外的类通信
};

//调用结果,项目开发时请确保每次都能调用成功
UENUM()
enum class ECallResult : uint8
{
	NoModule = 0,     //如果什么都没有改变说明没有对应模组
	LackObject,  //缺失对象
	NoFunction,  //没有对应方法
	Succeed      //成功调用
};

//BaseObject生命周期
UENUM()
enum class EBaseObjectLife : uint8
{
	None = 0,//初始化的状态
	Init,
	Loading,
	Register,
	Enable,
	Disable,
	UnRegister,
	UnLoading
};

//BaseObject生命周期
UENUM()
enum class EBaseObjectState : uint8
{
	Active = 0, //激活进程
	Stable,     //稳定进程
	Destroy     //销毁进程
};

//消息通信机制
struct DDParam
{

public:
	
	//回调的结果
	ECallResult AsyResult;

	//参数指针
	void* ParamPtr;
};


struct DDModuleAgreement
{

public:
	//模组对象
	int32 ModuleIndex;
	//方法名
	FString FunctionName;
};



struct DDObjectAgreement
{

public:
	//模组对象
	int32 ModuleIndex;
	//协议类型
	EAgreementType AgreementType;
	//对象组
	TArray<FString> ObjectGroup;
	//方法名
	FString FunctionName;
};


//UCLASS()
//class DATADRIVEN_API UDDParameter : public UObject
//{
//	GENERATED_BODY()
//
//public:
//
//	FDDParam* Param;
//};


//USTRUCT()
//struct FDDModulePackage
//{
//	GENERATED_BODY()
//
//public:
//
//	UDDModuleAgreement* Agreement;
//
//	UDDParameter* Parameter;
//
//};
//
//USTRUCT()
//struct FDDObjectPackage
//{
//	GENERATED_BODY()
//
//public:
//
//	UDDObjectAgreement Agreement;
//
//	UDDParameter* Parameter;
//};