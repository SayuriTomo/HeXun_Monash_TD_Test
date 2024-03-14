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
		int BestScore = INT_MIN;
		int BestMove = -1;

		for (int i = 0; i < 9; ++i) {
			if (BoardState[i] == ECellState::Empty) {
				BoardState[i] = ECellState::Cross;
				int Score = Minimax(BoardState, false);
				BoardState[i] = ECellState::Empty;

				if (Score > BestScore) {
					BestScore = Score;
					BestMove = i;
				}
			}
		}
		BoardState[BestMove] = ECellState::Cross;
		bIsPlayerTurn = true;
	}
	
	GetWorldTimerManager().ClearTimer(DelayTimerHandle);
}

void ATicTacToeGameState::StartDelayAI(float DelayTime)
{
	GetWorldTimerManager().SetTimer(DelayTimerHandle, this, &ATicTacToeGameState::GenerateAIDecision, DelayTime, false);
}

int ATicTacToeGameState::Evaluate(TArray<ECellState>& Board)
{
	for (int i = 0; i < 3; ++i) {
		if (Board[i * 3] == Board[i * 3 + 1] && Board[i * 3 + 1] == Board[i * 3 + 2] && Board[i * 3] != ECellState::Empty)
		{
			if(Board[i*3]==ECellState::Cross)
			{
				return 1;
			}
			else if(Board[i*3]==ECellState::Circle)
			{
				return -1;
			}
		}
		
		if (Board[i] == Board[i + 3] && Board[i + 3] == Board[i + 2 * 3] && Board[i] != ECellState::Empty)
		{
			if(Board[i]==ECellState::Cross)
			{
				return 1;
			}
			else if(Board[i]==ECellState::Circle)
			{
				return -1;
			}
		}
	}
	
	if (Board[0] == Board[4] && Board[4] == Board[8] && Board[0] != ECellState::Empty)
	{
		if(Board[0]==ECellState::Cross)
		{
			return 1;
		}
		else if(Board[0]==ECellState::Circle)
		{
			return -1;
		}
	}
	if (Board[2] == Board[4] && Board[4] == Board[6] && Board[2] != ECellState::Empty)
	{
		if(Board[2]==ECellState::Cross)
		{
			return 1;
		}
		else if(Board[2]==ECellState::Circle)
		{
			return -1;
		}
	}
	
	return 0;
}

int ATicTacToeGameState::Minimax(TArray<ECellState>& Board, bool bIsMax)
{
	int Score = Evaluate(Board);
	
	if (Score != 0||IsFull(Board))
		return Score;

	if (bIsMax) {
		int BestScore = INT_MIN;
		for (int i = 0; i < 9; i++) {
			if (Board[i] == ECellState::Empty) {
				Board[i] = ECellState::Cross;
				BestScore = FMath::Max(BestScore, Minimax(Board, false));
				Board[i] = ECellState::Empty;
			}
		}
		return BestScore;
	} else {
		int BestScore = INT_MAX;
		for (int i = 0; i < 9; i++) {
			if (Board[i] == ECellState::Empty) {
				Board[i] = ECellState::Circle;
				BestScore = FMath::Min(BestScore, Minimax(Board, true));
				Board[i] = ECellState::Empty;
			}
		}
		return BestScore;
	}
}

bool ATicTacToeGameState::IsFull(TArray<ECellState>& Board)
{
	for(int i=0; i<Board.Num(); i++)
	{
		if(Board[i] == ECellState::Empty)
		{
			return false;
		}
	}
	return true;
}


