// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
DECLARE_DELEGATE(FSEButtonOnClicked)

class RPGDEMO_API SRPGDemoOptionsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoOptionsWidget)
	{}
	SLATE_EVENT(FSEButtonOnClicked, OnGoBackClicked)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	void EnCheckBoxStateChanged(ECheckBoxState NewState);

	void ZhCheckBoxStateChanged(ECheckBoxState NewState);

private:
	const struct FRPGDemoMenuOptionsStyle* MenuStyle;

	//����CheckBox
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;

	//��CheckBox��Ӧ��TextBlock
	TSharedPtr<STextBlock> EnTextBlock;
	TSharedPtr<STextBlock> ZhTextBlock;

	//ί�е���
	FSEButtonOnClicked OnGoBackClicked;
};
