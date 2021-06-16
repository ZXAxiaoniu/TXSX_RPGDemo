// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Widgets/SCompoundWidget.h"


DECLARE_DELEGATE(FSEButtonOnClicked)
DECLARE_DELEGATE_OneParam(FSEEditTextBoxGetText, FText&)
/**
 * 
 */
class SRPGDemoSEEditTextBox;

class RPGDEMO_API SRPGDemoRegisterWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoRegisterWidget)
	{}
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetUsernameDelegate);
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetPasswordDelegate);
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetPasswordConfirmDelegate);
	SLATE_EVENT(FSEButtonOnClicked, OnGoBackClicked);
	SLATE_EVENT(FSEButtonOnClicked, OnRegisterClicked);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	void ClearText();

private:
	TSharedPtr<SRPGDemoSEEditTextBox> UsernameTextBlock;
	TSharedPtr<SRPGDemoSEEditTextBox> PasswordTextBlock;
	TSharedPtr<SRPGDemoSEEditTextBox> PasswordConfirmTextBlock;
};
