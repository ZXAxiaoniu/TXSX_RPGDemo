// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RPGDemoMenuPawn.generated.h"

class UCameraComponent;
class ACCVPMenuCameraLocation;

//�л��ӿڵ�ʱ��
#define CHANGE_VIEWPORT_TIME	10.f

//�����л�ǰ�����ӿ�ʼ�ƶ��ڱ���
#define MOVE_START_TIME_BEFORE_CHANGE_VIEWPORT	2.f

//�ƶ��ڱ����ʱ��
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
	//����-1˳��ʹ�ã����ǲ����ظ�֮ǰ���Ǹ���������ڵ���0��ָ������
	void SetNewLocation(int NewIndex);

private:
	TArray<LocationInfo> LocationList;

	//�����л��ӽǵ�ʱ�����
	float ChangeViewportTime = 0;
	//�ƶ��ڱ���ʱ�ļ�ʱ��
	float MoveShelterTime = 0;
	//�Ƿ������ƶ�Shelter
	bool bMovingShelter = false;

	//��ǰʹ�õ�λ�õ�����
	int NowLocationIndex = 0;

};
