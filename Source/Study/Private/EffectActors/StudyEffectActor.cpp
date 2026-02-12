// Copyright Solemmbum


#include "EffectActors/StudyEffectActor.h"

#include "AbilitySystemComponent.h"
#include "Components/ShapeComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

AStudyEffectActor::AStudyEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("RootComponent"));
}

void AStudyEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AStudyEffectActor::SetCollision(const TObjectPtr<UShapeComponent> CollisionIn)
{
	Collision = CollisionIn;
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AStudyEffectActor::OnOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AStudyEffectActor::OnEndOverlap);
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

