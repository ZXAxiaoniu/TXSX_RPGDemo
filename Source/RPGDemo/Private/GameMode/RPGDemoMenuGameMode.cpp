// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/RPGDemoMenuGameMode.h"

//


//
#include "Pawn/RPGDemoMenuPawn.h"
#include "PlayerController/RPGDemoMenuPlayerController.h"
#include "UI/HUD/RPGDemoMenuHUD.h"


ARPGDemoMenuGameMode::ARPGDemoMenuGameMode()
{
	DefaultPawnClass = ARPGDemoMenuPawn::StaticClass();
	HUDClass = ARPGDemoMenuHUD::StaticClass();
	PlayerControllerClass = ARPGDemoMenuPlayerController::StaticClass();
}