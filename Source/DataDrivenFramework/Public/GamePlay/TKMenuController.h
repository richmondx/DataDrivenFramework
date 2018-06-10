// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDObject/DDPlayerController.h"
#include "TKMenuController.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVENFRAMEWORK_API ATKMenuController : public ADDPlayerController
{
	GENERATED_BODY()
	
public:

	ATKMenuController();

	virtual void DDInit() override;

	UFUNCTION()
		void PCInfo(TArray<FString>& MessInfo, int32 IsUsed);
};
