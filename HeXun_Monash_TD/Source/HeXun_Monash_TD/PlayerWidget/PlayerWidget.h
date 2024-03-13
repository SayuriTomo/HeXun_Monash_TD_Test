// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlayerWidget.generated.h"

/**
 * 
 */
UCLASS()
class HEXUN_MONASH_TD_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void ChangeColor(int Index);
	
	UPROPERTY(meta = (BindWidget))class UTextBlock* CurrentTurn;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))TArray<class UTextBlock*> CellBlocks;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell3;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell4;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell5;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell6;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell7;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell8;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Cell9;
	void UpdateCell();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))class UTextBlock* Winner;
	
	
};
