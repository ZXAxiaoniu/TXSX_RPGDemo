// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "RPGDemoMenuOptionsWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct RPGDEMO_API FRPGDemoMenuOptionsStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FRPGDemoMenuOptionsStyle();
	virtual ~FRPGDemoMenuOptionsStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FRPGDemoMenuOptionsStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = "CheckBox")
		FCheckBoxStyle CheckBoxStyle;

	UPROPERTY(EditAnywhere, Category = "Font")
		FSlateFontInfo Font;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class URPGDemoMenuOptionsWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FRPGDemoMenuOptionsStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
