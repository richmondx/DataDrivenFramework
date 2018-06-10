// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDCore/DDManager.h"
#include "TKMenuHUDManager.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVENFRAMEWORK_API UTKMenuHUDManager : public UDDManager
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION()
		void HUDInfo(FString AcceptInfo, int32& InfoCount);

	UFUNCTION()
		void SingleInfo();
};
