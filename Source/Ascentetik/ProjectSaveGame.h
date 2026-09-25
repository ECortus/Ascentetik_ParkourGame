// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ProjectSaveGame.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGameSaveFields
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FSettingsSaveFields
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MasterVolume;
};

UCLASS(BlueprintType)
class ASCENTETIK_API UProjectSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameSaveFields Game;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSettingsSaveFields Settings;
};
