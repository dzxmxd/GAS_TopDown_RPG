// Copyright Santa.Wang


#include "Player/AuraPlayController.h"

#include "EnhancedInputSubsystems.h"
#include "Input/AuraInputComponent.h"
#include "Interaction/HoverInterface.h"

AAuraPlayController::AAuraPlayController(): LastActor(nullptr), ThisActor(nullptr)
{
	bReplicates = true;
}

void AAuraPlayController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeGameAndUI;
	InputModeGameAndUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeGameAndUI.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeGameAndUI);
}

void AAuraPlayController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UAuraInputComponent* AuraInputComponent = CastChecked<UAuraInputComponent>(InputComponent);
	AuraInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayController::Move);
	AuraInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagsPressed,
	                                       &ThisClass::AbilityInputTagsReleased, &ThisClass::AbilityInputTagsHeld);
}

void AAuraPlayController::AbilityInputTagsPressed(FGameplayTag InputTag)
{
	const FString ErrorStr = FString::Printf(TEXT("LOG_TEXT %s"), *InputTag.ToString());
	UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
	GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Red, ErrorStr);
}

void AAuraPlayController::AbilityInputTagsReleased(FGameplayTag InputTag)
{
	const FString ErrorStr = FString::Printf(TEXT("LOG_TEXT %s"), *InputTag.ToString());
	UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
	GEngine->AddOnScreenDebugMessage(2, 3.f, FColor::Green, ErrorStr);
}

void AAuraPlayController::AbilityInputTagsHeld(FGameplayTag InputTag)
{
	const FString ErrorStr = FString::Printf(TEXT("LOG_TEXT %s"), *InputTag.ToString());
	UE_LOG(LogTemp, Error, TEXT("%s:%d %s"), *FString(__FUNCTION__), __LINE__, *ErrorStr);
	GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Blue, ErrorStr);
}

void AAuraPlayController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAuraPlayController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit)
	{
		return;
	}

	LastActor = ThisActor;
	ThisActor = Cast<IHoverInterface>(CursorHit.GetActor());

	if (LastActor != nullptr)
	{
		if (ThisActor != nullptr)
		{
			if (ThisActor != LastActor)
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
		}
		else
		{
			LastActor->UnHighlightActor();
		}
	}
	else
	{
		if (ThisActor != nullptr)
		{
			ThisActor->HighlightActor();
		}
	}
}
