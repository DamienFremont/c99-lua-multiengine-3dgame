// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyGameUnreal5GameMode.h"
#include "MyGameUnreal5Character.h"
#include "UObject/ConstructorHelpers.h"

AMyGameUnreal5GameMode::AMyGameUnreal5GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
