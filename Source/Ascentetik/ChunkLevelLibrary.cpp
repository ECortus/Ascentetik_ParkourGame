#include "ChunkLevelLibrary.h"
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