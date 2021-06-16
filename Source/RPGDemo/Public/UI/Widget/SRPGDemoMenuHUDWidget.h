// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

#include "Class/RPGDemoTypes.h"

//切换菜单内容Box所需的时间
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
	//DPI缩放
	TAttribute<float> DPIScaler;
	
	//用于放置主要内容的Box
	TSharedPtr<SVerticalBox> ContentBox;
	
	//根据键值对，存储菜单ContentBox中的内容
	TMap<EMenuContentID::Type, TSharedPtr<SCompoundWidget>> WidgetContentMap;
	
	//存储当前的ContentID
	EMenuContentID::Type CurrentContentID = EMenuContentID::StartMenu;
	
	//切换界面时候使用的遮罩，负责阻断界面上的控件事件
	TSharedPtr<SImage> MaskImage;
	//切换界面动画计时器
	float AnimTimer;
	//切换界面时，临时保存下一个界面的ID
	EMenuContentID::Type NextWidgetID;
	
	//样式数据
	const FRPGDemoMenuSlateStyle * MenuStyle;

	//退出游戏委托
	FMenuHUDButtonDown OnQuitGameDelegate;
};
