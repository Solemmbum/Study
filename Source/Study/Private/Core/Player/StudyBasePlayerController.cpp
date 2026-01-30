// Copyright Solemmbum


#include "Core/Player/StudyBasePlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interfaces/InteractableInterface.h"

AStudyBasePlayerController::AStudyBasePlayerController()
{
	bReplicates = true;
}

void AStudyBasePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(BaseInputContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	
	Subsystem->AddMappingContext(BaseInputContext, 0);
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AStudyBasePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	CursorTrace();
}

void AStudyBasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStudyBasePlayerController::Move);
}

void AStudyBasePlayerController::Move(const FInputActionValue& InputActionValue)
{
	APawn* ControlledPawn = GetPawn();
	if (!IsValid(ControlledPawn))
	{
		return;
	}
	
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation(0.f, GetControlRotation().Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(Rotation).GetUnitAxis(EAxis::Y);
	
	ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
	ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
}

void AStudyBasePlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	
	if (!CursorHit.bBlockingHit || !IsValid(CursorHit.GetActor()) || !CursorHit.GetActor()->Implements<UInteractableInterface>())
	{
		if (CurrentInteractableActor.IsValid())
		{
			IInteractableInterface::Execute_ChangeActorHighlightState(CurrentInteractableActor.Get(), false);
			CurrentInteractableActor.Reset();
		}
		
		return;
	}
	
	if (CurrentInteractableActor.Get() != CursorHit.GetActor())
	{
		if (CurrentInteractableActor.IsValid())
		{
			IInteractableInterface::Execute_ChangeActorHighlightState(CurrentInteractableActor.Get(), false);
			CurrentInteractableActor.Reset();
		}
		
		IInteractableInterface::Execute_ChangeActorHighlightState(CursorHit.GetActor(), true);
		CurrentInteractableActor = CursorHit.GetActor();
	}
}
