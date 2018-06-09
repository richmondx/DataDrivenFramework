// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DDCommon/DDCommon.h"
#include "DDOO.generated.h"

class UDDModule;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDDOO : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DATADRIVEN_API IDDOO
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//设置对象名和类名,用于从外部注册,如果手动注册要重置类名就调用这个方法再调用RegisterToModule方法
	void RegisterName(FString ObjName, FString ClaName);

	//通过传入的ModName是否为空来判定是否自动注册
	void RegisterToModule(FString ModName);

	//从外部指定模组
	void AssignModule(UDDModule* Mod);

	//获取Obejct主体
	UObject* GetObjectBody() const;

	//获取模组Index
	int32 GetModuleIndex() const;

	//获取对象名字,允许重写,自己设定格式
	virtual FString GetObjectName() const;

	//获取类的名字
	virtual FString GetClassName() const;

	//DDOO的Tick函数
	virtual void ObjectTick(float DeltaSeconds);

	//激活生命周期,激活成功的时候返回true,停止调用
	bool ActiveLife();

	//销毁生命周期,销毁成功后返回true,并且从模组注销
	bool DestroyLife();

	//发布方法
	void ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param);
	//发布方法
	void ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param);
	//运行释放函数
	void OnRealse();

public:

	//是否允许帧运行,如果要允许帧运行需要在构造函数或者BeginPlay设置,在UE4里默认为false
	bool IsAllowTickEvent;

	//生命状态
	EBaseObjectLife LifeState;

	//运行状态
	EBaseObjectState RunState;

protected:

	//生命周期,由模组管理器调用
	virtual void DDInit();//初始化
	virtual void DDLoading();//加载绑定的资源
	virtual void DDRegister();//注册数据或者事件
	virtual void DDEnable();//激活对象
	virtual void DDDisable();//失活对象
	virtual void DDUnRegister();//注销数据或者事件
	virtual void DDUnLoading();//销毁绑定资源
	virtual void DDRelease();//释放自己

protected:

	//保存自身UObject
	UObject* Body;

	//保存对应的模组
	UDDModule* Module;

	//保存GameMode
	ADDGameMode* DDGameMode;

	//保存对应模组的Index
	int32 ModuleIndex;

	//物品的名字,如果不为空,获取物品名就返回这个,并且此物品在对应的Module唯一
		FString ObjectName;

	//类名,这个在初始化时一定要指定
		FString ClassName;
	
	
};
