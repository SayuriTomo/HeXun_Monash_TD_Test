// Fill out your copyright notice in the Description page of Project Settings.


#include "TicTacToeGameState.h"

ATicTacToeGameState::ATicTacToeGameState()
{
	PrimaryActorTick.bCanEverTick = true;
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
