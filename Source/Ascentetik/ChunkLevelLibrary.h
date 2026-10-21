#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ChunkLevelLibrary.generated.h"   // завжди останній інклюд

class UWorld;

class ULevelStreaming;
class AActor;

UCLASS()
class ASCENTETIK_API UChunkLevelLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Chunks")
	static AActor* FindActorWithTagInLevel(ULevelStreaming* LevelStreaming, FName Tag);
	
	UFUNCTION(BlueprintCallable, Category = "Chunks", meta = (WorldContext = "WorldContextObject"))
	static AActor* FindActorWithTagInStreamedWorld(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> StreamedWorld, FName Tag);
};
