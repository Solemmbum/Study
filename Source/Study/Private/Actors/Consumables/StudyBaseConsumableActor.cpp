// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/Consumables/StudyBaseConsumableActor.h"

#include "Components/ShapeComponent.h"
#include "AbilitySystemComponent.h"

AStudyBaseConsumableActor::AStudyBaseConsumableActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(GetRootComponent());
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
}

void AStudyBaseConsumableActor::SetCollision(const TObjectPtr<UShapeComponent> CollisionIn)
{
	Collision = CollisionIn;
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AStudyBaseConsumableActor::OnOverlap);
}

void AStudyBaseConsumableActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (TSubclassOf<UGameplayEffect> GameplayEffectClass : GameplayEffectClasses)
	{
		if (GameplayEffectClass != nullptr)
		{
			ApplyEffectToTarget(OtherActor, GameplayEffectClass);
		}
	}
	
	Destroy();
}
