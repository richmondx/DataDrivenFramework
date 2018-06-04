// Fill out your copyright notice in the Description page of Project Settings.

#include "DDModel.h"
#include "DDBaseObject.h"
#include "DDModule.h"



//void UDDModel::RegisterSuperModule(UDDModule* SuperMod)
//{
//	SuperModule = SuperMod;
//}
//
//void UDDModel::RegisterChildModule(UDDModule* ChildMod)
//{
//	//添加单个模组
//	ChildModule.Add(ChildMod->ModuleIndex, ChildMod);
//}

void UDDModel::RegisterObject(DDBaseObject* ObjectInst)
{
	//如果不重复就添加到模组对象
	if (!ObjectGroup.Contains(ObjectInst->GetObjectName()))
	{
		ObjectGroup.Add(ObjectInst->GetObjectName(), ObjectInst);
		//添加到模组类对象集
		FString ObejctClassName = ObjectInst->GetClassName();
		if (ObjectClassGroup.Contains(ObejctClassName))
		{
			ObjectClassGroup.Find(ObejctClassName)->Add(ObjectInst);
		}
		else {
			TArray<DDBaseObject*> ObejctArray;
			ObjectClassGroup.Add(ObejctClassName, ObejctArray);
			ObjectClassGroup.Find(ObejctClassName)->Add(ObjectInst);
		}
		//添加对象到生命周期组
		ObjectLifeGroup.Add(ObjectInst);
	}
	else {
		//如果有重复的就输出个Bug
		DDHelper::Debug(FString("Object Repeated --> ") + ObjectInst->GetObjectName(), 120.f);
	}
}

void UDDModel::ModelTick(float DeltaSeconds)
{
	//运行生命周期组的生命周期函数
	TArray<DDBaseObject*> TempObjectGroup;
	for (int i = 0; i < ObjectLifeGroup.Num(); ++i)
	{
		//如果激活成功
		if (ObjectLifeGroup[i]->ActiveLife()) {
			TempObjectGroup.Add(ObjectLifeGroup[i]);
		}
	}
	//将运行完生命周期的对象移出生命周期组,并且将运行Tick运行的对象添加到Tick组
	for (int i = 0; i < TempObjectGroup.Num(); ++i)
	{
		ObjectLifeGroup.Remove(TempObjectGroup[i]);
		if (TempObjectGroup[i]->IsAllowTickEvent)
		{
			ObjectTickGroup.Add(TempObjectGroup[i]);
		}
	}
	//运行Tick组的Tick函数
	for (int i = 0; i < ObjectTickGroup.Num(); ++i)
	{
		ObjectTickGroup[i]->ObjectTick(DeltaSeconds);
	}

}

void UDDModel::GetSelfObject(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	for (int i = 0; i < (*ObjectNameGroup).Num(); ++i)
	{
		if (ObjectGroup.Contains((*ObjectNameGroup)[i])) TargetObjectGroup.Add(*ObjectGroup.Find((*ObjectNameGroup)[i]));
	}
}

int32 UDDModel::GetOtherObject(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	//把对象组里与传入对象名组不相同的对象全部存到TargetObjectGroup
	for (TMap<FString, DDBaseObject*>::TIterator It(ObjectGroup); It; ++It) {
		bool IsSame = false;
		for (int i = 0; i < (*ObjectNameGroup).Num(); ++i)
		{
			//只要检查出相同的就马上跳出
			if ((*ObjectNameGroup)[i].Equals(It->Key)) { IsSame = true; break; }
		}
		if (!IsSame) TargetObjectGroup.Add(It->Value);
	}
	//返回全部对象的数量
	return GetObjectGroupNum();
}

int32 UDDModel::GetClassOtherObject(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	//现获取类名
	FString ObjectClassName = (*ObjectGroup.Find((*ObjectNameGroup)[0]))->GetClassName();
	//迭代类组对象
	for (TArray<DDBaseObject*>::TIterator It(*ObjectClassGroup.Find(ObjectClassName)); It; ++It)
	{
		bool IsSame = false;
		for (int i = 0; i < (*ObjectNameGroup).Num(); ++i)
		{
			//如果存储的对象相同就跳出
			if (*It == *ObjectGroup.Find((*ObjectNameGroup)[i])) { IsSame = true; break; }
		}
		if (!IsSame) TargetObjectGroup.Add(*It);
	}
	//返回这个类的对象数量
	return GetClassObjectGroupNum(ObjectClassName);
}

void UDDModel::GetSelfClass(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	for (int i = 0; i < (*ObjectNameGroup).Num(); ++i) {
		//如果不包含这个类,直接跳到下一个循环
		if (!ObjectClassGroup.Contains((*ObjectNameGroup)[i])) continue;
		//循环这个类去填入TargetObjectGroup
		for (TArray<DDBaseObject*>::TIterator It(*ObjectClassGroup.Find((*ObjectNameGroup)[i])); It; ++It)
		{
			TargetObjectGroup.Add(*It);
		}
	}
}

void UDDModel::GetOtherClass(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	for (TMap<FString, TArray<DDBaseObject*>>::TIterator It(ObjectClassGroup); It; ++It) {
		bool IsSame = false;
		for (int i = 0; i < (*ObjectNameGroup).Num(); ++i) {
			if ((*ObjectNameGroup)[i].Equals(It->Key)) { IsSame = true; break; }
		}
		//如果迭代到的这个类组与传入的类名相同,跳到下一个循环
		if (IsSame) continue;
		//如果迭代到的这个类组与传入的类名不相同,添加到TargetObjectGroup
		for (TArray<DDBaseObject*>::TIterator Ih(It->Value); Ih; ++Ih) {
			TargetObjectGroup.Add(*Ih);
		}
	}
}

int32 UDDModel::GetObjectGroupNum() const
{
	return ObjectGroup.Num();
}

int32 UDDModel::GetClassObjectGroupNum(FString ObjectClassName) const
{
	if (ObjectClassGroup.Contains(ObjectClassName)) return (*ObjectClassGroup.Find(ObjectClassName)).Num();
	return 0;
}

void UDDModel::RemoveObject(FString ObjectName)
{
	//如果没有这个对象,直接返回
	if (!ObjectGroup.Contains(ObjectName)) return;
	//先获取对象指针
	DDBaseObject* TargetObject = *ObjectGroup.Find(ObjectName);
	//从生命组移除对象
	ObjectLifeGroup.Remove(TargetObject);
	//从帧组移除对象
	ObjectTickGroup.Remove(TargetObject);
	//从类组移除对象
	ObjectClassGroup.Find(TargetObject->GetClassName())->Remove(TargetObject);
	//从对象组移除对象
	ObjectGroup.Remove(ObjectName);
}

void UDDModel::RemoveObjectClass(FString ObjectClassName)
{
	//如果没有这个对象类,直接返回
	if (!ObjectClassGroup.Contains(ObjectClassName)) return;
	//获取类对象数组
	TArray<DDBaseObject*>* TargetClassGroup = ObjectClassGroup.Find(ObjectClassName);
	//迭代移除对象
	for (int i = 0; i < (*TargetClassGroup).Num(); ++i) {
		//从生命组与帧组移除对象
		ObjectLifeGroup.Remove((*TargetClassGroup)[i]);
		ObjectTickGroup.Remove((*TargetClassGroup)[i]);
		//从对象组移除对象
		ObjectGroup.Remove((*TargetClassGroup)[i]->GetObjectName());
	}
	//最后从类组移除
	ObjectClassGroup.Remove(ObjectClassName);
}
