// Copyright Solemmbum


#include "Character/Core/StudyBaseCharacter.h"

// Sets default values
AStudyBaseCharacter::AStudyBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("LeftHandWeaponSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AStudyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

