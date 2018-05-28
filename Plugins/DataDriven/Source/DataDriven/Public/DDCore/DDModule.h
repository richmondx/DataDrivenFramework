// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Common/DDCommon.h"
#include "DDModule.generated.h"

class UDDManager;
class UDDModel;
class UDDMessage;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	//生命周期
	virtual void Init();
	virtual void Register();
	virtual void Active();
	virtual void Disable();
	virtual void UnRegister();
	virtual void Release();

	//迭代调动模组的反射方法
	virtual void IterCallFunction(UDDModule* Module, FString FunctionName, void* Param);
	
	
public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDManager> ManagerClass;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDModel> ModelClass;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDMessage> MessageClass;

	//管理器
	UDDManager* Manager;

protected:

	

protected:


		
	
};
