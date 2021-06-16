// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/RPGDemoMenuHUD.h"

//
#include "SlateBasics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

//
#include "UI/Widget/SRPGDemoMenuHUDWidget.h"
#include "Class/RPGDemoDataHandle.h"
#include "Class/RPGDemoTypes.h"
#include "PlayerController/RPGDemoMenuPlayerController.h"


ARPGDemoMenuHUD::ARPGDemoMenuHUD()
{
	if (GEngine && GEngine->GameViewport)
	{
		FMenuHUDButtonDown Delegate;
		Delegate.BindUObject(this, &ARPGDemoMenuHUD::QuitGame);
		SAssignNew(MenuHUDWidget, SRPGDemoMenuHUDWidget).OnQuitGameDelegate(Delegate);
		//弱控件会对子控件增加一个弱指针
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
	}
}

void ARPGDemoMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	RPGDemoDataHandle::ChangeCulture(ECulture::Zh);
}

void ARPGDemoMenuHUD::QuitGame()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UKismetSystemLibrary::QuitGame(GetWorld(), PlayerController, EQuitPreference::Quit, false);
}
