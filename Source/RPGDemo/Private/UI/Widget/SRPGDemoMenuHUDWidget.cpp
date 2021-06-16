// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SRPGDemoMenuHUDWidget.h"
#include "SlateOptMacros.h"

//
#include "Widgets/Layout/SDPIScaler.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SEditableTextBox.h"


//
#include "UI/WidgetStyle/RPGDemoMenuSlateWidgetStyle.h"
#include "Class/RPGDemoStyles.h"
#include "UI/Widget/SRPGDemoSEButton_V1.h"
#include "UI/Widget/SRPGDemoMenuStartWidget.h"
#include "UI/Widget/SRPGDemoOptionsWidget.h"
#include "UI/Widget/SRPGDemoRegisterWidget.h"
#include "UI/Widget/SRPGDemoEnterWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRPGDemoMenuHUDWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &RPGDemoStyles::Get().GetWidgetStyle<FRPGDemoMenuSlateStyle>("RPGDemoMenuStartWidgetStyle");
	
	FSlateApplication::Get().PlaySound(MenuStyle->MenuBGM);

	OnQuitGameDelegate = InArgs._OnQuitGameDelegate;

	//绑定的函数需要是const类型的
	DPIScaler.Bind(this, &SRPGDemoMenuHUDWidget::GetDPIScaler);

	ChildSlot
	[
		SNew(SDPIScaler).DPIScale(DPIScaler)
		[
			SNew(SOverlay)
			//右侧用于显示内容的空间
			+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(1300.f,0.f,0.f,0.f))
			[
				SNew(SOverlay)
				//黑色半透明遮罩外加背景图片
				+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill)
				[
					SNew(SBorder).BorderImage(&MenuStyle->MenuBackground)
					.BorderBackgroundColor(FLinearColor(0.2f, 0.2f, 0.2f, 0.5f))	//BorderImage算是背景内容
				]
				//游戏logo图片
				+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(180.f, 60.f, 180.f, 780.f))
				[
					SNew(SImage).Image(&MenuStyle->GameIconImage)
				]
				//动态内容框
				+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin(50.f, 350.f, 50.f, 50.f))
				[
					SAssignNew(ContentBox, SVerticalBox)
				]
				//遮罩图片
				+ SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill)
				[
					SAssignNew(MaskImage, SImage).RenderOpacity(0.f)
				]
			]
		]
	];

	MaskImage->SetVisibility(EVisibility::Hidden);

	InitializeChildWidgets();

	StartChangeChildWidgetAnim(EMenuContentID::StartMenu);

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SRPGDemoMenuHUDWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	if (AnimTimer > 0.f)
	{
		AnimTimer -= InDeltaTime;
		float Percent = AnimTimer / MENU_HUD_ANIM_CONTINUE_TIME;
		if (Percent < 0.5f)
		{
			ChangeChildWidget(NextWidgetID);
		}
		//设置透明度
		if (AnimTimer <= 0.f)
		{
			ContentBox->SetRenderOpacity(1.f);
			MaskImage->SetVisibility(EVisibility::Hidden);
		}
		else
		{
			ContentBox->SetRenderOpacity(FMath::Clamp<float>(2.f * FMath::Abs(Percent - 0.5f), 0.f, 1.f));
		}
	}
}

float SRPGDemoMenuHUDWidget::GetDPIScaler() const 
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D SRPGDemoMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result;
}

void SRPGDemoMenuHUDWidget::InitializeChildWidgets()
{
	//初始化登录界面
	TSharedPtr<SRPGDemoEnterWidget> EnterWidget;
	SAssignNew(EnterWidget, SRPGDemoEnterWidget)
		.OnGoBackClicked(this, &SRPGDemoMenuHUDWidget::OnGoBackClicked)
		.OnEnterClicked(this, &SRPGDemoMenuHUDWidget::OnEnterWidgetEnterClicked)
		.BindGetUsernameDelegate(&GetEnterUsernameDelegate)
		.BindGetPasswordDelegate(&GetEnterPasswordDelegate);
	WidgetContentMap.Add(EMenuContentID::Enter, EnterWidget);

	//初始化注册界面
	TSharedPtr<SRPGDemoRegisterWidget> RegisterWidget;
	SAssignNew(RegisterWidget, SRPGDemoRegisterWidget)
		.OnGoBackClicked(this, &SRPGDemoMenuHUDWidget::OnGoBackClicked)
		.OnRegisterClicked(this, &SRPGDemoMenuHUDWidget::OnRegisterWidgetRegisterClicked)
		.BindGetUsernameDelegate(&GetRegisterUsernameDelegate)
		.BindGetPasswordDelegate(&GetRegisterPasswordDelegate)
		.BindGetPasswordConfirmDelegate(&GetRegisterPasswordConfirmDelegate);
	WidgetContentMap.Add(EMenuContentID::Register, RegisterWidget);

	//初始化设置菜单
	TSharedPtr<SRPGDemoOptionsWidget> OptionsWidget;
	SAssignNew(OptionsWidget, SRPGDemoOptionsWidget)
		.OnGoBackClicked(this, &SRPGDemoMenuHUDWidget::OnGoBackClicked);
	WidgetContentMap.Add(EMenuContentID::Options, OptionsWidget);

	//初始化初始菜单控件
	TSharedPtr<SRPGDemoMenuStartWidget> StartMenuWidget;
	SAssignNew(StartMenuWidget, SRPGDemoMenuStartWidget)
		.OnEnterClicked(this, &SRPGDemoMenuHUDWidget::OnEnterClicked)
		.OnRegisterClicked(this, &SRPGDemoMenuHUDWidget::OnRegisterClicked)
		.OnOptionsClicked(this, &SRPGDemoMenuHUDWidget::OnOptionsClicked)
		.OnQuitGameClicked(this, &SRPGDemoMenuHUDWidget::OnQuitGameClicked);
	WidgetContentMap.Add(EMenuContentID::StartMenu, StartMenuWidget);
}

