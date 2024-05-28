// Copyright Santa.Wang

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayController.generated.h"

class USplineComponent;
class UAuraAbilitySystemComponent;
class IHoverInterface;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
class UAuraInputConfig;

UCLASS()
class AURA_API AAuraPlayController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayController();
	virtual void PlayerTick(float DeltaTime) override;
	
private:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	void AbilityInputTagsPressed(FGameplayTag InputTag);
	void AbilityInputTagsReleased(FGameplayTag InputTag);
	void AbilityInputTagsHeld(FGameplayTag InputTag);
	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	IHoverInterface* LastActor;
	IHoverInterface* ThisActor;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	UAuraAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::Zero();
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
};
