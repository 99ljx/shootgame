// Shoot Them Up Game,For studying


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjectile.h"
#include "Kismet/GameplayStatics.h"


void ASTULauncherWeapon::StartFire()
{
	MakeShot();
}

void ASTULauncherWeapon::MakeShot()
{
	if (!GetWorld()||IsAmmoEmpty())return;

	FVector TraceStart;
	FVector TraceEnd;
	if (!GetTraceDate(TraceStart, TraceEnd))return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);

	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
	const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();



	//存储了旋转和位置信息
	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
	ASTUProjectile* Projectile =GetWorld()->SpawnActorDeferred<ASTUProjectile>(ProjectileClass, SpawnTransform);

	//Set projectile params
	if (Projectile)
	{
		Projectile->SetShotDirection(Direction);
		Projectile->SetOwner(GetOwner());
		Projectile->FinishSpawning(SpawnTransform);
	}

	DecreaseAmmo();
}