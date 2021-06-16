// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Class/RPGDemoTypes.h"
/**
 * 
 */
class RPGDEMO_API RPGDemoDataHandle
{
private:
	static ECulture::Type CurrCulture;

public:
	static void ChangeCulture(ECulture::Type NewCulture);

	static ECulture::Type GetCurrentCulture();
};
