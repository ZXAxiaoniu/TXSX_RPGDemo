// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SRPGDemoSEButton_V1.h"
#include "SlateOptMacros.h"

//
#include "Widgets/Images/SImage.h"

//
#include "Class/RPGDemoStyles.h"
#include "UI/WidgetStyle/RPGDemoBaseWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRPGDemoSEButton_V1::Construct(const FArguments& InArgs)
{
	MenuStyle = &RPGDemoStyles::Get().GetWidgetStyle<FRPGDemoBaseStyle>("RPGDemoButtonBaseWidgetStyle");

	OnClicked = InArgs._OnClicked;

	ChildSlot
	[
		SNew(SOverlay)
		//ÏÔÊ¾µÄÎÄ×Ö
		+ SOverlay::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin(0.f,0.f,5.f,0.f))
		[
			SAssignNew(TextBlock, STextBlock).Font(MenuStyle->Font_30).ColorAndOpacity(MenuStyle->MenuButtonTextDeactiveColor)
			.Text(InArgs._Text)
		]
	];

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


void SRPGDemoSEButton_V1::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	if (CurrentAnim != SEWidgetAnim::None)
	{
		switch(CurrentAnim)
		{
		case SEWidgetAnim::ToLeft:
			AnimPercent = FMath::Clamp<float>(AnimPercent + InDeltaTime * 1.f / ANIM_TIME, 0.f, 1.f);
			if (AnimPercent > 0.5f)
			{
				if (NowTextColorID == 0)
				{
					NowTextColorID = 1;
					TextBlock->SetColorAndOpacity(MenuStyle->MenuButtonTextActiveColor);
					TextBlock->SetMargin(FMargin(0.f, 0.f, 70.f, 0.f));
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
			AnimPercent = FMath::Clamp<float>(AnimPercent - InDeltaTime * 1.f / ANIM_TIME, 0.f, 1.f);
			if (AnimPercent < 0.5f)
			{
				if (NowTextColorID == 1)
				{
					NowTextColorID = 0;
					TextBlock->SetColorAndOpacity(MenuStyle->MenuButtonTextDeactiveColor);
					TextBlock->SetMargin(FMargin(0.f));
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


int32 SRPGDemoSEButton_V1::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	if (AnimPercent > 0.f)
	{
		FVector2D Size = AllottedGeometry.GetLocalSize();
		float Left = Size.X - AnimPercent * Size.X;
		Size.X = AnimPercent * Size.X;

		FSlateDrawElement::MakeBox(OutDrawElements, LayerId,
			AllottedGeometry.ToPaintGeometry(FVector2D(Left, 0.f), Size),
			&MenuStyle->ButtonBackgroundImage);
	}
	return LayerId;
}

void SRPGDemoSEButton_V1::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	CurrentAnim = SEWidgetAnim::ToLeft;
	FSlateApplication::Get().PlaySound(MenuStyle->OnMouseEnterSound);
}

void SRPGDemoSEButton_V1::OnMouseLeave(const FPointerEvent& MouseEvent)
{
	CurrentAnim = SEWidgetAnim::ToRight;
}

FReply SRPGDemoSEButton_V1::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	OnClicked.ExecuteIfBound();
	FSlateApplication::Get().PlaySound(MenuStyle->OnButtonDownSound);
	return FReply::Handled();
}
