// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONS_API UAmmoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAmmoComponent();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int DefaultAmmo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ammo)
	int Ammo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Ammo)
	int MaxAmmo;

	UPROPERTY(EditDefaultsOnly, Category = Ammo)
	class UDamageType *DamageType;

	UFUNCTION(BlueprintCallable, Category = Ammo)
	int GetAmmo() const { return Ammo; }

	UFUNCTION(BlueprintCallable, Category = Ammo)
	int GetMaxAmmo() const { return MaxAmmo; }

	UFUNCTION(BlueprintCallable, Category = Ammo)
	virtual void SetAmmo(int NewAmmo);

	UFUNCTION(BlueprintCallable, Category = Ammo)
	virtual void SetMaxAmmo(int NewMax);

	UFUNCTION(BlueprintCallable, Category = Ammo)
	virtual void AddAmmo(int NewAmmo);

	UFUNCTION(BlueprintCallable, Category = Ammo)
	virtual void UseAmmo(int NewMax);

		
	
};
