// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarPanel.h"

USolarPanel::USolarPanel()
{

}

float USolarPanel::calculate_power()
{
	FVector pos = GetComponentLocation();
	FVector sun = FVector(0.0f, 0.0f, 100.0f); // GetWorld()->
	FVector normal_vec = GetUpVector();

	float sunlight_angle_factor = FVector::DotProduct((pos - sun), normal_vec);

	if (sunlight_angle_factor > 0.0) sunlight_angle_factor = 0; 
	      // zero out if sun is behind solar panel
	return (100*sunlight_angle_factor*efficiency*area);
}