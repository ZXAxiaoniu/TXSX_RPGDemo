// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

class SRPGDemoSEEditTextBox;

DECLARE_DELEGATE_OneParam(FSEEditTextBoxGetText, FText&)
DECLARE_DELEGATE(FSEButtonOnClicked)

class RPGDEMO_API SRPGDemoEnterWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoEnterWidget)
	{}
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetUsernameDelegate);
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetPasswordDelegate);
	SLATE_EVENT(FSEButtonOnClicked, OnGoBackClicked);
	SLATE_EVENT(FSEButtonOnClicked, OnEnterClicked);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments & InArgs);

	void ClearText();

private:
	TSharedPtr<SRPGDemoSEEditTextBox> UsernameTextBlock;
	TSharedPtr<SRPGDemoSEEditTextBox> PasswordTextBlock;
};
