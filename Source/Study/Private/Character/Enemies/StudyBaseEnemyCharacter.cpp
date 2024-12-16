// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Character/Enemies/StudyBaseEnemyCharacter.h"

#include "Study/Study.h"

AStudyBaseEnemyCharacter::AStudyBaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AStudyBaseEnemyCharacter::HightlightActor()
{
	GetMesh()->SetRenderCustomDepth( true);
	Weapon   ->SetRenderCustomDepth( true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon   ->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AStudyBaseEnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon   ->SetRenderCustomDepth(false);
	GetMesh()->SetCustomDepthStencilValue(0.f);
	Weapon   ->SetCustomDepthStencilValue(0.f);
}

void AStudyBaseEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}
