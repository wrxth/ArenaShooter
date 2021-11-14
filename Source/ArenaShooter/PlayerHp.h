// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerHp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENASHOOTER_API UPlayerHp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerHp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		int MaxHealth = 100;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
		int CurrentHealth;

	void TakeDamage(int _damage);
	void CheckHp();

	UENUM(BlueprintType)
	enum PlayerState
	{
		Alive UMETA(DisplayName = "ALIVE"),
		Dead   UMETA(DisplayName = "DEAD")
	}

	PlayerState Ps;
		
};
