//EXAMPLE STATICMESHWEAPON IMPLEMENTATION

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

protected:

public:

	FORCEINLINE UStaticMeshComponent *GetMesh() const { return Mesh; }
	
	
};
