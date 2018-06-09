// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDCommon/DDTypes.h"
#include "DDDefine.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDDefine : public UObject
{
	GENERATED_BODY()
	

};


#define DDFUNCTION(FuncName, ParamType1, ParamName1, ParamType2, ParamName2) \
	struct FuncName##Param : DDParam \
	{ \
		struct \
		{ \
			ParamType1 ParamName1; \
			ParamType2 ParamName2; \
		} Parameter; \
		ParamType1 ParamName1() { return Parameter.ParamName1; } \
		ParamType2 ParamName2() { return Parameter.ParamName2; } \
		FuncName##Param() { ParamPtr = &Parameter; } \
	};\
	FuncName##Param* FuncName(int32 ModuleIndex, FString FunctionName, ParamType1 ParamName1, ParamType2 ParamName2) \
	{ \
		DDModuleAgreement Agreement; \
		Agreement.ModuleIndex = ModuleIndex; \
		Agreement.FunctionName; \
		FuncName##Param* Param = new FuncName##Param(); \
		Param->Parameter.ParamName1 = ParamName1; \
		Param->Parameter.ParamName2 = ParamName2; \
		ExecuteFunction(Agreement, Param); \
		return Param; \
	}



