// Fill out your copyright notice in the Description page of Project Settings.

#include "MyMovingObject.h"

// Sets default values 
// constructor
AMyMovingObject::AMyMovingObject()
{
 	// Set this actor to call Tick() every frame.  
	//You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyMovingObject::BeginPlay()
{
	Super::BeginPlay();

	// initializing values to = 0 once the sim is started with the "play" button 
	ypos = 0;
	ypos_scaled = 0;
}

// Called every frame
void AMyMovingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	
	//If you want to use c++ and not have to worry about blueprints, 
	//this is the alternative
	AActor::AddActorLocalRotation({ RotateObject(), 0.0, 0.0 });
	
	*/

	/* 
	
	//Not scaled by fps 
	AActor::SetActorLocation({ 0.0,TranslateObject(1),90.0 });
	UE_LOG(LogTemp, Warning, TEXT("ypos = %f"), ypos)
	
	*/

	// Scaled by fps
	ypos_scaled = TranslateObject(DeltaTime);
	AActor::SetActorLocation({ 0.0, ypos_scaled ,90.0 });
	
	
	UE_LOG(LogTemp, Warning, TEXT("ypos = %f"), ypos_scaled);
	UE_LOG(LogTemp, Error, TEXT("DeltaTime = %f"), DeltaTime);

}

float AMyMovingObject::TranslateObject(float scale)
{
	// Once implemented in tick, will move to the left 
	//at 10*scale units (in ue4 this is cm) per tick

	//Fancy math would go here

	ypos = ypos + 1000.0*scale;

	// end of fancy math

	return ypos;
}


float AMyMovingObject::RotateObject()
{
	/* 
	
	Fancier math can go here 
	
	*/

	return RotationValue = 0.1;
}