// AERO 426 Workshop

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "SolarPanel.generated.h"


UCLASS(ClassGroup = (SystemComponent), meta = (BlueprintSpawnableComponent))
class AERO426TUTORIAL_API USolarPanel : public UPrimitiveComponent
{
	GENERATED_BODY()
	
public:

	USolarPanel();

	// Parameters
	UPROPERTY(EditAnywhere)
	float area = 1;

	UPROPERTY(EditAnywhere)
	float efficiency = 0.9;

	UPROPERTY(EditAnywhere)
	float energy_flux = 100; // W/m^2

	UFUNCTION()
	float calculate_power();
};
