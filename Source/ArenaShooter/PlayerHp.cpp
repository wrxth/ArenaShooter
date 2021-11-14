// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHp.h"

// Sets default values for this component's properties
UPlayerHp::UPlayerHp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerHp::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
	// ...
	
}


// Called every frame
void UPlayerHp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerHp::TakeDamage(int _damage) 
{
	CurrentHealth -= _damage;
	CheckHp();
}

void UPlayerHp::CheckHp() 
{
	if (CurrentHealth <= 0)
	{
		
	}
}

