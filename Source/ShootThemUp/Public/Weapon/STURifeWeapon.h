// Shoot Them Up Game,For studying

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTURifeWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()
public:

	virtual void StartFire()override;
	virtual void StopFire()override;
protected:
	virtual void MakeShot()override;
	virtual bool GetTraceDate(FVector& TraceStart, FVector& TraceEnd) const override;
	virtual void MakeDamage(FHitResult& HitResult);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintReadWrite)
	float TimeBetweenShots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, BlueprintReadWrite)
	float BulletSpread = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageAmount = 10.0f;

private:
	FTimerHandle ShootTimerHandle;


};
