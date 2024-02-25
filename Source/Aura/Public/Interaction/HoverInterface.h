// Copyright Santa.Wang

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HoverInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UHoverInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IHoverInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
