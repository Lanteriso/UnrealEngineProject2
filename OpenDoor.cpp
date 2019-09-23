// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	DefaultPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	UE_LOG(LogTemp, Warning, TEXT("Hello %s am in OpenDoor!"), *Owner->GetName() );
}

void UOpenDoor::OpenDoor() {
	FRotator Rotator = FRotator(0, 90, 0);
	Owner->SetActorRotation(Rotator);
	//OnOpen.Broadcast();
}
void UOpenDoor::CloseDoor() {
	FRotator Rotator = FRotator(0, 0, 0);
	Owner->SetActorRotation(Rotator);
}

float UOpenDoor::GetTotalMassInTrigger()
{
	TArray<AActor*> Actors;
	if (TriggerVolume == nullptr)return 0;
	TriggerVolume->GetOverlappingActors(OUT Actors);

	float TotalMass = 0;
	for (const auto& Actor : Actors) {
		TotalMass+= Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Mass is %f!"), TotalMass);
	return TotalMass;
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if (TriggerVolume!=nullptr && TriggerVolume->IsOverlappingActor(DefaultPawn)) {
	if(TriggerVolume && GetTotalMassInTrigger()>25){
		//OpenDoor();
		OnOpen.Broadcast();
		//LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else {
		OnClose.Broadcast();
	}
	
	//if(GetWorld()->GetTimeSeconds() - LastDoorOpenTime >DoorOpenDuration) {
	//	//CloseDoor();
	//	OnClose.Broadcast();
	//}
}

