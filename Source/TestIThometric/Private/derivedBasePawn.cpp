// Fill out your copyright notice in the Description page of Project Settings.


#include "derivedBasePawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
 
AderivedBasePawn::AderivedBasePawn()
{

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm -> SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

// 생성자 아래에 추가
void AderivedBasePawn::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
            UE_LOG(LogTemp, Warning, TEXT("IMC Registration Success!")); // 이게 떠야 합니다!
        }
        else {
            UE_LOG(LogTemp, Error, TEXT("Subsystem NOT Found!"));
        }
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Controller NOT Found! (Not Possessed)"));
    }
}

void AderivedBasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // 향상된 입력 컴포넌트로 캐스팅
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // 바인딩: IA_Move가 실행될 때 Move 함수를 호출해라
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AderivedBasePawn::Move);
    }
}

void AderivedBasePawn::Move(const FInputActionValue& Value)
{
    // 1. Vector2D로 값을 받습니다. (X: 좌우, Y: 앞뒤)
    FVector2D MovementVector = Value.Get<FVector2D>();

    // 2. 앞뒤 이동 (Y값 활용)
    if (MovementVector.Y != 0.f)
    {
        FVector Forward = GetActorForwardVector();
        AddActorLocalOffset(Forward * MovementVector.Y * 20.f);
    }

    // 3. 좌우 회전 (X값 활용)
    if (MovementVector.X != 0.f)
    {
        // 헬기나 전차처럼 회전시키고 싶을 때 (Yaw 회전)
        AddActorLocalRotation(FRotator(0.f, MovementVector.X * 2.f, 0.f));
    }

    // 로그 확인용
    UE_LOG(LogTemp, Warning, TEXT("Input X: %f, Y: %f"), MovementVector.X, MovementVector.Y);
}