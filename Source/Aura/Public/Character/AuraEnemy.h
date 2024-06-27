﻿// Copyright Santa.Wang

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/HoverInterface.h"
#include "AuraEnemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChangedSignature, float, Health);

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHoverInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraEnemy();

	/* IHoverInterface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/* IHoverInterface */

	/* ICombatInterface*/
	virtual int32 GetPlayerLevel() override;
	/* ICombatInterface*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FHealthChangedSignature HealthChangedDelegate;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;
};
