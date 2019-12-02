

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ItemInterface.h"
#include "Item.generated.h"

UCLASS()
class WEAPONS_API AItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/////////////INTERFACE CALLS///////////////
	virtual void Use_Implementation() override;
	virtual void Drop_Implementation() override;
	virtual void Pickup_Implementation() override;
	
};
