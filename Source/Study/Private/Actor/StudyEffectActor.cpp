// Copyright Solemmbum


#include "Actor/StudyEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/StudyBaseAttributeSet.h"
#include "Components/SphereComponent.h"

AStudyEffectActor::AStudyEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(MeshComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	SphereComponent->SetupAttachment(MeshComponent);
	SphereComponent->SetSphereRadius(104.f);
}

void AStudyEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AStudyEffectActor::OnOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AStudyEffectActor::OnEndOverlap);
}

void AStudyEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: Change this to apply a GameplayEffect. For now, using const_cast as a hack!
	if (const IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UStudyBaseAttributeSet* ConstAttributeSet = Cast<UStudyBaseAttributeSet>(AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UStudyBaseAttributeSet::StaticClass()));
		UStudyBaseAttributeSet* AttributeSet = const_cast<UStudyBaseAttributeSet*>(ConstAttributeSet);
		AttributeSet->SetHealth(AttributeSet->GetHealth() + 20.f);
		Destroy();
	}
}

void AStudyEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

