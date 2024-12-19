// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/AreaOfEffect/StudyBaseSphereAreaOfEffectActor.h"

#include "Components/SphereComponent.h"

AStudyBaseSphereAreaOfEffectActor::AStudyBaseSphereAreaOfEffectActor()
{
	const TObjectPtr<USphereComponent> Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	SetCollision(Sphere);
}
