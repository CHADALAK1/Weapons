// Fill out your copyright notice in the Description page of Project Settings.

#include "AmmoComponent.h"


// Sets default values for this component's properties
UAmmoComponent::UAmmoComponent()
{
	SetAmmo(DefaultAmmo);
}

void UAmmoComponent::SetAmmo(int NewAmmo)
{
	if (NewAmmo <= MaxAmmo)
	{
		Ammo = NewAmmo;
	}
	else
	{
		Ammo = MaxAmmo;
	}
}

void UAmmoComponent::SetMaxAmmo(int NewMax)
{
	MaxAmmo = NewMax;
}

void UAmmoComponent::AddAmmo(int NewAmmo)
{
	if ((Ammo + NewAmmo) <= MaxAmmo)
	{
		Ammo += NewAmmo;
	}
	else
	{
		Ammo = MaxAmmo;
	}
}

void UAmmoComponent::UseAmmo(int NewMax)
{
	if ((Ammo - NewMax) >= 0)
	{
		Ammo -= NewMax;
	}
	else
	{
		Ammo = 0;
	}
}

