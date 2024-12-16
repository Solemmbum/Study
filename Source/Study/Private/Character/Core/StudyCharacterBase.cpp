// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#include "Character/Core/StudyCharacterBase.h"

AStudyCharacterBase::AStudyCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AStudyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}