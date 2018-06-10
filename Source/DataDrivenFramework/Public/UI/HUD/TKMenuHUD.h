// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDObject/DDHUD.h"
#include "TKMenuHUD.generated.h"

/**
 *
 */
UCLASS()
class DATADRIVENFRAMEWORK_API ATKMenuHUD : public ADDHUD
{
	GENERATED_BODY()

public:


public:

	UPROPERTY(EditAnywhere, Category = "Tank")
		TSubclassOf<class UTKMenuWidget> MenuWidgetClass;

protected:

	virtual void BeginPlay() override;
};
