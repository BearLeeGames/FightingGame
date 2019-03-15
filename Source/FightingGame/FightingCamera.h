// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraActor.h"
#include "FightingCamera.generated.h"
UCLASS()
class FIGHTINGGAME_API AFightingCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFightingCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		AActor* PlayerOne;

	UPROPERTY(EditAnywhere)
		AActor* PlayerTwo;

	UPROPERTY(EditAnywhere)
		ACameraActor* Camera;
};
