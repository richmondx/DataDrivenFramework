// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDManager.generated.h"


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
	
	//生命周期函数
	virtual void Register();
	virtual void Active();
	virtual void Disable();
	virtual void UnRegister();
	virtual void Release();


public:
	//信息模块的类
	TSubclassOf<UDDMessage> MessageClass;
	//数据模块的类
	TSubclassOf<UDDModel> ModelClass;


	//信息模块
	UDDMessage* Message;
	//数据模块
	UDDModel* Model;

};
