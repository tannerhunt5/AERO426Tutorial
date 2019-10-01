// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "SolarPanel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (SystemComponent), meta = (BlueprintSpawnableComponent))
class AERO426TUTORIAL_API USolarPanel : public UPrimitiveComponent
{
	GENERATED_BODY()
	
public:

	USolarPanel();

	// Parameters
	UPROPERTY(EditAnywhere)
	float efficiency = 0.9;

	UPROPERTY(EditAnywhere)
	float area = 4;

	UFUNCTION()
	float calculate_power();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PanelMesh;

};
