// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "RPGDemoMenuHUD.generated.h"

/**
 * 
 */
class SRPGDemoMenuHUDWidget;

DECLARE_DELEGATE(FSEButtonOnClicked)

UCLASS()
class RPGDEMO_API ARPGDemoMenuHUD : public AHUD
{
	GENERATED_BODY()

	ARPGDemoMenuHUD();

	virtual void BeginPlay() override;

private:
	void QuitGame();

private:
	TSharedPtr<SRPGDemoMenuHUDWidget> MenuHUDWidget;
};
