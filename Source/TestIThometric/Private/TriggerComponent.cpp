// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent() {
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Display, TEXT("Construct"));
}
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("TriggerisAlive"));
}

	// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) 
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* Actor = GetAcceptableActor();
	if (Actor != nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Unlocking"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Relocking"));
	}
	
}

AActor* UTriggerComponent::GetAcceptableActor()const {
	
	TArray<AActor*>Actors;
	GetOverlappingActors(Actors);
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag(AcceptableActorTag))
		{
			return Actor;
		}
	}
	return nullptr;

}