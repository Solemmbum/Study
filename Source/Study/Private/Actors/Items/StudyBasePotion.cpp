// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/Items/StudyBasePotion.h"

#include "Components/SphereComponent.h"

AStudyBasePotion::AStudyBasePotion()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AStudyBasePotion::OnSphereOverlap);
	Sphere->SetSphereRadius(20.f);
}

void AStudyBasePotion::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ApplyEffectToTarget(OtherActor, InstantGameplayEffectClass);
	Destroy();
}