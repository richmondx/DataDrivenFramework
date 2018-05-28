// Fill out your copyright notice in the Description page of Project Settings.

#include "DDBaseObject.h"
#include "UObject/NoExportTypes.h"
#include "DDGameMode.h"
#include "Kismet/GameplayStatics.h"


DDBaseObject::DDBaseObject()
{
}


void DDBaseObject::RegisterObject(UObject* SelfBody)
{
	//获取自己的实例
	Body = SelfBody;
	//获取DDGameMode并且注册到DDGameMode的临时资源库
	Cast<ADDGameMode>(UGameplayStatics::GetGameMode(Body))->RegisterObject(this);
}

