// Copyright Santa.Wang

#include "AuraAbilityTypes.h"

bool FAuraGameplayEffectContext::IsIsBlockedHit() const
{
	return bIsBlockedHit;
}

void FAuraGameplayEffectContext::SetIsBlockedHit(const bool bInIsBlockedHit)
{
	this->bIsBlockedHit = bInIsBlockedHit;
}

bool FAuraGameplayEffectContext::IsIsCriticalHit() const
{
	return bIsCriticalHit;
}

void FAuraGameplayEffectContext::SetIsCriticalHit(const bool bInIsCriticalHit)
{
	this->bIsCriticalHit = bInIsCriticalHit;
}

UScriptStruct* FAuraGameplayEffectContext::GetScriptStruct() const
{
	return FAuraGameplayEffectContext::StaticStruct();
}

bool FAuraGameplayEffectContext::NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess)
{
	


	return true;
}
