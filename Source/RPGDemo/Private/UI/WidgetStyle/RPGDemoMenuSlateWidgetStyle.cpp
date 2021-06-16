// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetStyle/RPGDemoMenuSlateWidgetStyle.h"

FRPGDemoMenuSlateStyle::FRPGDemoMenuSlateStyle()
{
}

FRPGDemoMenuSlateStyle::~FRPGDemoMenuSlateStyle()
{
}

const FName FRPGDemoMenuSlateStyle::TypeName(TEXT("FRPGDemoMenuSlateStyle"));

const FRPGDemoMenuSlateStyle& FRPGDemoMenuSlateStyle::GetDefault()
{
	static FRPGDemoMenuSlateStyle Default;
	return Default;
}

void FRPGDemoMenuSlateStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

