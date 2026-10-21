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

static FString StripPIEPrefix(const FString& In)
{
	const int32 Idx = In.Find(TEXT("UEDPIE_"));
	if (Idx == INDEX_NONE) return In;

	int32 After = Idx + 7;                                   // довжина "UEDPIE_"
	while (After < In.Len() && FChar::IsDigit(In[After])) ++After;
	if (After < In.Len() && In[After] == TEXT('_')) ++After;

	return In.Left(Idx) + In.Mid(After);
}

AActor* UChunkLevelLibrary::FindActorWithTagInStreamedWorld(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> StreamedWorld, FName Tag)
{
	UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
	if (!World) return nullptr;

	const FString Target = StripPIEPrefix(StreamedWorld.GetLongPackageName());

	for (ULevelStreaming* Streaming : World->GetStreamingLevels())
	{
		if (!Streaming) continue;
		if (StripPIEPrefix(Streaming->GetWorldAssetPackageName()) != Target) continue;

		ULevel* Level = Streaming->GetLoadedLevel();
		if (!Level) return nullptr;

		for (AActor* Actor : Level->Actors)
		{
			if (Actor && Actor->ActorHasTag(Tag)) return Actor;
		}
		return nullptr;
	}
	return nullptr;
}