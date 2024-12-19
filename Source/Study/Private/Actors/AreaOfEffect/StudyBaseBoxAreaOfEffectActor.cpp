// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/AreaOfEffect/StudyBaseBoxAreaOfEffectActor.h"

#include "Components/BoxComponent.h"

AStudyBaseBoxAreaOfEffectActor::AStudyBaseBoxAreaOfEffectActor()
{
	const TObjectPtr<UBoxComponent> Box = CreateDefaultSubobject<UBoxComponent>("Collision");
	Box->SetupAttachment(GetRootComponent());
	SetCollision(Box);
}