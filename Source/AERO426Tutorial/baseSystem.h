// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "SolarPanel.h"

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "baseSystem.generated.h"

UCLASS()
class AERO426TUTORIAL_API AbaseSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AbaseSystem();

	float calculate_components_power();
	TArray<USolarPanel*> components;
	std::vector<USolarPanel *> attached_panels;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
