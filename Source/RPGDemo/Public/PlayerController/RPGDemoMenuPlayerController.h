// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RPGDemoMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPGDEMO_API ARPGDemoMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ARPGDemoMenuPlayerController();

protected:
	virtual void BeginPlay() override;
};
