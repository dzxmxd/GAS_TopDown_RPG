// Copyright Santa.Wang

#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::OnApplyGameplayEffectCallback);
}

void UAuraAbilitySystemComponent::OnApplyGameplayEffectCallback(UAbilitySystemComponent* AbilitySystemComponent,
                                                                const FGameplayEffectSpec& EffectSpec,
                                                                FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllGrantedTags(TagContainer);
	for (const FGameplayTag& Tag : TagContainer)
	{
		//TODO: Broadcast the tag to the widget controller
		const FString ErrorStr = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Silver, ErrorStr);

	}
}
