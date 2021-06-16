// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/RPGDemoMenuPlayerController.h"

ARPGDemoMenuPlayerController::ARPGDemoMenuPlayerController()
{
	bShowMouseCursor = true;
}

void ARPGDemoMenuPlayerController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
}