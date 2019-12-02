// Fill out your copyright notice in the Description page of Project Settings.

#include "StaticMeshWeapon.h"
#include "Components/StaticMeshComponent.h"


AStaticMeshWeapon::AStaticMeshWeapon()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}