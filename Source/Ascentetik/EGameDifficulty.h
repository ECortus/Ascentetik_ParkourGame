// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EGameDifficulty.generated.h"

UENUM(BlueprintType)
enum class EGameDifficulty : uint8
{
	Easy      UMETA(DisplayName = "Easy"),
	Regular   UMETA(DisplayName = "Regular"),
	Hard      UMETA(DisplayName = "Hard"),
	Endless   UMETA(DisplayName = "Endless")
};
