// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FSlateStyleSet;

class RPGDEMO_API RPGDemoStyles
{
private:
	static TSharedPtr<FSlateStyleSet> StyleSetInstance;

	static TSharedRef<FSlateStyleSet> Create();

public:
	static void Initialize();

	static const ISlateStyle& Get();

	static void ShutDown();

	static FName GetStyleSetName();
};
