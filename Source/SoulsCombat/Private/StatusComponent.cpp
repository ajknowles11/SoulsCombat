// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusComponent.h"

// Sets default values for this component's properties
UStatusComponent::UStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	Health = 100.0f;
	MaxHealth = 100.0f;
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
		Death();
	}

	OnTakeDamage.Broadcast(Damage);
}

void UStatusComponent::Death()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, "Dead");
	OnDeath.Broadcast();
}
