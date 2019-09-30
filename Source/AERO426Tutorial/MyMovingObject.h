// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyMovingObject.generated.h"

UCLASS()
class AERO426TUTORIAL_API AMyMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyMovingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float RotationValue = 0;
	float ypos, ypos_scaled;

	UFUNCTION(BlueprintCallable)
	float RotateObject();

	float TranslateObject(float scale);

};
