// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SRPGDemoRegisterWidget.h"
#include "SlateOptMacros.h"

//

//
#include "UI/Widget/SRPGDemoSEEditTextBox.h"
#include "UI/Widget/SRPGDemoSEButton_V1.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRPGDemoRegisterWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SAssignNew(UsernameTextBlock, SRPGDemoSEEditTextBox).HintText(NSLOCTEXT("MyText", "Username", "Username")).TextLengthLimit(20)
				.BindGetText(InArgs._BindGetUsernameDelegate)
			]
		]
		+ SVerticalBox::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SAssignNew(PasswordTextBlock,SRPGDemoSEEditTextBox).HintText(NSLOCTEXT("MyText", "Password", "Password")).TextLengthLimit(20)
				.IsPassword(true).BindGetText(InArgs._BindGetPasswordDelegate)
			]
		]
		+ SVerticalBox::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SAssignNew(PasswordConfirmTextBlock, SRPGDemoSEEditTextBox).HintText(NSLOCTEXT("MyText", "Password Confirm", "Password Confirm")).TextLengthLimit(20)
				.IsPassword(true).BindGetText(InArgs._BindGetPasswordConfirmDelegate)
			]
		]
		+ SVerticalBox::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Register", "Register"))
				.OnClicked(InArgs._OnRegisterClicked)
			]
		]
		+ SVerticalBox::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(0.f, 10.f, 0.f, 10.f))
		[
			SNew(SBox).WidthOverride(550.f).HeightOverride(85.f)
			[
				SNew(SRPGDemoSEButton_V1).Text(NSLOCTEXT("MyText", "Go Back", "Go Back"))
				.OnClicked(InArgs._OnGoBackClicked)
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SRPGDemoRegisterWidget::ClearText()
{
	UsernameTextBlock->ClearText();
	PasswordTextBlock->ClearText();
	PasswordConfirmTextBlock->ClearText();
}
