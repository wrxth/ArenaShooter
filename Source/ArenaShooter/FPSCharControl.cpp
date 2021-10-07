// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharControl.h"


// Sets default values
AFPSCharControl::AFPSCharControl()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;
	Cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Cam->AttachTo(RootComponent);
	Cam->SetRelativeLocation(FVector(0, 0, 40));
}

// Called when the game starts or when spawned
void AFPSCharControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharControl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharControl::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &AFPSCharControl::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AFPSCharControl::VerticalMove);

	InputComponent->BindAxis("HorizontalRot", this, &AFPSCharControl::HorizontalRot);
	InputComponent->BindAxis("Verticalrot", this, &AFPSCharControl::VerticalRot);

	InputComponent->BindAction("Jump", IE_Pressed,this, &AFPSCharControl::StartJump);

	InputComponent->BindAction("Sprint", IE_Pressed,this, &AFPSCharControl::StartSprint);
	InputComponent->BindAction("Sprint", IE_Released,this, &AFPSCharControl::StopSprint);
}

void AFPSCharControl::HorizontalMove(float _value) 
{
	if (_value && IsSprinting)
	{
		AddMovementInput(GetActorRightVector() * SpeedMod, _value);
	}
	else if (_value)
	{
		AddMovementInput(GetActorRightVector(), _value);
	}
}

void AFPSCharControl::VerticalMove(float _value)
{
	if (_value && IsSprinting)
	{
		AddMovementInput(GetActorForwardVector() * SpeedMod, _value);
	}
	else if (_value)
	{
		AddMovementInput(GetActorForwardVector(), _value);
	}
}
void AFPSCharControl::HorizontalRot(float _value)
{
	if (_value)
	{
		AddActorLocalRotation(FRotator(0, _value, 0));
	}
}

void AFPSCharControl::VerticalRot(float _value)
{
	if (_value)
	{
		float temp = Cam->GetRelativeRotation().Pitch + _value;
		if (temp < 65 && temp >-65)
		{
			Cam->AddLocalRotation(FRotator(_value ,0 , 0));
		}
	}
}

void AFPSCharControl::StartJump()
{
	ACharacter::Jump();
}

void AFPSCharControl::StartSprint() 
{
	IsSprinting = true;
}
void AFPSCharControl::StopSprint() 
{
	IsSprinting = false;
}


