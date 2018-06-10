// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDObject/DDUserWidget.h"
#include "TKOptionWidget.generated.h"



/**
 *
 */
UCLASS()
class DATADRIVENFRAMEWORK_API UTKOptionWidget : public UDDUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Tank")
		void ButtonEventOne();

	UFUNCTION(BlueprintCallable, Category = "Tank")
		void ButtonEventTwo();

	UFUNCTION(BlueprintCallable, Category = "Tank")
		void ButtonEventThree();

	UFUNCTION(BlueprintCallable, Category = "Tank")
		void ButtonEventFour();

protected:

	DDMODFUNC_TWO(HUDInfo, FString, AcceptInfo, int32, InfoCount);

	DDOBJFUNC_TWO(PCInfo, TArray<FString>, MessInfo, int32, IsUsed);

	DDMODFUNC(SingleInfo);
};
