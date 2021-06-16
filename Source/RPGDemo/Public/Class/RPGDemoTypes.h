// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

namespace SEWidgetAnim
{
	enum Type
	{
		None = 0,
		ToLeft,
		ToRight
	};
}


namespace EMenuContentID
{
	enum Type
	{
		None = 0,
		StartMenu,		//初始界面
		Enter,			//登录界面
		Register,		//注册界面
		Options			//选择界面
	};
}

namespace ECulture
{
	enum Type
	{
		En = 0,
		Zh,
	};
}