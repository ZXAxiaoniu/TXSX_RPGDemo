// Fill out your copyright notice in the Description page of Project Settings.


#include "Class/RPGDemoStyles.h"

//
#include "Slate/SlateGameResources.h"
#include "Styling/SlateStyleRegistry.h"

//

TSharedPtr<FSlateStyleSet> RPGDemoStyles::StyleSetInstance = nullptr;


void RPGDemoStyles::Initialize()
{
	if (!StyleSetInstance.IsValid())
	{
		StyleSetInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleSetInstance);
	}
}

TSharedRef<FSlateStyleSet> RPGDemoStyles::Create()
{
	TSharedRef<FSlateStyleSet> StyleSetRef = FSlateGameResources::New(GetStyleSetName(), "/Game/MyProjectContent/UI/SlateStyle", "/Game/MyProjectContent/UI/SlateStyle"); 
	return StyleSetRef;
}

FName RPGDemoStyles::GetStyleSetName()
{
	static FName StyleSetName(TEXT("RPGDemoWidgetStyle"));
	return StyleSetName;
}

const ISlateStyle& RPGDemoStyles::Get()
{
	return *StyleSetInstance;
}

void RPGDemoStyles::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSetInstance);
	ensure(StyleSetInstance.IsUnique());
	StyleSetInstance.Reset();
}