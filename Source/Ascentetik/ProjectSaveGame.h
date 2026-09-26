// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EGameDifficulty.h"
#include "GameFramework/SaveGame.h"
#include "ProjectSaveGame.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGameSaveFields
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDifficulty Difficulty;
};

USTRUCT(BlueprintType)
struct FSettingsSaveFields
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MasterVolume;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseSensitivity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool InvertYAxis;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FieldOfView;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CameraShake;
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
