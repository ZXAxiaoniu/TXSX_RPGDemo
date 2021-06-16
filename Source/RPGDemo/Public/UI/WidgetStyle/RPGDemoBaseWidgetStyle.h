// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "RPGDemoBaseWidgetStyle.generated.h"

/**
 * 
 */


 //这个Style主要用于UI界面按钮设置
USTRUCT()
struct RPGDEMO_API FRPGDemoBaseStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FRPGDemoBaseStyle();
	virtual ~FRPGDemoBaseStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FRPGDemoBaseStyle& GetDefault();

	
	UPROPERTY(EditAnywhere, Category = "ButtonBase")
		FLinearColor MenuButtonTextActiveColor;

	UPROPERTY(EditAnywhere, Category = "ButtonBase")
		FLinearColor MenuButtonTextDeactiveColor;

	UPROPERTY(EditAnywhere, Category = "ButtonBase")
		FSlateBrush ButtonBackgroundImage;

	UPROPERTY(EditAnywhere, Category = "ButtonSound")
		FSlateSound OnButtonDownSound;

	UPROPERTY(EditAnywhere, Category = "ButtonSound")
		FSlateSound OnMouseEnterSound;

	UPROPERTY(EditAnywhere, Category = "Font")
		FSlateFontInfo Font_16;

	UPROPERTY(EditAnywhere, Category = "Font")
		FSlateFontInfo Font_20;

	UPROPERTY(EditAnywhere, Category = "Font")
		FSlateFontInfo Font_30;

	UPROPERTY(EditAnywhere, Category = "Font")
		FSlateFontInfo Font_40;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class URPGDemoBaseWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FRPGDemoBaseStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
