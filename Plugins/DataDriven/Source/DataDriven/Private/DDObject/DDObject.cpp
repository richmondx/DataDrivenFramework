// Fill out your copyright notice in the Description page of Project Settings.

#include "DDObject.h"







void UDDObject::DDRelease()
{
	//立马回收资源
	ConditionalBeginDestroy();
}
