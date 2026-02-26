// Copyright Solemmbum


#include "EffectActors/AOE/StudyBaseSphereAreaOfEffectActor.h"

#include "Components/SphereComponent.h"

AStudyBaseSphereAreaOfEffectActor::AStudyBaseSphereAreaOfEffectActor()
{
	const TObjectPtr<USphereComponent> Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	SetCollision(Sphere);
}
