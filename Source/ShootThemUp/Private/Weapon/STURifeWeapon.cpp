// Shoot Them Up Game,For studying


#include "Weapon/STURifeWeapon.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

void ASTURifeWeapon::StartFire()
{
	MakeShot();
	GetWorld()->GetTimerManager().SetTimer(ShootTimerHandle, this, &ASTURifeWeapon::MakeShot, TimeBetweenShots, true);
}

void ASTURifeWeapon::StopFire()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootTimerHandle);
}

void ASTURifeWeapon::MakeShot()
{
	if (!GetWorld()||IsAmmoEmpty())return;

	FVector TraceStart;
	FVector TraceEnd;
	if (!GetTraceDate(TraceStart, TraceEnd))return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);


	if (HitResult.bBlockingHit)
	{
		MakeDamage(HitResult);
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0, 3.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
	}
	else
	{
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	}
	DecreaseAmmo();
}

bool ASTURifeWeapon::GetTraceDate(FVector& TraceStart, FVector& TraceEnd)const
{

	FVector ViewLocation;
	FRotator ViewRotation;
	if (!GetPlayerPointView(ViewLocation, ViewRotation))return false;

	TraceStart = ViewLocation;
	const auto HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(ViewRotation.Vector(), HalfRad);
	TraceEnd = TraceStart + ShootDirection * TranceMaxDistance;
	return true;
}


void ASTURifeWeapon::MakeDamage(FHitResult& HitResult)
{
	const auto	DamageActor = HitResult.GetActor();
	if (!DamageActor)return;

	DamageActor->TakeDamage(DamageAmount, FDamageEvent{}, GetPlayerController(), this);
}