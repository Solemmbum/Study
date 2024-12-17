// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Core/Player/StudyBasePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interfaces/InteractableInterface.h"

AStudyBasePlayerController::AStudyBasePlayerController()
{
	bReplicates = true;
}

void AStudyBasePlayerController::BeginPlay()
{
	Super::BeginPlay();
	InitializeInput();
}

void AStudyBasePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AStudyBasePlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit)
	{
		return;
	}

	LastInteractable = CurrentInteractable;
	CurrentInteractable = CursorHit.GetActor();

	if (LastInteractable == nullptr)
	{
		if (CurrentInteractable != nullptr)
		{
			CurrentInteractable->HightlightActor();
		}
	}
	else
	{
		if (CurrentInteractable == nullptr)
		{
			LastInteractable->UnHighlightActor();
		}
		else
		{
			if (CurrentInteractable != LastInteractable)
			{
				LastInteractable->UnHighlightActor();
				CurrentInteractable->HightlightActor();
			}
		}
	}
}

void AStudyBasePlayerController::InitializeInput()
{
	try
	{
		if (!StudyContext)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aura Context was not Valid during AStudyBasePlayerController Begin Play!"));
			throw(001);
		}
	}
	catch (int32 ErrorCode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Error Code: %d"), ErrorCode);
		check(StudyContext);
	}

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(StudyContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AStudyBasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent);
	try
	{
		if (!EnhancedInput)
		{
			UE_LOG(LogTemp, Warning, TEXT("Enhanced Input Component was not Valid during AStudyBasePlayerController Setup Input Component!"));
			throw(002);
		}
	}
	catch (int32 ErrorCode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Error Code: %d"), ErrorCode);
		check(EnhancedInput);
	}

	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStudyBasePlayerController::Move);
}

void AStudyBasePlayerController::Move(const FInputActionValue& Value)
{
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		const FVector2D MovementDirection = Value.Get<FVector2D>();
		const FVector ForwardVector = FRotationMatrix(FRotator(0.f, GetControlRotation().Yaw, 0.f)).GetUnitAxis(EAxis::X);
		const FVector RightVector = FRotationMatrix(FRotator(0.f, GetControlRotation().Yaw, 0.f)).GetUnitAxis(EAxis::Y);

		ControlledPawn->AddMovementInput(ForwardVector, MovementDirection.Y);
		ControlledPawn->AddMovementInput(RightVector, MovementDirection.X);
	}
}
