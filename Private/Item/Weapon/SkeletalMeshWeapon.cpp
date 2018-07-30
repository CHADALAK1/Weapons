// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletalMeshWeapon.h"
#include "Components/SkeletalMeshComponent.h"



ASkeletalMeshWeapon::ASkeletalMeshWeapon()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

void ASkeletalMeshWeapon::Use()
{

}

void ASkeletalMeshWeapon::Fire()
{

}
