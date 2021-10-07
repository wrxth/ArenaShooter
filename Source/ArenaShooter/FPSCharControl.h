// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "FPSCharControl.generated.h"


UCLASS()
class ARENASHOOTER_API AFPSCharControl : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharControl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void HorizontalMove(float _value);
	void VerticalMove(float _value);

	void HorizontalRot(float _value);
	void VerticalRot(float _value);

	void StartJump();

	void StartSprint();
	void StopSprint();

	bool IsSprinting = false;

	int SpeedMod = 200;

	UPROPERTY(EditAnywhere, Category = Camera)
		UCameraComponent* Cam;
};
