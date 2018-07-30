// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "StaticMeshWeapon.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONS_API AStaticMeshWeapon : public AWeapon
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *Mesh;
	
public:

	AStaticMeshWeapon();

	virtual void Use() override;

protected:

	virtual void Fire() override;

public:

	FORCEINLINE UStaticMeshComponent *GetMesh() const { return Mesh; }
	
	
};
