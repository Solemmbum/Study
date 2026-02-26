// Copyright Solemmbum


#include "EffectActors/AOE/StudyBaseBoxAreaOfEffectActor.h"

#include "Components/BoxComponent.h"

AStudyBaseBoxAreaOfEffectActor::AStudyBaseBoxAreaOfEffectActor()
{
	const TObjectPtr<UBoxComponent> Box = CreateDefaultSubobject<UBoxComponent>("Collision");
	Box->SetupAttachment(GetRootComponent());
	SetCollision(Box);
}
