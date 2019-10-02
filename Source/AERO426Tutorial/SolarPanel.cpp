// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarPanel.h"

USolarPanel::USolarPanel()
{

}

float USolarPanel::calculate_power()
{
	FVector pos = GetComponentLocation(); //Get Panel location
	FVector sun = FVector(0.0f, 0.0f, 1000.0f); // GetWorld()->
	FVector normal_vec = GetUpVector(); // Get Z-direction vector of panel (normal axis)
	FVector sun_2_panel = pos - sun; // Vector from sun to the panel
	FVector sun_2_panel_unit = sun_2_panel.GetSafeNormal(); // Normalize to unit vec

	float sunlight_angle_factor = FVector::DotProduct(sun_2_panel_unit, normal_vec);

	if (sunlight_angle_factor > 0.0) sunlight_angle_factor = 0; 
	      // zero out if sun is behind solar panel
	return (-sunlight_angle_factor*efficiency*area);
}