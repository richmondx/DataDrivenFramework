// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDCore/DDModule.h"
#include "DDCenterModule.generated.h"


/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDCenterModule : public UDDModule
{
	GENERATED_BODY()

public:

	UDDCenterModule();

	//virtual void InitializeComponent() override;

	//迭代调用本模组以及子模组的BeginPlay方法,不用反射
	virtual void IterModuleBeginPlay(UDDModule* Module);

	//迭代调用本模组以及子模组的Tick方法,不用反射
	virtual void IterModuleTick(UDDModule* Module, float DeltaSeconds);

	//迭代注册物品到模组
	virtual bool IterRegisterToModule(UDDModule* Module, DDBaseObject* Object);

	//迭代调用本模组以及子模组的EditChangeModuleType方法
	virtual void IterChangeModuleType(UDDModule* Module, FString ModType);

	//迭代实例化管理器组件
	virtual void IterCreateManager(UDDModule* Module);

	//迭代执行模组方法
	virtual void IterExecuteFunction(UDDModule* Module, FDDModuleAgreement* Agreement, FDDParam* Param);

	//迭代执行对象方法
	virtual void IterExecuteFunction(UDDModule* Module, FDDObjectAgreement* Agreement, FDDParam* Param);

public:

	
};
