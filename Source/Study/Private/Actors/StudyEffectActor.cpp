// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/StudyEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/StudyAttributeSet.h"

AStudyEffectActor::AStudyEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(Mesh);
	Sphere->SetSphereRadius(100.f);
}

void AStudyEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AStudyEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AStudyEffectActor::OnEndOverlap);
}

void AStudyEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (const IAbilitySystemInterface* AbilitySystemComponentInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UStudyAttributeSet* ConstStudyAttributeSet = Cast<UStudyAttributeSet>(AbilitySystemComponentInterface->GetAbilitySystemComponent()->GetAttributeSet(UStudyAttributeSet::StaticClass()));
		UStudyAttributeSet* StudyAttributeSet = const_cast<UStudyAttributeSet*>(ConstStudyAttributeSet);
		StudyAttributeSet->SetHealth(ConstStudyAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AStudyEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}