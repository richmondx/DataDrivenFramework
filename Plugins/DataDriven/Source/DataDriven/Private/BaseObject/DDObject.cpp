// Fill out your copyright notice in the Description page of Project Settings.

#include "DDObject.h"




UDDObject::UDDObject()
{

}

void UDDObject::PostLoad()
{
	Super::PostLoad();
	//将自己注册到框架
	RegisterObject((UObject*)this);
}
