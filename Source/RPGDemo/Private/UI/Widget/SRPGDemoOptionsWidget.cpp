// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SRPGDemoOptionsWidget.h"
#include "SlateOptMacros.h"

//

//
#include "UI/WidgetStyle/RPGDemoMenuOptionsWidgetStyle.h"
#include "Class/RPGDemoStyles.h"
#include "UI/Widget/SRPGDemoSEButton_V1.h"
#include "Class/RPGDemoDataHandle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRPGDemoOptionsWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &RPGDemoStyles::Get().GetWidgetStyle<FRPGDemoMenuOptionsStyle>("RPGDemoMenuOptionsStyle");

	ChildSlot
	[
		// Populate the widget
		//出现CheckBox命中，点击有特效，但是无法Check的情况，可能是被Text挡住了
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().VAlign(VAlign_Center).HAlign(HAlign_Center)//.FillWidth(1.f)
			[
				SNew(SBox).WidthOverride(200.f).HeightOverride(200.f)
				[
					SAssignNew(EnCheckBox, SCheckBox).OnCheckStateChanged(this, &SRPGDemoOptionsWidget::EnCheckBoxStateChanged)
					.Style(&MenuStyle->CheckBoxStyle)
				]
			]
			+ SHorizontalBox::Slot().VAlign(VAlign_Center).HAlign(HAlign_Center)//.FillWidth(3.f)
			[
				SAssignNew(EnTextBlock, STextBlock).Font(MenuStyle->Font).Text(NSLOCTEXT("MyTest","English","English"))
				.ColorAndOpacity(FColor::White)
			]
			+ SHorizontalBox::Slot().VAlign(VAlign_Center).HAlign(HAlign_Center)//.FillWidth(1.f)
			[
				SNew(SBox).WidthOverride(100.f).HeightOverride(100.f)
				[
					SAssignNew(ZhCheckBox, SCheckBox).OnCheckStateChanged(this, &SRPGDemoOptionsWidget::ZhCheckBoxStateChanged)
					.Style(&MenuStyle->CheckBoxStyle)
				]
			]
			+ SHorizontalBox::Slot().VAlign(VAlign_Center).HAlign(HAlign_Center)//.FillWidth(3.f)
			[
				SAssignNew(ZhTextBlock, STextBlock).Font(MenuStyle->Font).Text(NSLOCTEXT("MyTest", "Chinese", "Chinese"))
				.ColorAndOpacity(FColor::White)
			]
		]
		+ SVerticalBox::Slot().AutoHeight().Padding(FMargin(0.f, 200.f, 0.f, 0.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Go Back", "Go Back")).OnClicked(InArgs._OnGoBackClicked)
			]
		]
	];

	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SRPGDemoOptionsWidget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);

	RPGDemoDataHandle::ChangeCulture(ECulture::En);
}

void SRPGDemoOptionsWidget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);

	RPGDemoDataHandle::ChangeCulture(ECulture::Zh);
}
