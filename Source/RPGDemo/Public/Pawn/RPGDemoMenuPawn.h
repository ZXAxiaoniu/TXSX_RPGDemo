// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RPGDemoMenuPawn.generated.h"

class UCameraComponent;
class ACCVPMenuCameraLocation;

//切换视口的时间
#define CHANGE_VIEWPORT_TIME	10.f

//距离切换前几秒钟开始移动遮蔽物
#define MOVE_START_TIME_BEFORE_CHANGE_VIEWPORT	2.f

//移动遮蔽物的时间
#define MOVE_SHELTER_TIME	4.f


struct LocationInfo
{
	FVector Location;
	FRotator Rotator;
};



UCLASS()
class RPGDEMO_API ARPGDemoMenuPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARPGDemoMenuPawn();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
		void StartMoveShelter();

	UFUNCTION(BlueprintImplementableEvent)
		void MoveShelter(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent)
		void ResetShelter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UParticleSystemComponent* ParticleComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(BlueprintReadOnly)
		float MoveShelterAllTime = MOVE_SHELTER_TIME;

private:
	//传入-1顺序使用，但是不会重复之前的那个，传入大于等于0的指定生成
	void SetNewLocation(int NewIndex);

private:
	TArray<LocationInfo> LocationList;

	//用于切换视角的时间计数
	float ChangeViewportTime = 0;
	//移动遮蔽物时的计时器
	float MoveShelterTime = 0;
	//是否正在移动Shelter
	bool bMovingShelter = false;

	//当前使用的位置的索引
	int NowLocationIndex = 0;

};
