// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"

#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnOpenRequest OnOpenRequest;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.f;

	float LastDoorOpenTime;

	AActor* Owner = nullptr;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
