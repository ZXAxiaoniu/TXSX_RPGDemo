// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGDemoCameraLocation.generated.h"

UCLASS()
class RPGDEMO_API ARPGDemoCameraLocation : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ARPGDemoCameraLocation();

public:
	UPROPERTY(EditAnywhere, Category = "Base")
		class UArrowComponent* ArrowComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
