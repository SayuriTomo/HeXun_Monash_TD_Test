// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerWidget.h"

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

	TTTGameState = GetWorld()->GetGameState<ATicTacToeGameState>();
	TTTGameMode = GetWorld()->GetAuthGameMode<AHeXun_Monash_TDGameMode>();
	
}

void UPlayerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UpdateTurn();
	UpdateCell();
	UpdateWinner();
	
}

void UPlayerWidget::ChangeColor(int Index)
{
	if(TTTGameMode && TTTGameState && !TTTGameState->bIsEnd &&
		TTTGameState->bIsPlayerTurn &&
		TTTGameState->BoardState[Index] == ECellState::Empty)
	{
		TTTGameState->BoardState[Index] = ECellState::Circle;
		
		TTTGameState->bIsPlayerTurn = false;
		TTTGameState->StartDelayAI(2.0f);
	}
}

void UPlayerWidget::UpdateTurn()
{
	if(TTTGameState)
	{
		if(TTTGameState->bIsPlayerTurn)
		{
			CurrentTurn->SetText(FText::FromString("Player Turn"));
		}
		else
		{
			CurrentTurn->SetText(FText::FromString("AI Turn"));
		}
	}
}

void UPlayerWidget::UpdateCell()
{
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

void UPlayerWidget::UpdateWinner()
{
	switch (TTTGameMode->WinnerPlayer)
	{
		case ECellState::Circle:
			Winner->SetText(FText::FromString("Player Win"));
			break;

		case ECellState::Cross:
			Winner->SetText(FText::FromString("AI Win"));
			break;
		
		case ECellState::Empty:
			Winner->SetText(FText::FromString("Draw"));
			break;
		
		case ECellState::None:
			Winner->SetText(FText::FromString("None"));
			break;
				
		default:
			break;
	}
}

void UPlayerWidget::ResetGame()
{
	TTTGameMode->ResetGame();
}

