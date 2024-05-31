// Copyright Santa.Wang


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	const FString ErrorStr = FString::Printf(TEXT("Projectile spell activate ability called!"));
	UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.f, FColor::Red, ErrorStr);
}
