// Fill out your copyright notice in the Description page of Project Settings.

#include "baseSystem.h"

// Sets default values
AbaseSystem::AbaseSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootSceneComponent;
}

// Called when the game starts or when spawned
void AbaseSystem::BeginPlay()
{
	Super::BeginPlay();
	GetComponents<USolarPanel>(components);
	for (auto& comp : components)
	{
		AbaseSystem::attached_panels.push_back(comp); // Add solar panels to the components vector
	}
}

// Called every frame
void AbaseSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float power = calculate_components_power();
	// UE_LOG(LogTemp, Warning, TEXT("The current net power is: %f"), power);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Net Power: %f"), power));
}

float AbaseSystem::calculate_components_power()
{
    // Solar Panels
	float solar_power = 0.0;
	for (auto& comp : components)
	{
		solar_power += comp->calculate_power(); // Add solar panels to the components vector
	}
	return solar_power;
}