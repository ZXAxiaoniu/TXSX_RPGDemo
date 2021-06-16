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

	SLATE_ARGUMENT(int32, TextLengthLimit);		//���룬���Ƴ���
	SLATE_ARGUMENT(FSEEditTextBoxGetText*, BindGetText);
	SLATE_ATTRIBUTE(FText, HintText);
	SLATE_ATTRIBUTE(bool, IsPassword);	//���룬�Ƿ�������

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments & InArgs);

	virtual void Tick(const FGeometry & AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	virtual int32 OnPaint(const FPaintArgs & Args, const FGeometry & AllottedGeometry, const FSlateRect & MyCullingRect, FSlateWindowElementList & OutDrawElements, int32 LayerId, const FWidgetStyle & InWidgetStyle, bool bParentEnabled) const override;

	void ClearText();

private:
	//����������������Ի�ȡTextBlock��Text�������Text��
	void SEEditGetText(FText& Text);
	//�󶨵�TextBlock��OnTextChanged�ϣ������������볤�ȣ������������ݵ�
	void OnEditTextBlockTextChange(const FText& Text);

	virtual void OnMouseEnter(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;

	virtual void OnMouseLeave(const FPointerEvent & MouseEvent) override;

	virtual FReply OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;

private:
	const static float AnimationContinueTime;

	//��¼��ǰ���ŵĶ�������
	SEWidgetAnim::Type CurrentAnim = SEWidgetAnim::None;
	//��ǰ�����ٷֱ�
	float AnimPercent = 0.0f;
	//�����0���ʾ��ǰʹ�õ���δ����ʱ�����ɫ��1��ʾ����ʱ�����ɫ
	int NowTextColorID = 0;


	//��������
	TSharedPtr<class SEditableTextBox> TextBlock;
	//���ڰ󶨵�TextBlock��ί��
	FOnTextChanged OnTextChangeDelegate;
	//��������
	int32 TextLengthLimit;

	//��ʽ�ļ�
	const struct FRPGDemoMenuEditTextStyle* MenuStyle;
};
