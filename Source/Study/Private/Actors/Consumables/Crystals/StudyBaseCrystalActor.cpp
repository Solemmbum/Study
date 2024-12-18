// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/Consumables/Crystals/StudyBaseCrystalActor.h"

#include "Components/CapsuleComponent.h"

AStudyBaseCrystalActor::AStudyBaseCrystalActor()
{
	const TObjectPtr<UCapsuleComponent> Capsule = CreateDefaultSubobject<UCapsuleComponent>("Collision");
	Capsule->SetupAttachment(GetRootComponent());
	Capsule->SetCapsuleHalfHeight(22.f);
	Capsule->SetCapsuleRadius(15.f);
	Capsule->SetRelativeLocation(FVector(2.f, -4.f, -1.f));
	SetCollision(Capsule);
}
