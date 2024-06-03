// Copyright Santa.Wang


#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

FVector AAuraCharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::InitializeAttributes() const
{
	ApplyAttributesToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyAttributesToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyAttributesToSelf(DefaultVitalAttributes, 1.f);
}

void AAuraCharacterBase::ApplyAttributesToSelf(const TSubclassOf<UGameplayEffect> GamePlayEffectClass, const float Level) const
{
	UAbilitySystemComponent* ASCComponent = GetAbilitySystemComponent();
	check(IsValid(ASCComponent));
	check(IsValid(GamePlayEffectClass));
	FGameplayEffectContextHandle ContextHandle = ASCComponent->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = ASCComponent->MakeOutgoingSpec(GamePlayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), ASCComponent);
}

void AAuraCharacterBase::AddCharacterAbilities() const
{
	UAuraAbilitySystemComponent* AuraASC = CastChecked<UAuraAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority())
	{
		return;
	}
	AuraASC->AddCharacterAbilities(StartupAbilities);
}
