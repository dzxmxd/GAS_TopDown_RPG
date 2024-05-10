// Copyright Santa.Wang

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayController.generated.h"

class IHoverInterface;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

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

	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	IHoverInterface* LastActor;
	IHoverInterface* ThisActor;
};
