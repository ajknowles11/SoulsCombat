// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusComponent.h"

// Sets default values for this component's properties
UStatusComponent::UStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatusComponent::TakeDamage(float Damage)
{
	Health = std::clamp(Health - Damage, 0.0f, MaxHealth);
	if (Health == 0.0f) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, "Dead");
	}

	OnTakeDamage.Broadcast(Damage);
}
