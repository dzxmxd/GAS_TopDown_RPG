// Copyright Santa.Wang


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInfos)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		const FString ErrorStr = FString::Printf(TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]"), *AttributeTag.ToString(), *GetNameSafe(this));
		UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor::Red, ErrorStr);
	}
	return FAuraAttributeInfo();
}
