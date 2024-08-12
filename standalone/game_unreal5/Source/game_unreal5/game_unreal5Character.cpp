// Copyright Epic Games, Inc. All Rights Reserved.

#include "game_unreal5Character.h"
#include "game_unreal5Projectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ENG

typedef struct ENG_Vector3 {
	float x;
	float y;
	float z;
} ENG_Vector3;

void ENG_GameObject_SetLocation(int act, const ENG_Vector3* location);

void ENG_Character_Move(ENG_Vector3* location) {
	location->x = location->x + 1;
	ENG_GameObject_SetLocation(0, location); // TODO: act 0
}

//////////////////////////////////////////////////////////////////////////
// UE5

typedef struct ENG_GoDicoItem {
	int eng;
	AActor* ue5;
} ENG_GoDicoItem;

static ENG_GoDicoItem UE5_enginesMapping[999] = { 0 };

static ENG_Vector3 UE5_characterLocation = { 0,0,0 };

// ENG <-> UE5

ENG_Vector3 UE5_Math_ToVector3(const FVector src) {
	ENG_Vector3 tgt = ENG_Vector3();
	tgt.x = src.X;
	tgt.y = src.Y;
	tgt.z = src.Z;
	return tgt;
}

FVector UE5_Math_ToFVector(const ENG_Vector3 src) {
	FVector tgt = FVector();
	tgt.X = src.x;
	tgt.Y = src.y;
	tgt.Z = src.z;
	return tgt;
}
/*
void UE5_Math_UpdateFVector(FVector* tgt, const ENG_Vector3 src) {
	tgt->X = src.x;
	tgt->Y = src.y;
	tgt->Z = src.z;
}
*/

void ENG_GameObject_SetLocation(int act, const ENG_Vector3* loc) {
	FVector newLoc = UE5_Math_ToFVector(*loc);

	// UE5
	ENG_GoDicoItem dico0 = UE5_enginesMapping[0]; // TODO: act 0
	AActor* act0 = dico0.ue5;

	act0->SetActorLocation(newLoc);
}

void UE5_Move() {
	ENG_Character_Move(&UE5_characterLocation);
}


//////////////////////////////////////////////////////////////////////////
// Agame_unreal5Character

Agame_unreal5Character::Agame_unreal5Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	/*
		// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
		Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
		Mesh1P->SetOnlyOwnerSee(true);
		Mesh1P->SetupAttachment(FirstPersonCameraComponent);
		Mesh1P->bCastDynamicShadow = false;
		Mesh1P->CastShadow = false;
		//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
		Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));
	*/
}

void Agame_unreal5Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	
	UE5_enginesMapping[0] = ENG_GoDicoItem(0, this); // TODO: act 0
	UE5_characterLocation = UE5_Math_ToVector3(GetActorLocation());
}

//////////////////////////////////////////////////////////////////////////// Input

void Agame_unreal5Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &Agame_unreal5Character::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &Agame_unreal5Character::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void Agame_unreal5Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		// AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		// AddMovementInput(GetActorRightVector(), MovementVector.X);
		UE5_Move();
	}
}

void Agame_unreal5Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}