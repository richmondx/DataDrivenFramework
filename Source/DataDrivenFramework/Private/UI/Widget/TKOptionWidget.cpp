// Fill out your copyright notice in the Description page of Project Settings.

#include "TKOptionWidget.h"




void UTKOptionWidget::ButtonEventOne()
{


	HUDInfoParam* Param = HUDInfo(int32(EMenuMapModule::HUD), "HUDInfo", "ButtonEventOne", 1);

	//DDHelper::Debug(DDHelper::GetEnumValueAsString<ECallResult>("ECallResult", Param->AsyResult), 5.f);

	DDHelper::Debug(FString("InfoCount --> ") + FString::FromInt(Param->InfoCount()), 5.f);

	delete Param;
}

void UTKOptionWidget::ButtonEventTwo()
{
	TArray<FString> InfoArr;
	InfoArr.Add("Info One");
	InfoArr.Add("Info Two");
	PCInfoParam* Param = PCInfo(int32(EMenuMapModule::Controller), EAgreementType::SelfObject, "MenuController", "PCInfo", InfoArr, 67);

	TArray<FString> RetArr = Param->MessInfo();
	FString EchoStr;
	for (int i = 0; i < RetArr.Num(); ++i) {
		EchoStr = EchoStr + RetArr[i] + FString(" -- ");
	}
	DDHelper::Debug(EchoStr);

	delete Param;
}

void UTKOptionWidget::ButtonEventThree()
{
	SingleInfoParam* Param = SingleInfo(int32(EMenuMapModule::HUD), "SingleInfo");
	delete Param;
}

void UTKOptionWidget::ButtonEventFour()
{
	HUDInfoParam* Param = HUDInfo(int32(EMenuMapModule::HUD), "HUDInfo", "ButtonEventFour", 4);
	delete Param;
}
