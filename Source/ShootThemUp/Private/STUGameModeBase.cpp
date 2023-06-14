// Shoot Them Up Game,For studying


#include "STUGameModeBase.h"
#include "Player/STUBaseCharacter.h"
#include "Player/STUPlayerController.h"
#include "UI/STUGameHUD.h"

ASTUGameModeBase::ASTUGameModeBase()
{
	DefaultPawnClass = ASTUGameModeBase::StaticClass();
	
	PlayerControllerClass = ASTUPlayerController::StaticClass();

	HUDClass = ASTUGameHUD::StaticClass();
}