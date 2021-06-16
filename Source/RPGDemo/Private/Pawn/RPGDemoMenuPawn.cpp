// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn/RPGDemoMenuPawn.h"

//
#include "EngineUtils.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"

//
#include "Actor/RPGDemoCameraLocation.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARPGDemoMenuPawn::ARPGDemoMenuPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> MyParticleSystem(TEXT("ParticleSystem'/Game/MyProjectContent/Res/Particle/P_LightTriangle.P_LightTriangle'"));
	ParticleComponent->SetTemplate(MyParticleSystem.Object);
	ParticleComponent->SetupAttachment(RootComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MyStaticMesh(TEXT("StaticMesh'/Game/MyProjectContent/Res/StaticMesh/SM_BlueLightPlant.SM_BlueLightPlant'"));
	StaticMeshComponent->SetStaticMesh(MyStaticMesh.Object);
	StaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARPGDemoMenuPawn::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		TActorIterator<ARPGDemoCameraLocation> LocaActorIter = TActorIterator<ARPGDemoCameraLocation>(GetWorld());
		for (; LocaActorIter; ++LocaActorIter)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Green, LocaActorIter->GetName());
			LocationInfo NewInfo = { LocaActorIter->GetActorLocation(), LocaActorIter->GetActorRotation() };
			LocationList.Add(NewInfo);
		}
	}
	SetNewLocation(0);
}

void ARPGDemoMenuPawn::SetNewLocation(int NewIndex)
{
	if (LocationList.Num() == 0) return;
	if (NewIndex != -1 && NewIndex < LocationList.Num())
		NowLocationIndex = NewIndex;
	else
	{
		if (LocationList.Num() > 1)
		{
			NowLocationIndex = NowLocationIndex + 1;
			if (NowLocationIndex == LocationList.Num())
				NowLocationIndex = 0;
		}
		else
			NowLocationIndex = 0;
	}
	SetActorLocation(LocationList[NowLocationIndex].Location);
	SetActorRotation(LocationList[NowLocationIndex].Rotator);
}

// Called every frame
void ARPGDemoMenuPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//更新时间
	ChangeViewportTime += DeltaTime;
	if (bMovingShelter)
	{
		MoveShelterTime -= DeltaTime;
		MoveShelter(DeltaTime);
	}

	//几秒切换一次视口位置
	if (ChangeViewportTime > CHANGE_VIEWPORT_TIME)
	{
		ChangeViewportTime = 0.f;
		SetNewLocation(-1);
	}

	//如果剩余时间少于阈值，则开启移动遮蔽物
	if (ChangeViewportTime > CHANGE_VIEWPORT_TIME - MOVE_START_TIME_BEFORE_CHANGE_VIEWPORT && bMovingShelter == false)
	{
		bMovingShelter = true;
		MoveShelterTime = MOVE_SHELTER_TIME;
		StartMoveShelter();
	}
	else if (bMovingShelter == true && MoveShelterTime <= 0.f)
	{
		bMovingShelter = false;
		MoveShelterTime = 0.f;
		ResetShelter();
	}
}

// Called to bind functionality to input
void ARPGDemoMenuPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

