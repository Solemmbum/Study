// Copyright Solemmbum


#include "Character/Core/StudyBaseCharacter.h"

// Sets default values
AStudyBaseCharacter::AStudyBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStudyBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStudyBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AStudyBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

