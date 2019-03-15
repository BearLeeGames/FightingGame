// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingCamera.h"
#include "Engine/GameEngine.h"
#include "Camera/CameraComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
// Sets default values
AFightingCamera::AFightingCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFightingCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFightingCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// get both player locations
	FVector PlayerOneLoc = PlayerOne->GetActorLocation();
	FVector PlayerTwoLoc = PlayerTwo->GetActorLocation();

	// get camera location
	FVector CameraLoc = Camera->GetActorLocation();

	// set x to be the midpoint
	CameraLoc.Y = (PlayerOneLoc.Y + PlayerTwoLoc.Y) / 2;

	// set FieldOfView to be the difference + constant * multiplier
	// constant: how far before the camera STARTS zooming out (the higher, the later)
	// multiplier: how fast the camera zooms out
	float FieldOfView = FMath::Abs(PlayerTwoLoc.Y - PlayerOneLoc.Y - 30) * 0.05;

	// clamp the FieldOfView, setting a min and max
	// min: how close the camera starts, max: how far it is allowed to fully zoom out
	FieldOfView = FMath::Clamp(FieldOfView, 40.0f, 100.0f);

	// debugging purposes
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), FieldOfView));

	// get the camera component from camera actor inorder to set FieldOfView
	UCameraComponent* CamComp = Camera->GetCameraComponent();
	CamComp->SetFieldOfView(FieldOfView);

	// set the camera actor's new location
	Camera->SetActorLocation(CameraLoc);
}

