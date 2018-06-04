// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Common/DDCommon.h"
#include "CoreMinimal.h"



class UObject;
class UDDModule;
/**
 *
 */
class DATADRIVEN_API DDBaseObject
{

public:

	//通过传入的ModName是否为空来判定是否自动注册
	void RegisterToModule(UObject* ObjectBody, FString ModName);

	//从外部指定模组
	void AssignModule(UDDModule* Mod);

	//获取Obejct主体
	UObject* GetObjectBody() const;

	//获取模组Index
	int32 GetModuleIndex() const;

	//获取对象名字
	FString GetObjectName() const;

	//获取类的名字
	FString GetClassName() const;

	//DDBaseObject的Tick函数
	virtual void ObjectTick(float DeltaSeconds);

	//激活生命周期,激活成功的时候返回true,停止调用
	bool ActiveLife();

	//销毁生命周期,销毁成功后返回true,并且从模组注销
	bool DestroyLife();

	//运行本地模组方法
	void ExecuteLocalFunction(FDDModuleAgreement* Agreement, FDDParam* Param);
	//运行本地对象方法
	void ExecuteLocalFunction(FDDObjectAgreement* Agreement, FDDParam* Param);
	//运行异地模组方法
	void ExecuteRemoteFunction(FDDModuleAgreement* Agreement, FDDParam* Param);
	//运行异地对象方法
	void ExecuteRemoteFunction(FDDObjectAgreement* Agreement, FDDParam* Param);

public:

	//是否允许帧运行,如果要允许帧运行需要在构造函数或者BeginPlay设置,在UE4里默认为false
	bool IsAllowTickEvent;

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

	//生命状态
	EBaseObjectLife LifeState;

};
