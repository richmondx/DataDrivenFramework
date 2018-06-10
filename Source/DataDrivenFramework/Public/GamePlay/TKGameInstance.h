// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDObject/DDGameInstance.h"
#include "TKGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVENFRAMEWORK_API UTKGameInstance : public UDDGameInstance
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
		void GIInfo(FString Info);

	
};
