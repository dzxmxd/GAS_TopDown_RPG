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
	GEngine->AddOnScreenDebugMessage(1, 8.f, FColor::Emerald, FString("Effect Applied!"));
}
