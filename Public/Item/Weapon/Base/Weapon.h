// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Interfaces/WeaponInterface.h"
#include "Weapon.generated.h"


//Forward Declarations
class UAudioComponent;
class USoundCue;

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

	/*Projectile type of the Weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	EProjectileType ProjectileType;

	/*Name of the socket to fire from (if any)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	FName SocketName;

	/*Cost of each fire to use this weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	int ShotCost;

	/*Time Between shots of the weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float TimeBetweenShots;

	/*The distance of the weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float ShotDistance;

	/*The cone spread of the weapon*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	float WeaponSpread;

};

/**
 * Weapon
 * This class inherits from Item in case one wishes to be able to pick up and store this
 * object in an inventory.
 */
UCLASS()
class WEAPONS_API AWeapon : public AItem, public IWeaponInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ammo, meta = (AllowPrivateAccess = "true"))
	class UAmmoComponent *AmmoComponent;
	
public:

	AWeapon();

	/*Call this to fire the weapon. Reason for this design
	 is for the sake of having the weapon be an item and "Use" the weapon
	*/
	virtual void Use() override;

	/*Equip the Weapon */
	virtual void Equip() {}

	/*Equip the weapon*/
	virtual void UnEquip() {}

	/*
	* Attaches Weapon to Pawn via SkeletalMeshComponent
	* @param _Pawn  Pawn to check if it's the correct owner
	* @param AttachRules  Attachment type for the weapon (i.e., hard attach, keep relative transforms, etc)
	* @param SocketName  Socket name to attach weapon to
	*/
	void AttachToPawn(APawn *_Pawn, const FAttachmentTransformRules AttachRules, FName SocketName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Config)
	FWeaponConfig WeaponConfig;

protected:

	/*Main Function to fire Weapon*/
	virtual void Fire();

	/*Function to handle shooting a projectile*/
	virtual void ProjectileFire() {}

	/*Function to Handle firing a Line Trace*/
	virtual void TraceFire() {}

	/*Function to handle Melee Firing*/
	virtual void MeleeFire() {}

	UAudioComponent *PlayWeaponSound(USoundCue *Sound);

public:

	FORCEINLINE UAmmoComponent *GetAmmoComponent() const { return AmmoComponent; }
};
