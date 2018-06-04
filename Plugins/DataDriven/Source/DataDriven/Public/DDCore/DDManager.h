// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Common/DDCommon.h"
#include "DDManager.generated.h"

class UDDModule;
class DDBaseObject;
class UDDMessage;
class UDDModel;

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDManager : public UObject
{
	GENERATED_BODY()

public:

	UDDManager();

	//Manager的BeginPlay函数
	virtual void ManagerBeginPlay();

	//Manager的Tick函数
	virtual void ManagerTick(float DeltaSeconds);

	//添加对象
	void RegisterObject(DDBaseObject* Object);

	//执行单个对象方法
	void ExecuteSelfObject(FDDObjectAgreement* Agreement, FDDParam* Param);
	//执行其余对象方法
	void ExecuteOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param);
	//支持相同类的区域对象方法
	void ExecuteClassOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param);
	//执行类对象的方法
	void ExecuteSelfClass(FDDObjectAgreement* Agreement, FDDParam* Param);
	//执行其他类对象的方法
	void ExecuteOtherClass(FDDObjectAgreement* Agreement, FDDParam* Param);

	////注册父类模组
	//void RegisterSuperModule(UDDModule* SuperMod);

	////注册单个子类模组
	//void RegisterChildModule(UDDModule* ChildMod);

	//在这里面进行子组件的初始化,如果要自定义组件就重写这个函数
	virtual void InitManagerComponent();

	//执行对象方法
	void ExecuteObjectFunction(FDDObjectAgreement* Agreement, FDDParam* Param);

public:



protected:

	//模板获取组件,因为是父类转子类,可能会有问题,绝对不能设置错误的类
	template<typename ModelClass>
	ModelClass* GetModel();

	template<typename MessageClass>
	MessageClass* GetMessage();

protected:

	//保存数据指针
	UDDModel* Model;
	//保存消息指针
	UDDMessage* Message;


};



