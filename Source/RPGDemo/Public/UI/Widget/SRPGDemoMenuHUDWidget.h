// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

#include "Class/RPGDemoTypes.h"

//�л��˵�����Box�����ʱ��
#define MENU_HUD_ANIM_CONTINUE_TIME	1.5f

struct FRPGDemoMenuSlateStyle;
class SEditableTextBox;

DECLARE_DELEGATE(FMenuHUDButtonDown)

class RPGDEMO_API SRPGDemoMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoMenuHUDWidget)
	{}
	SLATE_EVENT(FMenuHUDButtonDown, OnQuitGameDelegate)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */

	void Construct(const FArguments& InArgs);

protected:
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

private:
	float GetDPIScaler() const;

	FVector2D GetViewportSize() const;

	void InitializeChildWidgets();

	void StartChangeChildWidgetAnim(EMenuContentID::Type WidgetID);

	void ChangeChildWidget(EMenuContentID::Type WidgetID);

	void OnEnterClicked();

	void OnRegisterClicked();

	void OnOptionsClicked();

	void OnQuitGameClicked();

	void OnGoBackClicked();

private:
	//DPI����
	TAttribute<float> DPIScaler;
	
	//���ڷ�����Ҫ���ݵ�Box
	TSharedPtr<SVerticalBox> ContentBox;
	
	//���ݼ�ֵ�ԣ��洢�˵�ContentBox�е�����
	TMap<EMenuContentID::Type, TSharedPtr<SCompoundWidget>> WidgetContentMap;
	
	//�洢��ǰ��ContentID
	EMenuContentID::Type CurrentContentID = EMenuContentID::StartMenu;
	
	//�л�����ʱ��ʹ�õ����֣�������Ͻ����ϵĿؼ��¼�
	TSharedPtr<SImage> MaskImage;
	//�л����涯����ʱ��
	float AnimTimer;
	//�л�����ʱ����ʱ������һ�������ID
	EMenuContentID::Type NextWidgetID;
	
	//��ʽ����
	const FRPGDemoMenuSlateStyle * MenuStyle;

	//�˳���Ϸί��
	FMenuHUDButtonDown OnQuitGameDelegate;
};
