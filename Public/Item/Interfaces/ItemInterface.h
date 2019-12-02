

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WEAPONS_API IItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item")
	void Use();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item")
	void Drop();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item")
	void Pickup();
};
