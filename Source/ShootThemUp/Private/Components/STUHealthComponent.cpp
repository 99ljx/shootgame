// Shoot Them Up Game,For studying


#include "Components/STUHealthComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent,All,All)


USTUHealthComponent::USTUHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = false;

}



void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	check(MaxHealth > 0);
	
	SetHealth(MaxHealth);
	AActor* Component = GetOwner();
	if (Component)
	{
		Component->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);

	}
	
}



void USTUHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f || IsDead()||!GetWorld())return;
	SetHealth(Health - Damage);
	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	if (IsDead())
	{
		OnDeath.Broadcast();
	}
	else if (AutoHeal&&GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle,this,&USTUHealthComponent::HealUpdate,HealUpdateTime,true,HealDelay);
	}
}

void USTUHealthComponent::HealUpdate()
{
	SetHealth(HealModifier+Health);

	if (Health == MaxHealth && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}
}

void USTUHealthComponent::SetHealth(float NewHealth)
{
	Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Health);
}
