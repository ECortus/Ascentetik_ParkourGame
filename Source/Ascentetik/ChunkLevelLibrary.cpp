#include "ChunkLevelLibrary.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Engine/LevelStreaming.h"
#include "Engine/Level.h"
#include "GameFramework/Actor.h"

AActor* UChunkLevelLibrary::FindActorWithTagInLevel(ULevelStreaming* LevelStreaming, FName Tag)
{
	ULevel* Level = LevelStreaming ? LevelStreaming->GetLoadedLevel() : nullptr;
	if (!Level) return nullptr;

	for (AActor* Actor : Level->Actors)
	{
		if (Actor && Actor->ActorHasTag(Tag))
		{
			return Actor;
		}
	}
	return nullptr;
}

AActor* UChunkLevelLibrary::FindActorWithTagInStreamedWorld(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> StreamedWorld, FName Tag)
{
	UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
	if (!World) 
	{
		UE_LOG(LogTemp, Warning, TEXT("ERROR WORLD"));
	 	return nullptr;
	}

	for (ULevelStreaming* Streaming : World->GetStreamingLevels())
	{
		if (!Streaming || Streaming->GetWorldAsset() != StreamedWorld)
		{
			continue;
		}

		ULevel* Level = Streaming->GetLoadedLevel();
		if (!Level)
		{
			UE_LOG(LogTemp, Warning, TEXT("ERROR LEVEL"));
			return nullptr;
		}

		for (AActor* Actor : Level->Actors)
		{
			if (Actor && Actor->ActorHasTag(Tag))
			{ 
				UE_LOG(LogTemp, Warning, TEXT("ERROR ON ACTOR"));
				return Actor;
			}
		}
		
		UE_LOG(LogTemp, Warning, TEXT("ERROR WORLD AFTER FOR OF LEVEL"));
		return nullptr;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("ERROR WORLD ON END"));
	return nullptr;
}