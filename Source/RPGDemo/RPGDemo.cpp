// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGDemo.h"
#include "Modules/ModuleManager.h"

//
#include "Styling/SlateStyleRegistry.h"

//
#include "Class/RPGDemoStyles.h"


IMPLEMENT_PRIMARY_GAME_MODULE(FRPGDemoModule, RPGDemo, "RPGDemo" );

void FRPGDemoModule::StartupModule()
{
	//初始化样式
	FSlateStyleRegistry::UnRegisterSlateStyle(RPGDemoStyles::GetStyleSetName());
	RPGDemoStyles::Initialize();
}

void FRPGDemoModule::ShutdownModule()
{
	RPGDemoStyles::ShutDown();
}