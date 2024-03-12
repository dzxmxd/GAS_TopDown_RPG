// Copyright Santa.Wang


#include "UI/WidgetController/AuraWidgetController.h"

FWidgetControllerParams::FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,
                                                 UAttributeSet* AS) : PlayerController(PC), PlayerState(PS),
                                                                      AbilitySystemComponent(ASC), AttributeSet(AS)
{
}

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}
