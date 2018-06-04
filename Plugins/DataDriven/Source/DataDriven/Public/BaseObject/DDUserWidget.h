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
	//UserWidget的构造函数重写方式
	//UDDUserWidget(const FObjectInitializer& ObjectInitializer);

	//Widget的初始化函数
	virtual bool Initialize() override;



};
