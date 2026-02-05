// Copyright Solemmbum


#include "Character/Player/StudyBasePlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Core/Player/StudyBasePlayerState.h"
#include "Camera/CameraComponent.h"
#include "Core/Player/StudyBasePlayerController.h"
#include "UI/HUD/StudyBaseHUD.h"

AStudyBasePlayerCharacter::AStudyBasePlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 750.f;
	
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	
	Camera->bUsePawnControlRotation = false;
	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bConstrainToPlane = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AStudyBasePlayerCharacter::InitializeAbilityActorInfo()
{
	AStudyBasePlayerState* StudyPlayerState = GetPlayerState<AStudyBasePlayerState>();
	checkf(StudyPlayerState, TEXT("Player State not valid on AStudyBasePlayerCharacter::InitializeAbilitySystem"));
	
	StudyPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(StudyPlayerState, this);
	
	AbilitySystemComponent = StudyPlayerState->GetAbilitySystemComponent();
	checkf(AbilitySystemComponent, TEXT("Ability System Component not valid on AStudyBasePlayerCharacter::InitializeAbilitySystem"));
	
	AttributeSet = StudyPlayerState->GetAttributeSet();
	checkf(AttributeSet, TEXT("Attribute Set not valid on AStudyBasePlayerCharacter::InitializeAbilitySystem"));
}

void AStudyBasePlayerCharacter::InitializeOverlay()
{
	const AStudyBasePlayerController* PlayerController = GetController<AStudyBasePlayerController>();
	if (!IsValid(PlayerController))
	{
		return;
	}
	
	AStudyBaseHUD* HUD = PlayerController->GetHUD<AStudyBaseHUD>();
	if (!IsValid(HUD))
	{
		return;
	}
	
	HUD->InitializeOverlay();
}

void AStudyBasePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	InitializeAbilityActorInfo();
	InitializeOverlay();
}

void AStudyBasePlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	InitializeAbilityActorInfo();
	InitializeOverlay();
}
