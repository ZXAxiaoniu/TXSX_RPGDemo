// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//

//
#include "Class/RPGDemoTypes.h"


#include "Widgets/SCompoundWidget.h"

/**
 * 
 */

DECLARE_DELEGATE(FSEButtonOnClicked)

//单向完成整个动画需要的时间
#define ANIM_TIME	0.7f

class SImage;

class RPGDEMO_API SRPGDemoSEButton_V1 : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoSEButton_V1)
	{}

	SLATE_ATTRIBUTE(FText, Text);
	SLATE_ATTRIBUTE(FSlateFontInfo, Font);
	SLATE_EVENT(FSEButtonOnClicked, OnClicked);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

private:
	TSharedPtr<STextBlock> TextBlock;

	//记录当前播放的动画类型
	SEWidgetAnim::Type CurrentAnim = SEWidgetAnim::None;
	//当前动画百分比
	float AnimPercent = 0.0f;
	//如果是0则表示当前使用的是未激活时候的颜色，1表示激活时候的颜色
	int NowTextColorID = 0;

	//获取Style
	const struct FRPGDemoBaseStyle* MenuStyle;

	//当被点击时执行的委托
	FSEButtonOnClicked OnClicked;
};
