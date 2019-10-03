// AERO 426 Workshop

#include "SolarPanel.h"

USolarPanel::USolarPanel() {}

float USolarPanel::calculate_power()
{
	FVector pos = GetComponentLocation(); //Get Panel location
	FVector sun = { 77800000.0, 0.0, 0.0 }; // Hardcoded sun position
	FVector normal_vec = GetUpVector(); // Get Z-direction vector of panel (normal axis)
	FVector sun_2_panel = pos - sun; // Vector from sun to the panel
	FVector sun_2_panel_unit = sun_2_panel.GetSafeNormal(); // Normalize to unit vec

	float sunlight_angle_factor = FVector::DotProduct(sun_2_panel_unit, normal_vec);

	if (sunlight_angle_factor > 0.0) // Sun facing back of solar panel
	{
		sunlight_angle_factor = 0;
	}
	
	return (-sunlight_angle_factor*energy_flux*efficiency*area);
}