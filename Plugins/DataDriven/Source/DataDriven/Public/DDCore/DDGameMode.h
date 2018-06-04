// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Common/DDCommon.h"
#include "DDGameMode.generated.h"

class USceneComponent;
class UDDCenterModule;
class DDBaseObject;
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
	void ExecuteFunction(FDDModuleAgreement* Agreement, FDDParam* Param);
	//调用对象方法
	void ExecuteFunction(FDDObjectAgreement* Agreement, FDDParam* Param);

#if WITH_EDITOR
	//属性修改方法
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	//提供给资源们进行注册
	bool RegisterToModule(DDBaseObject* Object);

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

};
