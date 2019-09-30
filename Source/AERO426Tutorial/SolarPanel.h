// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "SolarPanel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (SatelliteComponent), meta = (BlueprintSpawnableComponent))
class AERO426TUTORIAL_API USolarPanel : public UPrimitiveComponent
{
	GENERATED_BODY()

	
	
public:

	USolarPanel();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PanelMesh;


};
