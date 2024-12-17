// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Character/Player/StudyBasePlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Core/Player/StudyPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"

AStudyBasePlayerCharacter::AStudyBasePlayerCharacter()
{
#pragma region Camera Configuration
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->TargetArmLength = 750.f;
	SpringArm->SetRelativeRotation(FRotator(45.f, 0.f, 0.f));
	
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;
	
#pragma endregion Camera Configuration

#pragma region Movement Configuration

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

#pragma endregion Movement Configuration
}

void AStudyBasePlayerCharacter::InitAbilityActorInfo()
{
	AStudyPlayerState* StudyPlayerState = GetPlayerState<AStudyPlayerState>();
	check(StudyPlayerState);
	StudyPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(StudyPlayerState, this);
	AbilitySystemComponent = StudyPlayerState->GetAbilitySystemComponent();
	AttributeSet = StudyPlayerState->GetAttributeSet();
}

void AStudyBasePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init Ability Actor Info for the Server
	InitAbilityActorInfo();
}

void AStudyBasePlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init Ability Actor Info for the Client
	InitAbilityActorInfo();
}
