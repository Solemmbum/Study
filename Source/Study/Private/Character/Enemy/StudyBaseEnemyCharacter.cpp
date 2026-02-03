// Copyright Solemmbum


#include "Character/Enemy/StudyBaseEnemyCharacter.h"

#include "AbilitySystem/StudyBaseAbilitySystemComponent.h"
#include "AbilitySystem/StudyBaseAttributeSet.h"
#include "Study/Study.h"

AStudyBaseEnemyCharacter::AStudyBaseEnemyCharacter()
{
#pragma region Collision Settings
	
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	
	GetWeaponMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	GetWeaponMesh()->SetCollisionObjectType(ECC_Pawn);
	GetWeaponMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);
	GetWeaponMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Block);
	GetWeaponMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	GetWeaponMesh()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	
#pragma endregion Collision Settings
	
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	GetWeaponMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
	AbilitySystemComponent = CreateDefaultSubobject<UStudyBaseAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UStudyBaseAttributeSet>("AttributeSet");
}

void AStudyBaseEnemyCharacter::ChangeActorHighlightState_Implementation(const bool bShouldBeHighlighted)
{
	GetMesh()->SetRenderCustomDepth(bShouldBeHighlighted);
	GetWeaponMesh()->SetRenderCustomDepth(bShouldBeHighlighted);
}
