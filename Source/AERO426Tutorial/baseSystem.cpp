// AERO 426 Workshop

#include "baseSystem.h"

// Sets default values
AbaseSystem::AbaseSystem()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootSceneComponent;
}

// Called when the game starts or when spawned
void AbaseSystem::BeginPlay()
{
	Super::BeginPlay();

	GetComponents<USolarPanel>(attached_panels);
	// Populates TArray with references (as pointers)
	// to all instances of USolarPanel currently attached
}

// Called every frame
void AbaseSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float power = calculate_components_power();

	if (GEngine) // NULL checking
		GEngine->AddOnScreenDebugMessage(-1, 15.0f,
			                             FColor::Yellow,
			                             FString::Printf(TEXT("Net Power: %f W"), power));
	    // Outputs power state to the screen
}

// Functions defined after here are completely user-defined and created

float AbaseSystem::calculate_components_power() // Sum the power input or 
                                                // output of all attached components
{
    // Solar Panels (only component for now)
	float solar_power = 0.0;
	for (auto& panel : attached_panels)
	{
		solar_power += panel->calculate_power();
		// Sums the power contribution of each solar panel
	}
	return solar_power;
}