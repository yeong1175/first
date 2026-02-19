// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "InputActionValue.h"
#include "derivedBasePawn.generated.h"

/**
 * 
 */
UCLASS()
class TESTITHOMETRIC_API AderivedBasePawn : public ABasePawn
{
	GENERATED_BODY()
public:
	AderivedBasePawn();
	
private:
	UPROPERTY(VisibleAnywhere,Category="Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere,Category = "Components")
	class UCameraComponent* Camera;
	
protected:
	// 1. 입력 에셋을 담을 변수 (블루프린트에서 할당용)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	class UInputAction* MoveAction;

	// 2. 함수 매개변수를 FInputActionValue로 변경
	void Move(const FInputActionValue& Value);

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
