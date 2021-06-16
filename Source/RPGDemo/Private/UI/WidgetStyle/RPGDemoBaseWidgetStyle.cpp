// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetStyle/RPGDemoBaseWidgetStyle.h"

FRPGDemoBaseStyle::FRPGDemoBaseStyle()
{
}

FRPGDemoBaseStyle::~FRPGDemoBaseStyle()
{
}

const FName FRPGDemoBaseStyle::TypeName(TEXT("FRPGDemoBaseStyle"));

const FRPGDemoBaseStyle& FRPGDemoBaseStyle::GetDefault()
{
	static FRPGDemoBaseStyle Default;
	return Default;
}

void FRPGDemoBaseStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

