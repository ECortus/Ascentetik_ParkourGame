#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChunkLevelLibrary.generated.h"   // завжди останній інклюд

class ULevelStreaming;
class AActor;

UCLASS()
class ASCENTETIK_API UChunkLevelLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Chunks")
	static AActor* FindActorWithTagInLevel(ULevelStreaming* LevelStreaming, FName Tag);
};
