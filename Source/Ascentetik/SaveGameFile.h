// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SaveGameFile.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGameSave
{
	GENERATED_BODY()
};

USTRUCT(BlueprintType)
struct FSettingsSave
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MasterVolume;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MouseSensitivity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool InvertYAxisEnabled;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FieldOfView;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CameraShakeEnabled;
};

UCLASS(BlueprintType)
class ASCENTETIK_API USaveGameFile : public UDataAsset
{
	GENERATED_BODY()
	
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameSave Game;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSettingsSave Settings;
};
