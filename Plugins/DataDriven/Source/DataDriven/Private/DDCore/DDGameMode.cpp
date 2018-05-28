// Fill out your copyright notice in the Description page of Project Settings.

#include "DDGameMode.h"
#include "Default/DDCenterModule.h"
#include "DDBaseObject.h"
#include "Components/SceneComponent.h"



ADDGameMode::ADDGameMode()
{
	//允许每帧运行
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	CenterModule = CreateDefaultSubobject<UDDCenterModule>(TEXT("CenterModule"));
	CenterModule->SetupAttachment(RootComponent);

}

void ADDGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	//初始化中央模组
	CenterModule->Register();

}

void ADDGameMode::BeginPlay()
{
	Super::BeginPlay();

	//调用中央模组的BeginPlay迭代
	CenterModule->IterModuleBeginPlay(CenterModule);
}

void ADDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//调用中央模组的Tick迭代
	CenterModule->IterModuleTick(CenterModule, DeltaSeconds);
}

void ADDGameMode::RegisterObject(DDBaseObject* Object)
{
	ObjectGroup.Push(Object);
}


