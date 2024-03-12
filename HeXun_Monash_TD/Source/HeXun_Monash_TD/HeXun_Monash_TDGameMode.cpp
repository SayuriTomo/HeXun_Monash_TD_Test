// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeXun_Monash_TDGameMode.h"
#include "HeXun_Monash_TDCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHeXun_Monash_TDGameMode::AHeXun_Monash_TDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