void SRPGDemoMenuHUDWidget::StartChangeChildWidgetAnim(EMenuContentID::Type WidgetID)
{
	AnimTimer = MENU_HUD_ANIM_CONTINUE_TIME;
	MaskImage->SetVisibility(EVisibility::Visible);
	NextWidgetID = WidgetID;
}

void SRPGDemoMenuHUDWidget::ChangeChildWidget(EMenuContentID::Type WidgetID)
{
	//移除所有组件
	ContentBox->ClearChildren();
	//如果MenuType是None
	if (WidgetID == EMenuContentID::None) return;

	//如果是Enter还有Register，需要重置输入框
	if (WidgetID == EMenuContentID::Enter)
	{
		SRPGDemoEnterWidget* EnterWidget = StaticCast<SRPGDemoEnterWidget*>((*(WidgetContentMap.Find(WidgetID))).Get());
		EnterWidget->ClearText();
	}
	else if (WidgetID == EMenuContentID::Register)
	{
		SRPGDemoRegisterWidget * RegisterWidget = StaticCast<SRPGDemoRegisterWidget*>((*(WidgetContentMap.Find(WidgetID))).Get());
		RegisterWidget->ClearText();
	}

	ContentBox->AddSlot().AutoHeight()[(WidgetContentMap.Find(WidgetID))->ToSharedRef()];

	CurrentContentID = WidgetID;
}

void SRPGDemoMenuHUDWidget::OnEnterClicked()
{
	StartChangeChildWidgetAnim(EMenuContentID::Enter);
}

void SRPGDemoMenuHUDWidget::OnRegisterClicked()
{
	StartChangeChildWidgetAnim(EMenuContentID::Register);
}

void SRPGDemoMenuHUDWidget::OnOptionsClicked()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("Options"));
	StartChangeChildWidgetAnim(EMenuContentID::Options);
}

void SRPGDemoMenuHUDWidget::OnQuitGameClicked()
{
	OnQuitGameDelegate.ExecuteIfBound();
}

void SRPGDemoMenuHUDWidget::OnGoBackClicked()
{
	//可能以后会改，所以先保留着Switch，虽然看上去一行代码就行
	switch (CurrentContentID)
	{
	case EMenuContentID::Enter:
		StartChangeChildWidgetAnim(EMenuContentID::StartMenu);
		return;

	case EMenuContentID::Options:
		StartChangeChildWidgetAnim(EMenuContentID::StartMenu);
		return;

	case EMenuContentID::Register:
		StartChangeChildWidgetAnim(EMenuContentID::StartMenu);
		return;
	}
	StartChangeChildWidgetAnim(EMenuContentID::StartMenu);
}

void SRPGDemoMenuHUDWidget::OnRegisterWidgetRegisterClicked()
{
	FText Username;
	GetRegisterUsernameDelegate.ExecuteIfBound(Username);

	FText Password;
	GetRegisterPasswordDelegate.ExecuteIfBound(Password);

	FText PasswordConfirm;
	GetRegisterPasswordConfirmDelegate.ExecuteIfBound(PasswordConfirm);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("PasswordConfirm:  ") + PasswordConfirm.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("Password:  ") + Password.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("Username:  ") + Username.ToString());
}

void SRPGDemoMenuHUDWidget::OnEnterWidgetEnterClicked()
{
	FText Username;
	GetEnterUsernameDelegate.ExecuteIfBound(Username);

	FText Password;
	GetEnterPasswordDelegate.ExecuteIfBound(Password);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("Password:  ") + Password.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString("Username:  ") + Username.ToString());
}
