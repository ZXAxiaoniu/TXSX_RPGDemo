// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SRPGDemoMenuStartWidget.h"
#include "SlateOptMacros.h"

//
#include "Widgets/Layout/SDPIScaler.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SEditableTextBox.h"

//
#include "UI/WidgetStyle/RPGDemoMenuSlateWidgetStyle.h"
#include "Class/RPGDemoStyles.h"
#include "UI/Widget/SRPGDemoSEButton_V1.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRPGDemoMenuStartWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		// Populate the widget
		//µÇÂ¼
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Enter", "Enter")).OnClicked(InArgs._OnEnterClicked)
			]
		]
		//×¢²á
		+ SVerticalBox::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Register", "Register")).OnClicked(InArgs._OnRegisterClicked)
			]
		]
		//ÉèÖÃ
		+ SVerticalBox::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Options", "Options")).OnClicked(InArgs._OnOptionsClicked)
			]
		]
		//ÍË³ö
		+ SVerticalBox::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Quit Game ", "Quit Game")).OnClicked(InArgs._OnQuitGameClicked)
			]
		]
	];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
