// Fill out your copyright notice in the Description page of Project Settings.


#include "JOpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
// Sets default values for this component's properties
UJOpenDoor::UJOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	//�õ����ڵ�Actor  �������Actor������
	
}


// Called when the game starts
void UJOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Owner = GetOwner();
	DefaultPawn = GetWorld()->GetFirstPlayerController()->GetPawn();//�õ�Ĭ�Ͻ�ɫ������
}


// Called every frame    
void UJOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (TriggerVolume2!=nullptr && TriggerVolume2->IsOverlappingActor(DefaultPawn)) {//�жν�ɫ���봥������
		JOpenDoor();
		
		//LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else {
		JCloseDoor();
	}
}

void UJOpenDoor::JOpenDoor()
{
	//pitch=y yaw=z roll=x
	FRotator NewRotator = FRotator(0, 90, 0);
	Owner->SetActorRotation(NewRotator);
}

void UJOpenDoor::JCloseDoor()
{
	FRotator NewRotator = FRotator(0, 0, 0);
	Owner->SetActorRotation(NewRotator);
}

