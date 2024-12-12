// // Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Core/StudyCharacterBase.h"

// Sets default values
AStudyCharacterBase::AStudyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStudyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStudyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStudyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

