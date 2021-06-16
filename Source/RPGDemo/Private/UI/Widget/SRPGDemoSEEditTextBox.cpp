// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SRPGDemoSEEditTextBox.h"
#include "SlateOptMacros.h"

//
#include "Widgets/Input/SEditableTextBox.h"

//
#include "Class/RPGDemoStyles.h"
#include "UI/WidgetStyle/RPGDemoMenuEditTextWidgetStyle.h"

const float SRPGDemoSEEditTextBox::AnimationContinueTime = 0.5f;

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRPGDemoSEEditTextBox::Construct(const FArguments& InArgs)
{
	MenuStyle = &RPGDemoStyles::Get().GetWidgetStyle<FRPGDemoMenuEditTextStyle>("RPGDemoMenuEditTextStyle");
	OnTextChangeDelegate.BindRaw(this, &SRPGDemoSEEditTextBox::OnEditTextBlockTextChange);

	//存储长度限制信息
	TextLengthLimit = InArgs._TextLengthLimit;
	//绑定获取Text的委托
	InArgs._BindGetText->BindRaw(this, &SRPGDemoSEEditTextBox::SEEditGetText);

	ChildSlot
	[
		// Populate the widget
		SAssignNew(TextBlock, SEditableTextBox).HintText(InArgs._HintText).Style(&MenuStyle->EditTextStyle)
		.Padding(FMargin(10.f)).OnTextChanged(OnTextChangeDelegate).IsPassword(InArgs._IsPassword)
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SRPGDemoSEEditTextBox::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	if (CurrentAnim != SEWidgetAnim::None)
	{
		switch (CurrentAnim)
		{
		case SEWidgetAnim::ToLeft:
			AnimPercent = FMath::Clamp<float>(AnimPercent + InDeltaTime * 1.f / AnimationContinueTime, 0.f, 1.f);
			if (AnimPercent > 0.5f)
			{
				if (NowTextColorID == 0)
				{
					NowTextColorID = 1;
					TextBlock->SetTextBoxForegroundColor(MenuStyle->EditTextTextActiveColor);
				}
				TextBlock->SetRenderOpacity(FMath::Clamp<float>((AnimPercent * 2.f) - 1.f, 0.f, 1.f));
			}
			else
			{
				TextBlock->SetRenderOpacity(FMath::Clamp<float>(1.f - (AnimPercent * 2.f), 0.f, 1.f));
			}

			if (AnimPercent >= 1.f)
			{
				CurrentAnim = SEWidgetAnim::None;
			}
			break;

		case SEWidgetAnim::ToRight:
			AnimPercent = FMath::Clamp<float>(AnimPercent - InDeltaTime * 1.f / AnimationContinueTime, 0.f, 1.f);
			if (AnimPercent < 0.5f)
			{
				if (NowTextColorID == 1)
				{
					NowTextColorID = 0;
					TextBlock->SetTextBoxForegroundColor(MenuStyle->EditTextTextDeactiveColor);
				}
				TextBlock->SetRenderOpacity(FMath::Clamp<float>(1.f - (AnimPercent * 2.f), 0.f, 1.f));
			}
			else
			{
				TextBlock->SetRenderOpacity(FMath::Clamp<float>((AnimPercent * 2.f) - 1.f, 0.f, 1.f));
			}
			if (AnimPercent <= 0.f)
			{
				CurrentAnim = SEWidgetAnim::None;
			}
			break;
		}
	}
}


int32 SRPGDemoSEEditTextBox::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	if (AnimPercent > 0.f)
	{
		FVector2D Size = AllottedGeometry.GetLocalSize();
		float top = Size.Y - AnimPercent * Size.Y;
		Size.Y = AnimPercent * Size.Y;

		FSlateDrawElement::MakeBox(OutDrawElements, LayerId,
			AllottedGeometry.ToPaintGeometry(FVector2D(0.f,top), Size),
			&MenuStyle->EditTextBackgroundImage);
	}
	return LayerId;
}

void SRPGDemoSEEditTextBox::ClearText()
{
	TextBlock->SetText(FText::FromString(""));
}

void SRPGDemoSEEditTextBox::SEEditGetText(FText& Text)
{
	Text = TextBlock->GetText();
}

void SRPGDemoSEEditTextBox::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	CurrentAnim = SEWidgetAnim::ToLeft;
	FSlateApplication::Get().PlaySound(MenuStyle->OnMouseEnterSound);
}

void SRPGDemoSEEditTextBox::OnEditTextBlockTextChange(const FText& Text)
{
	FString TextString = Text.ToString();
	FText ReplaceText = Text;
	if (TextString.Len() >= 1)
	{
		if (TextString.Len() > TextLengthLimit)
		{
			TextString.RemoveAt(TextLengthLimit, TextString.Len() - TextLengthLimit);
		}
		else
		{
			TCHAR CH = TextString[TextString.Len() - 1];
			if (!((CH >= 'a' && CH <= 'z') || (CH >= 'A' && CH <= 'Z') || (CH >= '0' && CH <= '9')))
			{
				TextString.RemoveAt(TextString.Len() - 1, 1);
			}
		}
		ReplaceText = FText::FromString(TextString);
	}
	TextBlock->SetText(ReplaceText);
}

void SRPGDemoSEEditTextBox::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	CurrentAnim = SEWidgetAnim::ToRight;
}

FReply SRPGDemoSEEditTextBox::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Handled();
}
