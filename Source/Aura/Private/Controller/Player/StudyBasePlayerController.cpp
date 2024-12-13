// // Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Controller/Player/StudyBasePlayerController.h"

#include "EnhancedInputSubsystems.h"

AStudyBasePlayerController::AStudyBasePlayerController()
{
	bReplicates = true;
}

void AStudyBasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	try
	{
		if (!AuraContext)
		{
			throw(001);
		}
	}
	catch (int32 ErrorCode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Aura Context was not Valid during AStudyBasePlayerController Begin Play!"));
		UE_LOG(LogTemp, Warning, TEXT("Error Code: %d"), ErrorCode);
	}

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
