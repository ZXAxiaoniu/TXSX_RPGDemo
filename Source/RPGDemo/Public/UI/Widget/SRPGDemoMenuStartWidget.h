// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

DECLARE_DELEGATE(FSEButtonOnClicked)

class RPGDEMO_API SRPGDemoMenuStartWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoMenuStartWidget)
	{}

	SLATE_EVENT(FSEButtonOnClicked, OnEnterClicked);
	SLATE_EVENT(FSEButtonOnClicked, OnRegisterClicked);
	SLATE_EVENT(FSEButtonOnClicked, OnOptionsClicked);
	SLATE_EVENT(FSEButtonOnClicked, OnQuitGameClicked);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
