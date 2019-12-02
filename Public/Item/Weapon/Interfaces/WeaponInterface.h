

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WeaponInterface.generated.h"

class APawn;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class WEAPONS_API IWeaponInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Weapon")
	void Fire();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Weapon")
	void SecondaryFire();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Weapon")
	void Aim(bool _Aim);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Weapon")
	void Reload();
};
