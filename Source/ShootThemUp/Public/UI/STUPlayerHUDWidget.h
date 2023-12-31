// Shoot Them Up Game,For studying

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUPlayerHUDWidget.generated.h"


class USTUWeaponComponent;
UCLASS()
class SHOOTTHEMUP_API USTUPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetHealthPercent()const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool GetCurrentWeaponUIData(FWeaponUIData& UIData)const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	
	bool GetCurrentAmmoData(FAmmoData& AmmoData)const;
	
private:

	USTUWeaponComponent* GetWeaponComponent()const;
};
