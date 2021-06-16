// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "RPGDemoMenuSlateWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct RPGDEMO_API FRPGDemoMenuSlateStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FRPGDemoMenuSlateStyle();
	virtual ~FRPGDemoMenuSlateStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FRPGDemoMenuSlateStyle& GetDefault();


	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateBrush GameIconImage;

	UPROPERTY(EditAnywhere, Category = "Menu")
		FSlateBrush MenuBackground;

	UPROPERTY(EditAnywhere, Category = "Music")
		FSlateSound MenuBGM;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class URPGDemoMenuSlateWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FRPGDemoMenuSlateStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
