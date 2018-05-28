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

	virtual void InitializeComponent() override;

	//迭代调用本模组以及子模组的BeginPlay方法,不用反射
	virtual void IterModuleBeginPlay(UDDModule* Module);

	//迭代调用本模组以及子模组的Tick方法,不用反射
	virtual void IterModuleTick(UDDModule* Module, float DeltaSeconds);


};
