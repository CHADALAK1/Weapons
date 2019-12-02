// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/Ammo/AmmoComponent.h"
#include "Sound/SoundCue.h"

#include "Kismet/GameplayStatics.h"

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

UAudioComponent * AWeapon::PlayWeaponSound(USoundCue *Sound)
{
	UAudioComponent *AC = NULL;
	if (Sound)
	{
		AC = UGameplayStatics::SpawnSoundAttached(Sound, this->GetRootComponent());
	}
	return AC;
}

void AWeapon::Use()
{
	Super::Use();
	Fire();
}

void AWeapon::AttachToPawn(APawn *_Pawn, const FAttachmentTransformRules AttachRules, FName SocketName)
{
	if (_Pawn && IsOwnedBy(_Pawn))
	{
		AttachToActor(_Pawn, AttachRules, SocketName);
	}
}
