// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Character/Enemies/StudyBaseEnemyCharacter.h"

AStudyBaseEnemyCharacter::AStudyBaseEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AStudyBaseEnemyCharacter::HightlightActor()
{
	bIsHighlighted = true;
}

void AStudyBaseEnemyCharacter::UnHighlightActor()
{
	bIsHighlighted = false;
}

// ReSharper disable once CppParameterMayBeConst
void AStudyBaseEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}
