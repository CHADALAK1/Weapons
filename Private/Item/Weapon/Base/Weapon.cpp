// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/Ammo/AmmoComponent.h"


AWeapon::AWeapon()
{
	AmmoComponent = CreateDefaultSubobject<UAmmoComponent>(TEXT("AmmoComponent"));
}

void AWeapon::Fire()
{
	switch (WeaponConfig.ProjectileType)
	{
	case EProjectileType::E_None:
		return;
	case EProjectileType::E_Projectile:
		ProjectileFire();
	case EProjectileType::E_Trace:
		TraceFire();
	case EProjectileType::E_Melee:
		MeleeFire();
	}
}

void AWeapon::Use()
{
	Super::Use();
	Fire();
}

void AWeapon::AttachToPawn(USkeletalMeshComponent *PawnMesh, APawn *_Pawn, FName SocketName)
{
	if (_Pawn && IsOwnedBy(_Pawn))
	{
		if (PawnMesh)
		{
			//TODO: Attach to Pawn
		}
	}
}
