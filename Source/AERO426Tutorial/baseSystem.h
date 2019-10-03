// AERO 426 Workshop

#pragma once

#include "SolarPanel.h" // USolarPanel
#include "Engine.h" // GEngine (used for screen text printing)

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "baseSystem.generated.h"

UCLASS()
class AERO426TUTORIAL_API AbaseSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	AbaseSystem(); // Default object constructor

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* RootSceneComponent;

	TArray<USolarPanel*> attached_panels; // TArray of references (pointers)
	                                      // to attached solar panel instances

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float calculate_components_power(); // Function to calculate the net power of the system

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
