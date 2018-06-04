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

	Center = CreateDefaultSubobject<UDDCenterModule>(TEXT("Center"));
	Center->SetupAttachment(RootComponent);
}

void ADDGameMode::PostInitializeComponents()
{
	//先调用一次父类
	Super::PostInitializeComponents();
	//注册GameMode和世界到UDDCommon
	DDHelper::DDGameMode = this;
	//在游戏运行之前必须进行一次模组	ID的设定
	Center->IterChangeModuleType(Center, ModuleType);
	//创建Manager组件
	Center->IterCreateManager(Center);
}

void ADDGameMode::BeginPlay()
{
	Super::BeginPlay();

	//调用中央模组的BeginPlay迭代
	Center->IterModuleBeginPlay(Center);
}

void ADDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//调用中央模组的Tick迭代
	Center->IterModuleTick(Center, DeltaSeconds);
}


void ADDGameMode::ExecuteFunction(FDDModuleAgreement* Agreement, FDDParam* Param)
{
	Center->IterExecuteFunction(Center, Agreement, Param);
}

void ADDGameMode::ExecuteFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	Center->IterExecuteFunction(Center, Agreement, Param);
}

#if WITH_EDITOR
void ADDGameMode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property &&
		PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(ADDGameMode, ModuleType))
	{
		Center->IterChangeModuleType(Center, ModuleType);
	}
}
#endif

bool ADDGameMode::RegisterToModule(DDBaseObject* Object)
{
	//调用中央模组的迭代注册对象功能
	return Center->IterRegisterToModule(Center, Object);
}


