// Copyright Epic Games, Inc. All Rights Reserved.

#include "HeXun_Monash_TDGameMode.h"
#include "HeXun_Monash_TDCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "TicTacToeGameState/TicTacToeGameState.h"

AHeXun_Monash_TDGameMode::AHeXun_Monash_TDGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	GameStateClass = ATicTacToeGameState::StaticClass();
	
	PrimaryActorTick.bCanEverTick = true;
}

void AHeXun_Monash_TDGameMode::BeginPlay()
{
	Super::BeginPlay();

	TTTGameState = GetGameState<ATicTacToeGameState>();
	ResetGame();
}

void AHeXun_Monash_TDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(CheckForWin()||CheckForDraw())
	{
		TTTGameState->bIsEnd = true;
	}
}

bool AHeXun_Monash_TDGameMode::CheckForWin()
{
	TArray<ECellState> BoardState = TTTGameState->BoardState;
	for (int Row = 0; Row < BoardSize; ++Row)
	{
		int StartIndex = Row * BoardSize;
		if (BoardState[StartIndex] != ECellState::Empty &&
			BoardState[StartIndex] == BoardState[StartIndex + 1] &&
			BoardState[StartIndex] == BoardState[StartIndex + 2])
		{
			WinnerPlayer = BoardState[StartIndex];
			return true;
		}
	}
	
	for (int Col = 0; Col < BoardSize; ++Col)
	{
		if (BoardState[Col] != ECellState::Empty &&
			BoardState[Col] == BoardState[Col + BoardSize] &&
			BoardState[Col] == BoardState[Col + 2 * BoardSize])
		{
			WinnerPlayer = BoardState[Col];
			return true;
		}
	}
	
	if (BoardState[0] != ECellState::Empty &&
		BoardState[0] == BoardState[4] &&
		BoardState[0] == BoardState[8])
	{
		WinnerPlayer = BoardState[0];
		return true;
	}

	if (BoardState[2] != ECellState::Empty &&
		BoardState[2] == BoardState[4] &&
		BoardState[2] == BoardState[6])
	{
		WinnerPlayer = BoardState[2];
		return true;
	}
	
	return false;
}

bool AHeXun_Monash_TDGameMode::CheckForDraw()
{
	TArray<ECellState> BoardState = TTTGameState->BoardState;
	for(ECellState CellState:BoardState)
	{
		if(CellState==ECellState::Empty)
		{
			return false;
		}
	}
	WinnerPlayer = ECellState::Empty;
	return true;
}

void AHeXun_Monash_TDGameMode::ResetGame()
{
	TTTGameState->ResetBoard();
	TTTGameState->bIsEnd = false;
	TTTGameState->bIsPlayerFirst = FMath::RandBool();
	if(TTTGameState->bIsPlayerFirst)
	{
		TTTGameState->bIsPlayerTurn = true;
	}
	else
	{
		TTTGameState->bIsPlayerTurn = false;
		TTTGameState->StartDelayAI(4.0f);
	}
	WinnerPlayer = ECellState::None;
}



