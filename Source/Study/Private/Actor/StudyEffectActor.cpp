// Copyright Solemmbum


#include "Actor/StudyEffectActor.h"

#include "AbilitySystemComponent.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

AStudyEffectActor::AStudyEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	SphereComponent->SetupAttachment(RootComponent);
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
	for (FEffect GameplayEffect : GameplayEffects)
	{
		if (GameplayEffect.GameplayEffectClass != nullptr)
		{
			ApplyEffectToTarget(OtherActor, GameplayEffect);
		}
	}
}

void AStudyEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AStudyEffectActor::ApplyEffectToTarget(AActor* TargetActor, const FEffect& GameplayEffect)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary:: GetAbilitySystemComponent(TargetActor);
	if (!IsValid(TargetAbilitySystemComponent))
	{
		return;
	}
	
	checkf(GameplayEffect.GameplayEffectClass, TEXT("Gameplay Effect Class Invalid on Apply Effect To Target at Study Effect Actor."));
	
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffect.GameplayEffectClass, 1.f, EffectContextHandle);
	const FActiveGameplayEffectHandle EffectHandleRef = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

