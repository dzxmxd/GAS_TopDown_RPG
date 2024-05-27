// Copyright Santa.Wang


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
                                                                   const bool bLogNotFound) const
{
	for (const auto& [InputAction, InputTag] : AbilityInputActions)
	{
		if (InputAction && InputTag.MatchesTagExact(InputTag))
		{
			return InputAction;
		}
	}

	if (bLogNotFound)
	{
		const FString ErrorStr = FString::Printf(
			TEXT("Can't find AbilityInputAction for InputTag [%s], on Inputconfig [%s]"), *InputTag.ToString(),
			*GetNameSafe(this));
		UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor::Red, ErrorStr);
	}
	return nullptr;
}
