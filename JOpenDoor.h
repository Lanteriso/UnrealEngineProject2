// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "JOpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALENGINEPROJECT2_API UJOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void JOpenDoor();
	void JCloseDoor();
private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* TriggerVolume2;
	AActor* Owner;
	AActor* DefaultPawn;//Ä¬ÈÏ½ÇÉ«¿ØÖÆÆ÷
};
