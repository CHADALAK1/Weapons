// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EProjectileType : uint8
{
	E_None			UMETA(DisplayName = "None"),
	E_Melee			UMETA(DisplayName = "Melee"),
	E_Projectile	UMETA(DisplayName = "Projectile"),
	E_Trace			UMETA(DisplayName = "Trace")
};

USTRUCT(BlueprintType)
struct FWeaponConfig
{
	GENERATED_USTRUCT_BODY()

	//Projectile type of the Weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	EProjectileType ProjectileType;

	//Name of the socket to fire from (if any)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	FName SocketName;

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

	//Call this to fire the weapon. Reason for this design
	//is for the sake of having the weapon be an item and "Use" the weapon
	virtual void Use() override;

	//Equip the Weapon
	virtual void Equip() {}

	//UnEquip the weapon
	virtual void UnEquip() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	FWeaponConfig WeaponConfig;

protected:

	virtual void Fire();

	virtual void ProjectileFire();

	virtual void TraceFire();

	virtual void MeleeFire();
};
