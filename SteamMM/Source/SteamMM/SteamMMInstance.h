// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "USessionMenuInterface.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "SteamMMInstance.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FServerData
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly)
	FString Name;
	UPROPERTY(BlueprintReadOnly)
	int CurrentPlayers;
	UPROPERTY(BlueprintReadOnly)
	int MaxPlayers;
	UPROPERTY(BlueprintReadOnly)
	FString HostUsername;
};

UCLASS(BlueprintType)
class STEAMMM_API USteamMMInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	virtual void Init() override;

	virtual void OnCreateSessionComplete(FName ServerName, bool Succeeded);

	virtual void OnFindSessionsComplete(bool Succeeded);

	virtual void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	UFUNCTION(BlueprintCallable)
	void CreateServer();

	UFUNCTION(BlueprintCallable)
	void JoinServer();

	// Declare of SessionInterface for the subsystem
	IOnlineSessionPtr SessionInterface;

	// Shareable pointer to the session
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
	
	FName SESSION_NAME = TEXT("SteamMMGameSession");

	
};
