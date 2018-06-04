// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Common/DDCommon.h"
#include "DDModule.generated.h"

class UDDManager;
class UDDModel;
class UDDMessage;
class DDBaseObject;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DATADRIVEN_API UDDModule : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDDModule();

	//Module的BeginPlay函数
	virtual void ModuleBeginPlay();

	//Module的Tick函数
	virtual void ModuleTick(float DeltaSeconds);

	bool RegisterObject(DDBaseObject* Object);

	void CreateManager();

	void ChangeModuleType(FString ModuleType);

	//调动模组方法
	void ExecuteFunction(FDDModuleAgreement* Agreement, FDDParam* Param);
	//调用对象方法
	void ExecuteFunction(FDDObjectAgreement* Agreement, FDDParam* Param);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDManager> ManagerClass;

	UPROPERTY(VisibleAnywhere, Category = "DataDriven")
		int32 ModuleIndex;

	//管理器
	UDDManager* Manager;

protected:



protected:




};


