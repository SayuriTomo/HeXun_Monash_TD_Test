// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TicTacToeGameState/TicTacToeGameState.h"
#include "HeXun_Monash_TDGameMode.generated.h"

UCLASS(minimalapi)
class AHeXun_Monash_TDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHeXun_Monash_TDGameMode();
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	void ProcessGameStage();

	bool CheckForWin();

	void EndMatch();
	
	void GenerateAIDecision();
	
	int BoardSize = 3;
	ECellState WinnerPlayer;
};



