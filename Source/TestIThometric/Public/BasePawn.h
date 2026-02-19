// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TESTITHOMETRIC_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	
	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceOnlyInt = 11;
	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt = 5;
	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyUnt = 3;
	UPROPERTY(EditInstanceOnly)
	int32 EditInstanceOnly = 11;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 PlayerLuck = 10;
	



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="xx",meta =(AllowPrivateAccess="true"))
	class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "xx", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "xx", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Turret;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "xx", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjecttileSpawnPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite,Category = "ZZ",meta = (AllowPrivateAccess = "true"))
	int32 VisibleAnywhereInt = 12;
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "EE",meta = (AllowPrivateAccess = "true"))
	int32 EditAnywhereInt = 22;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	

};
