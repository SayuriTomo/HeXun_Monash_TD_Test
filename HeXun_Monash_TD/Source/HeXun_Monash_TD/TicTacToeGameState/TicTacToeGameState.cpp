// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeGameState.h"

ATicTacToeGameState::ATicTacToeGameState()
{
	
}


void ATicTacToeGameState::BeginPlay()
{
	Super::BeginPlay();
	ResetBoard();
}

void ATicTacToeGameState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ATicTacToeGameState::ResetBoard()
{
	BoardState.Init(ECellState::Empty,9);
}

void ATicTacToeGameState::GenerateAIDecision()
{
	if(!bIsEnd)
	{
		for(int i=0; i<BoardState.Num(); i++)
		{
			if(BoardState[i]==ECellState::Empty)
			{
				BoardState[i] = ECellState::Cross;
				bIsPlayerTurn = true;
				break;
			}
		}
	}
	GetWorldTimerManager().ClearTimer(DelayTimerHandle);
}

void ATicTacToeGameState::StartDelayAI(float DelayTime)
{
	GetWorldTimerManager().SetTimer(DelayTimerHandle, this, &ATicTacToeGameState::GenerateAIDecision, DelayTime, false);
}
