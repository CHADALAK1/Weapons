// Fill out your copyright notice in the Description page of Project Settings.

#include "SkeletalMeshWeapon.h"
#include "Components/SkeletalMeshComponent.h"



ASkeletalMeshWeapon::ASkeletalMeshWeapon()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

void ASkeletalMeshWeapon::TraceFire()
{
	Super::TraceFire();
	if (GetMesh())
	{
		const int32 RandomSeed = FMath::Rand();
		FRandomStream WeaponRandomStream(RandomSeed);
		const float CurrentSpread = WeaponConfig.WeaponSpread;
		const float SpreadCone = FMath::DegreesToRadians(WeaponConfig.WeaponSpread * 0.5);
		const FVector AimDir = GetMesh()->GetSocketRotation(WeaponConfig.SocketName).Vector();
		const FVector StartTrace = GetMesh()->GetSocketLocation(WeaponConfig.SocketName);
		const FVector ShootDir = WeaponRandomStream.VRandCone(AimDir, SpreadCone, SpreadCone);
		const FVector EndTrace = StartTrace + ShootDir * WeaponConfig.ShotDistance;
		const FHitResult Impact = WeaponTrace(StartTrace, EndTrace);

		ProcessInstantHit(Impact, StartTrace, ShootDir, RandomSeed, CurrentSpread);
	}
}

FHitResult ASkeletalMeshWeapon::WeaponTrace(const FVector &TraceFrom, const FVector &TraceTo) const
{
	static FName WeaponFireTag = FName(TEXT("WeaponTrace"));

	FCollisionQueryParams TraceParams(WeaponFireTag, true, Instigator);
	TraceParams.bReturnPhysicalMaterial = true;
	TraceParams.AddIgnoredActor(this);

	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceFrom, TraceTo, TRACE_WEAPON, TraceParams);

	return Hit;
}

void ASkeletalMeshWeapon::ProcessInstantHit(const FHitResult &Impact, const FVector &Origin, const FVector &ShootDir, int32 RandomSeed, float ReticleSpread)
{
	const FVector EndTrace = Origin + ShootDir * WeaponConfig.ShotDistance;
	const FVector EndPoint = Impact.GetActor() ? Impact.ImpactPoint : EndTrace;

	//..Add Code here to check for what has been hit
}
