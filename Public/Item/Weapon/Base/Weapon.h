// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

USTRUCT(BlueprintType)
struct FWeaponConfig
{
	GENERATED_USTRUCT_BODY()

	//Time Between shots of the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float TimeBetweenShots;

	//The distance of the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float ShotDistance;

};

/**
 * 
 */
UCLASS()
class WEAPONS_API AWeapon : public AItem
{
	GENERATED_BODY()
	
public:

	virtual void Use() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	FWeaponConfig WeaponConfig;
	

protected:

	virtual void Fire();
};
