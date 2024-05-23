// Copyright Santa.Wang

#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::OnApplyGameplayEffectCallback);
}

void UAuraAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		// GiveAbility(AbilitySpec);
		GiveAbilityAndActivateOnce(AbilitySpec);
	}
}

void UAuraAbilitySystemComponent::OnApplyGameplayEffectCallback(UAbilitySystemComponent* AbilitySystemComponent,
                                                                const FGameplayEffectSpec& EffectSpec,
                                                                FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllGrantedTags(TagContainer);

	EffectGrantedTags.Broadcast(TagContainer);
}
