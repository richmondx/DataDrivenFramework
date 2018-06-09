// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "DDOO.h"
#include "DDPlayerCameraManager.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API ADDPlayerCameraManager : public APlayerCameraManager, public IDDOO
{
	GENERATED_BODY()
	
public:

	ADDPlayerCameraManager();

public:

	//ģ������,���Ϊ��,˵��Ҫ�ֶ�ָ��,��Ϊ�վ����Զ�ָ��
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ModuleName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};