// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DDBaseObject.h"
#include "DDCharacter.generated.h"

UCLASS()
class DATADRIVEN_API ADDCharacter : public ACharacter, public DDBaseObject
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADDCharacter();

	//构造函数与属性加载后调用,在这里将Object注册到框架
	virtual void PostLoad() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	
	
};
