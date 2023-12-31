// Shoot Them Up Game,For studying


#include "UI/STUPlayerHUDWidget.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"

float USTUPlayerHUDWidget::GetHealthPercent()const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player)return 0.0f;

	const auto Component = Player->GetComponentByClass(USTUHealthComponent::StaticClass());
	const auto HealthComponent = Cast<USTUHealthComponent>(Component);
	if (!HealthComponent)return 0.0f;

	return HealthComponent->GetHealthPercent();

}

bool USTUPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData)const
{

	const auto WeaponComponent = GetWeaponComponent();
	if (!WeaponComponent)return false;

	return WeaponComponent->GetWeaponUIData(UIData);

}

bool USTUPlayerHUDWidget::GetCurrentAmmoData(FAmmoData& AmmoData) const
{

	const auto WeaponComponent = GetWeaponComponent();
	if (!WeaponComponent)return false;

	return WeaponComponent->GetWeaponAmmoData(AmmoData);
}

USTUWeaponComponent* USTUPlayerHUDWidget::GetWeaponComponent()const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player)return nullptr;

	const auto Component = Player->GetComponentByClass(USTUWeaponComponent::StaticClass());
	const auto WeaponComponent = Cast<USTUWeaponComponent>(Component);
	if (!WeaponComponent)return nullptr;

	return WeaponComponent;
}