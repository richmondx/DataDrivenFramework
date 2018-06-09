// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DDCommon/DDCommon.h"
#include "DDGameMode.generated.h"

class USceneComponent;
class UDDCenterModule;
class IDDOO;
/**
 * 
 */
UCLASS()
class DATADRIVEN_API ADDGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	ADDGameMode();

	virtual void PostInitializeComponents() override;

	virtual void Tick(float DeltaSeconds) override;

	//调动模组方法
	void ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param);
	//调用对象方法
	void ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param);

#if WITH_EDITOR
	//属性修改方法
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	//提供给资源们进行注册
	bool RegisterToModule(IDDOO* Object);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		UDDCenterModule* Center;

	//模组对应的枚举名字
	UPROPERTY(EditDefaultsOnly, Category = "DataDriven")
		FString ModuleType;

protected:

	virtual void BeginPlay() override;

protected:

	//是否已经运行BeginPlay函数
	bool IsBeginPlay;

};
