// Fill out your copyright notice in the Description page of Project Settings.

#include "DDGameMode.h"
#include "DDDefault/DDCenterModule.h"
#include "DDOO.h"
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
	//在游戏运行之前必须进行一次模组	ID的设定
	Center->IterChangeModuleType(Center, ModuleType);
	//创建Manager组件
	Center->IterCreateManager(Center);
}

void ADDGameMode::BeginPlay()
{
	Super::BeginPlay();

	//调用中央模组的BeginPlay迭代
	Center->IterPreModuleBeginPlay(Center);
	//注册GameInstance到框架
	RegisterGameInstance();
}

void ADDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!IsBeginPlay) {
		//调用中央模组的BeginPlay迭代
		Center->IterModuleBeginPlay(Center);
		//第一帧运行全体的BeginPlay函数
		IsBeginPlay = true;
	}
	else {
		//调用中央模组的Tick迭代
		Center->IterModuleTick(Center, DeltaSeconds);
	}
}


void ADDGameMode::ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param)
{
	Center->IterExecuteFunction(Center, Agreement, Param);
}

void ADDGameMode::ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param)
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

bool ADDGameMode::RegisterToModule(IDDOO* Object)
{
	//调用中央模组的迭代注册对象功能
	return Center->IterRegisterToModule(Center, Object);
}

void ADDGameMode::RegisterGameInstance()
{
	//获取GameInstance
	UGameInstance* GameInst = UGameplayStatics::GetGameInstance(GetWorld());
	//如果存在并且继承自IDDOO,就注册进Center,类名和对象名都是GameInstance
	if (GameInst && Cast<IDDOO>(GameInst))
		Cast<IDDOO>(GameInst)->RegisterToModule("Center", "GameInstacne", "GameInstacne");
}

