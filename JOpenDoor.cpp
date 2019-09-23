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
	//得到所在的Actor  设置这个Actor的属性
	
}


// Called when the game starts
void UJOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Owner = GetOwner();
	DefaultPawn = GetWorld()->GetFirstPlayerController()->GetPawn();//得到默认角色控制器
}


// Called every frame    
void UJOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (TriggerVolume2!=nullptr && TriggerVolume2->IsOverlappingActor(DefaultPawn)) {//判段角色进入触发区域
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

