// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsule"));
	RootComponent = CapsuleComp;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoolMesh"));
	Mesh->SetupAttachment(CapsuleComp);
	Turret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	Turret -> SetupAttachment(Mesh);
	ProjecttileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projecttile"));
	ProjecttileSpawnPoint->SetupAttachment(Turret);

}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input

