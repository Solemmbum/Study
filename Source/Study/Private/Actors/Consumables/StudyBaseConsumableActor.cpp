// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/Consumables/StudyBaseConsumableActor.h"


AStudyBaseConsumableActor::AStudyBaseConsumableActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
}

void AStudyBaseConsumableActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	Destroy();
}
