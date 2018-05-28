// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



class UObject;
class UDDModule;
/**
 * 
 */
class DATADRIVEN_API DDBaseObject
{

public:

	DDBaseObject();


	//这个函数会在资源PostInitProperties时调用,在编辑器内就添加到了模组
	void RegisterObject(UObject* SelfBody);
	
public:

	//保存自身UObject
	UObject* Body;

	


};
