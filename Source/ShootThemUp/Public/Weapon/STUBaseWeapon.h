// Shoot Them Up Game,For studying

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUCoreTypes.h"
#include "STUBaseWeapon.generated.h"



class USkeletalMeshComponent;


UCLASS()
class SHOOTTHEMUP_API ASTUBaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTUBaseWeapon();

	virtual	void StartFire();
	virtual	void StopFire();

	FWeaponUIData GetUIData()const { return UIData; }
	FAmmoData GetAmmoData()const { return DefaultAmmo; }


protected:

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Component")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,Category="Weapon")
	FName MuzzleSocketName = "MuzzleSocket";



	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FAmmoData DefaultAmmo {15, 10, false};


	float TranceMaxDistance = 1500.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	FWeaponUIData UIData;

	virtual void BeginPlay() override;

	virtual void MakeShot();

	virtual bool GetTraceDate(FVector& TraceStart, FVector& TraceEnd)const;
	
	virtual void MakeDamage(FHitResult& HitResult);

	APlayerController* GetPlayerController() const;
	
	bool GetPlayerPointView(FVector& ViewLocation, FRotator& ViewRotation)const;
	
	FVector GetMuzzleWorldLocation()const;
	
	void MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);
	
	void DecreaseAmmo();
	bool IsAmmoEmpty()const;
	bool IsClipEmpty()const;
	void ChangeClip();
	void LogAmmo();	

private:
	FAmmoData CurrentAmmo;
};
