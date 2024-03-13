// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"

#include "HeXun_Monash_TD/HeXun_Monash_TDGameMode.h"
#include "HeXun_Monash_TD/TicTacToeGameState/TicTacToeGameState.h"

void UPlayerWidget::NativeConstruct()
{
	Super::NativeConstruct();
	CellBlocks.Add(Cell1);
	CellBlocks.Add(Cell2);
	CellBlocks.Add(Cell3);
	CellBlocks.Add(Cell4);
	CellBlocks.Add(Cell5);
	CellBlocks.Add(Cell6);
	CellBlocks.Add(Cell7);
	CellBlocks.Add(Cell8);
	CellBlocks.Add(Cell9);
	
}

void UPlayerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	ATicTacToeGameState* TicTacToeGameState = GetWorld()->GetGameState<ATicTacToeGameState>();
	if(TicTacToeGameState)
	{
		if(TicTacToeGameState->bIsPlayerTurn)
		{
			CurrentTurn->SetText(FText::FromString("Player Turn"));
		}
		else
		{
			CurrentTurn->SetText(FText::FromString("AI Turn"));
		}
	}

	UpdateCell();
	
}

void UPlayerWidget::ChangeColor(int Index)
{
	ATicTacToeGameState* TTTGameState = GetWorld()->GetGameState<ATicTacToeGameState>();
	AHeXun_Monash_TDGameMode* TTTGameMode = GetWorld()->GetAuthGameMode<AHeXun_Monash_TDGameMode>();
	
	if(TTTGameMode && TTTGameState &&
		TTTGameState->bIsPlayerTurn &&
		TTTGameState->BoardState[Index] == ECellState::Empty)
	{
		TTTGameState->BoardState[Index] = ECellState::Circle;

		if(TTTGameMode->CheckForWin())
		{
			switch (TTTGameMode->WinnerPlayer)
			{
				case ECellState::Circle:
					Winner->SetText(FText::FromString("Player Win"));
					break;
				
				case ECellState::Cross:
					Winner->SetText(FText::FromString("AI Win"));
					break;
				
				default:break;
			}
		}

		TTTGameState->bIsPlayerTurn = false;
		TTTGameMode->GenerateAIDecision();
	}
}

void UPlayerWidget::UpdateCell()
{
	ATicTacToeGameState* TTTGameState = GetWorld()->GetGameState<ATicTacToeGameState>();
	
	for(int i=0; i<TTTGameState->BoardState.Num(); i++)
	{
		switch (TTTGameState->BoardState[i])
		{
			case ECellState::Empty:
				CellBlocks[i]->SetText(FText::FromString("None"));
				break;
			
			case ECellState::Cross:
				CellBlocks[i]->SetText(FText::FromString("X"));
				break;
			
			case ECellState::Circle:
				CellBlocks[i]->SetText(FText::FromString("O"));
				break;
			
			default:
				break;
		}

	}
}

