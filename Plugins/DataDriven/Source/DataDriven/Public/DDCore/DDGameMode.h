// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
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

	//提供给资源们进行注册
	void RegisterObject(DDBaseObject* Object);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		UDDCenterModule* CenterModule;
	
	//临时保存所有资源
	TArray<DDBaseObject*> ObjectGroup;

protected:

	virtual void BeginPlay() override;

};
