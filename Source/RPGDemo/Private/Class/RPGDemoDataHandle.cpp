// Fill out your copyright notice in the Description page of Project Settings.


#include "Class/RPGDemoDataHandle.h"

ECulture::Type RPGDemoDataHandle::CurrCulture = ECulture::Zh;

void RPGDemoDataHandle::ChangeCulture(ECulture::Type NewCulture)
{
	switch (NewCulture)
	{
		case ECulture::En:
			FInternationalization::Get().SetCurrentCulture(TEXT("en"));
			break;

		case ECulture::Zh:
			FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
	}
	CurrCulture = NewCulture;
}

ECulture::Type RPGDemoDataHandle::GetCurrentCulture()
{
	return CurrCulture;
}
