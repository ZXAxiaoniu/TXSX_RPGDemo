// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetStyle/RPGDemoMenuOptionsWidgetStyle.h"

FRPGDemoMenuOptionsStyle::FRPGDemoMenuOptionsStyle()
{
}

FRPGDemoMenuOptionsStyle::~FRPGDemoMenuOptionsStyle()
{
}

const FName FRPGDemoMenuOptionsStyle::TypeName(TEXT("FRPGDemoMenuOptionsStyle"));

const FRPGDemoMenuOptionsStyle& FRPGDemoMenuOptionsStyle::GetDefault()
{
	static FRPGDemoMenuOptionsStyle Default;
	return Default;
}

void FRPGDemoMenuOptionsStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

