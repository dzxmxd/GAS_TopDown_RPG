// Copyright Santa.Wang

#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::OnApplyGameplayEffectCallback);

	const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();
	const FString ErrorStr = GameplayTags.Attributes_Secondary_Armor.ToString();
	UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor::Red, ErrorStr);
}

void UAuraAbilitySystemComponent::OnApplyGameplayEffectCallback(UAbilitySystemComponent* AbilitySystemComponent,
                                                                const FGameplayEffectSpec& EffectSpec,
                                                                FActiveGameplayEffectHandle ActiveHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllGrantedTags(TagContainer);

	EffectGrantedTags.Broadcast(TagContainer);
}
