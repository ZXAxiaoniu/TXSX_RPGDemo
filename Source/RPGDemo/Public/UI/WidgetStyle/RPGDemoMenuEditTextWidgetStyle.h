// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "RPGDemoMenuEditTextWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct RPGDEMO_API FRPGDemoMenuEditTextStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FRPGDemoMenuEditTextStyle();
	virtual ~FRPGDemoMenuEditTextStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FRPGDemoMenuEditTextStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = "EditText")
		FEditableTextBoxStyle EditTextStyle;

	UPROPERTY(EditAnywhere, Category = "EditText")
		FLinearColor EditTextTextActiveColor;

	UPROPERTY(EditAnywhere, Category = "EditText")
		FLinearColor EditTextTextDeactiveColor;

	UPROPERTY(EditAnywhere, Category = "EditText")
		FSlateBrush EditTextBackgroundImage;

	UPROPERTY(EditAnywhere, Category = "Sound")
		FSlateSound OnMouseEnterSound;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class URPGDemoMenuEditTextWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FRPGDemoMenuEditTextStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
