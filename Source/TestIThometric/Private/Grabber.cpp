// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();


	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{	
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UPhysicsHandleComponent* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr) {
		return;
	}
	FVector TargetLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
	PhysicsHandle->SetTargetLocationAndRotation(TargetLocation,GetComponentRotation());	
	
}	

void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Hit1"));

}

void UGrabber::Grab() {
	UPhysicsHandleComponent* PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr){
		return;
	}
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * DrawDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::White, false,5);
	DrawDebugSphere(GetWorld(), End, 10, 10, FColor::Blue, true);
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool Hashit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		Sphere
	);
	if (Hashit && HitResult.GetComponent() != nullptr)
	{
		UPrimitiveComponent* HitComponent = HitResult.GetComponent();

		// 1. 물리 시뮬레이션이 켜져 있는지 확인 (선택사항이지만 권장)
		HitComponent->WakeAllRigidBodies();

		// 2. 실제 잡기 실행
		PhysicsHandle->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			HitResult.ImpactPoint, // 실제 충격 지점
			HitComponent->GetComponentRotation() // 컴포넌트의 현재 회전값
		);

		UE_LOG(LogTemp, Warning, TEXT("Successfully Grabbed: %s"), *HitComponent->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Actor Hit"));
	}
}





