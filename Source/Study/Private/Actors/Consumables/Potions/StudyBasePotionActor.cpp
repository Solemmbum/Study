// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/Consumables/Potions/StudyBasePotionActor.h"

#include "Components/SphereComponent.h"

AStudyBasePotionActor::AStudyBasePotionActor()
{
	const TObjectPtr<USphereComponent> Sphere = CreateDefaultSubobject<USphereComponent>("Collision");
	Sphere->SetupAttachment(GetRootComponent());
	Sphere->SetSphereRadius(20.f);
	SetCollision(Sphere);
}