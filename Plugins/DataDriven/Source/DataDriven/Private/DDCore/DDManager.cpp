// Fill out your copyright notice in the Description page of Project Settings.

#include "DDManager.h"
#include "DDMessage.h"
#include "DDModel.h"
#include "DDBaseObject.h"



UDDManager::UDDManager()
{
	//创建组件
	InitManagerComponent();
}

void UDDManager::ManagerBeginPlay()
{

}

void UDDManager::ManagerTick(float DeltaSeconds)
{
	//调用数据的Tick函数
	Model->ModelTick(DeltaSeconds);
}

void UDDManager::InitManagerComponent()
{
	//创建组件,子类需要重写
	Model = NewObject<UDDModel>();
	Message = NewObject<UDDMessage>();
}

void UDDManager::ExecuteObjectFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	switch (Agreement->AgreementType)
	{
	case EAgreementType::SelfObject:
		ExecuteSelfObject(Agreement, Param);
		break;
	case EAgreementType::OtherObject:
		ExecuteOtherObject(Agreement, Param);
		break;
	case EAgreementType::ClassOtherObject:
		ExecuteClassOtherObject(Agreement, Param);
		break;
	case EAgreementType::SelfClass:
		ExecuteSelfClass(Agreement, Param);
		break;
	case EAgreementType::OtherClass:
		ExecuteOtherClass(Agreement, Param);
		break;
	}
}

void UDDManager::DestroyObject(ECallResult& Result, EAgreementType Agreement, TArray<FString> ObjectNameGroup)
{
	Model->DestroyObject(Agreement, &ObjectNameGroup);
}

void UDDManager::RegisterObject(DDBaseObject* Object)
{
	//注册对象到数据组件
	Model->RegisterObject(Object);
}

void UDDManager::ExecuteSelfObject(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//定义存储目标对象的组
	TArray<DDBaseObject*> TargetObjectGroup;
	//从数据组件获取对象组
	Model->GetSelfObject(&Agreement->ObjectGroup, TargetObjectGroup);
	//循环调用事件
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//获取方法
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//执行方法
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//如果没有方法就设置调用结果为没有对应方法
			Param->Result = ECallResult::NoFunction;
		}
	}
	//如果获取的对象与传入的对象名数量不相等,这个优先级最高
	if (TargetObjectGroup.Num() != Agreement->ObjectGroup.Num()) Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//定义存储目标对象的组
	TArray<DDBaseObject*> TargetObjectGroup;
	//从数据组件获取对象组
	int32 TotalObjectNum = Model->GetOtherObject(&Agreement->ObjectGroup, TargetObjectGroup);
	//循环调用事件
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//获取方法
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//执行方法
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//如果没有方法就设置调用结果为没有对应方法
			Param->Result = ECallResult::NoFunction;
		}
	}
	//如果数量和不相同说明数据不匹配
	if (Agreement->ObjectGroup.Num() + TargetObjectGroup.Num() != TotalObjectNum)Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteClassOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//定义存储目标对象的组
	TArray<DDBaseObject*> TargetObjectGroup;
	//从数据组件获取对象组
	int32 TotalClassNum = Model->GetClassOtherObject(&Agreement->ObjectGroup, TargetObjectGroup);
	//循环调用事件
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//获取方法
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//执行方法
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//如果没有方法就设置调用结果为没有对应方法
			Param->Result = ECallResult::NoFunction;
		}
	}
	//如果数量和不相同说明数据不匹配
	if (Agreement->ObjectGroup.Num() + TargetObjectGroup.Num() != TotalClassNum)Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteSelfClass(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//定义存储目标对象的组
	TArray<DDBaseObject*> TargetObjectGroup;
	//从数据组件获取对象组
	Model->GetSelfClass(&Agreement->ObjectGroup, TargetObjectGroup);
	//循环调用事件
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//获取方法
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//执行方法
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//如果没有方法就设置调用结果为没有对应方法
			Param->Result = ECallResult::NoFunction;
		}
	}
	//如果数量为0
	if (TargetObjectGroup.Num() == 0) Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteOtherClass(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//定义存储目标对象的组
	TArray<DDBaseObject*> TargetObjectGroup;
	//从数据组件获取对象组
	Model->GetOtherClass(&Agreement->ObjectGroup, TargetObjectGroup);
	//循环调用事件
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//获取方法
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//执行方法
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//如果没有方法就设置调用结果为没有对应方法
			Param->Result = ECallResult::NoFunction;
		}
	}
	//如果数量为0
	if (TargetObjectGroup.Num() == 0) Param->Result = ECallResult::LackObject;
}

//void UDDManager::RegisterSuperModule(UDDModule* SuperMod)
//{
//	//注册父模组到数据层
//	Model->RegisterSuperModule(SuperMod);
//}
//
//void UDDManager::RegisterChildModule(UDDModule* ChildMod)
//{
//	//注册子类模组到数据层
//	Model->RegisterChildModule(ChildMod);
//}

template<typename ModelClass>
ModelClass* UDDManager::GetModel()
{
	ModelClass* Result = Cast<ModelClass>(Model);
	if (Result) return Result;
	return NULL;
}

template<typename MessageClass>
MessageClass* UDDManager::GetMessage()
{
	MessageClass* Result = Cast<MessageClass>(Message);
	if (Result) return Result;
	return NULL;
}


