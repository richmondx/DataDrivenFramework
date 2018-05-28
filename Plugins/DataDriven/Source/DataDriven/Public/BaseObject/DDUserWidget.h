// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DDBaseObject.h"
#include "DDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDUserWidget : public UUserWidget, public DDBaseObject
{
	GENERATED_BODY()
	
public:

	UDDUserWidget(const FObjectInitializer& ObjectInitializer);

	//构造函数与属性加载后调用,在这里将Object注册到框架
	virtual void PostLoad() override;

	//Widget的初始化函数
	virtual bool Initialize() override;

	
	
};
