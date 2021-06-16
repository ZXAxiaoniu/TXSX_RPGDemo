// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

//


//
#include "Class/RPGDemoTypes.h"


/**
 * 
 */
DECLARE_DELEGATE_OneParam(FSEEditTextBoxGetText, FText &)


class RPGDEMO_API SRPGDemoSEEditTextBox : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRPGDemoSEEditTextBox)
	{}

	SLATE_ARGUMENT(int32, TextLengthLimit);		//输入，限制长度
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetText);
	SLATE_ATTRIBUTE(FText, HintText);
	SLATE_ATTRIBUTE(bool, IsPassword);	//输入，是否是密码

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments & InArgs);

	virtual void Tick(const FGeometry & AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	virtual int32 OnPaint(const FPaintArgs & Args, const FGeometry & AllottedGeometry, const FSlateRect & MyCullingRect, FSlateWindowElementList & OutDrawElements, int32 LayerId, const FWidgetStyle & InWidgetStyle, bool bParentEnabled) const override;

	void ClearText();

private:
	//调用这个函数，可以获取TextBlock的Text到传入的Text上
	void SEEditGetText(FText& Text);
	//绑定到TextBlock的OnTextChanged上，用于限制输入长度，限制输入内容等
	void OnEditTextBlockTextChange(const FText& Text);

	virtual void OnMouseEnter(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;

	virtual void OnMouseLeave(const FPointerEvent & MouseEvent) override;

	virtual FReply OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;

private:
	const static float AnimationContinueTime;

	//记录当前播放的动画类型
	SEWidgetAnim::Type CurrentAnim = SEWidgetAnim::None;
	//当前动画百分比
	float AnimPercent = 0.0f;
	//如果是0则表示当前使用的是未激活时候的颜色，1表示激活时候的颜色
	int NowTextColorID = 0;


	//输入内容
	TSharedPtr<class SEditableTextBox> TextBlock;
	//用于绑定到TextBlock的委托
	FOnTextChanged OnTextChangeDelegate;
	//长度限制
	int32 TextLengthLimit;

	//样式文件
	const struct FRPGDemoMenuEditTextStyle* MenuStyle;
};
