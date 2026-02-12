// Copyright Solemmbum


#include "EffectActors/Consumables/Potions/StudyBasePotionActor.h"

#include "Components/SphereComponent.h"

AStudyBasePotionActor::AStudyBasePotionActor()
{
	const TObjectPtr<USphereComponent> Sphere = CreateDefaultSubobject<USphereComponent>("Sphere Collision");
	Sphere->SetupAttachment(GetRootComponent());
	Sphere->SetSphereRadius(20.f);
	SetCollision(Sphere);
}
