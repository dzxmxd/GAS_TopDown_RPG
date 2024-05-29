// Copyright Santa.Wang

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "AuraAbilitySystemComponent.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FEffectGrantedTags, const FGameplayTagContainer& /* AssetTags */)

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void AbilityActorInfoSet();
	
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities);

	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	FEffectGrantedTags EffectGrantedTags;
	
protected:
	UFUNCTION(Client, Reliable)
	void ApplyGameplayEffect(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveHandle);
};
