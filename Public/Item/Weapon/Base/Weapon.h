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

	//Cost of each fire to use this weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	int ShotCost;

	//Time Between shots of the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float TimeBetweenShots;

	//The distance of the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float ShotDistance;

	//The distance of the weapon
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float WeaponSpread;

};

/**
 * 
 */
UCLASS()
class WEAPONS_API AWeapon : public AItem
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	class UAmmoComponent *AmmoComponent;
	
public:

	AWeapon();

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

	//Main Function to fire Weapon
	virtual void Fire();

	//Function to handle shooting a projectile
	virtual void ProjectileFire();

	//Function to Handle firing a Line Trace
	virtual void TraceFire();

	//Function to handle Melee Firing
	virtual void MeleeFire();

public:

	FORCEINLINE UAmmoComponent *GetAmmoComponent() const { return AmmoComponent; }
};
