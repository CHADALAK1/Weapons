// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "SkeletalMeshWeapon.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API ASkeletalMeshWeapon : public AWeapon
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent *Mesh;

public:

	ASkeletalMeshWeapon();

	virtual void Use() override;

protected:

	virtual void Fire() override;
	
public:

	FORCEINLINE USkeletalMeshComponent *GetMesh() const { return Mesh; }
};
