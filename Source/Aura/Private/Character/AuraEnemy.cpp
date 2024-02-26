// Copyright Santa.Wang


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/Aura.h"


// Sets default values
AAuraEnemy::AAuraEnemy()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (GetMesh())
	{
		GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	}

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	if (USkeletalMeshComponent* MeshComponent =  GetMesh())
	{
		MeshComponent->SetRenderCustomDepth(true);
	}
	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
	}
}

void AAuraEnemy::UnHighlightActor()
{
	if (USkeletalMeshComponent* MeshComponent =  GetMesh())
	{
		MeshComponent->SetRenderCustomDepth(false);
	}
	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(false);
	}
}

// Called when the game starts or when spawned
void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	if (USkeletalMeshComponent* MeshComponent =  GetMesh())
	{
		MeshComponent->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
	if (Weapon)
	{
		Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}
}

// Called every frame
void AAuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAuraEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

