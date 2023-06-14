#pragma once
	
#include "STUCoreTypes.generated.h"

class ASTUBaseWeapon;

//BaseWeapon
USTRUCT(BlueprintType)
struct FAmmoData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Bullets;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon", meta = (EditCondition = "!Infinite"))
	int32 Clips;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool Infinite;

};


//WeaponComponent
USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ASTUBaseWeapon>WeaponClass;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	UAnimMontage* ReloadAnimMontage;
};

//UI
USTRUCT(BlueprintType)
struct FWeaponUIData
{
	GENERATED_USTRUCT_BODY()

	//发射器准心
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	UTexture2D* MainIcon;

	//步枪准心
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	UTexture2D* CrossHairIcon;
};


//HealthComponent
DECLARE_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float);


