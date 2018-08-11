// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "SkeletalMeshWeapon.generated.h"

#define TRACE_WEAPON ECC_GameTraceChannel1


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

	virtual void TraceFire() override;

	//Creates a line trace and returns the hit result of the line trace
	FHitResult WeaponTrace(const FVector &TraceFrom, const FVector &TraceTo) const;

	//Handles what happens when a Line Trace Hit occures
	virtual void ProcessInstantHit(const FHitResult &Impact, const FVector &Origin, const FVector &ShootDir, int32 RandomSeed, float ReticleSpread);

	
public:

	FORCEINLINE USkeletalMeshComponent *GetMesh() const { return Mesh; }
};
