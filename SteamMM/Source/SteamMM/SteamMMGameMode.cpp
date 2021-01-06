// Copyright Epic Games, Inc. All Rights Reserved.

#include "SteamMMGameMode.h"
#include "SteamMMHUD.h"
#include "SteamMMCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASteamMMGameMode::ASteamMMGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASteamMMHUD::StaticClass();
}
