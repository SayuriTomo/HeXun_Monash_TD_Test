// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TicTacToeGameState.generated.h"

UENUM(BlueprintType)
enum class ECellState : uint8
{
	Empty,
	Cross,
	Circle,
	None
};

/**
 * 
 */
UCLASS()
class HEXUN_MONASH_TD_API ATicTacToeGameState : public AGameStateBase
{
	GENERATED_BODY()
	
	ATicTacToeGameState();
	
public:
	UPROPERTY()
	TArray<ECellState> BoardState;
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;
	
	void ResetBoard();

	bool bIsPlayerFirst;
	bool bIsPlayerTurn;
	bool bIsEnd;

	void GenerateAIDecision();

	void StartDelayAI(float DelayTime);
	FTimerHandle DelayTimerHandle;

	

	
};
