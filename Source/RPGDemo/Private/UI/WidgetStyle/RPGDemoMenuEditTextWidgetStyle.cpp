// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetStyle/RPGDemoMenuEditTextWidgetStyle.h"

FRPGDemoMenuEditTextStyle::FRPGDemoMenuEditTextStyle()
{
}

FRPGDemoMenuEditTextStyle::~FRPGDemoMenuEditTextStyle()
{
}

const FName FRPGDemoMenuEditTextStyle::TypeName(TEXT("FRPGDemoMenuEditTextStyle"));

const FRPGDemoMenuEditTextStyle& FRPGDemoMenuEditTextStyle::GetDefault()
{
	static FRPGDemoMenuEditTextStyle Default;
	return Default;
}

void FRPGDemoMenuEditTextStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

