// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Actors/StudyEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Components/ShapeComponent.h"
#include "AbilitySystemComponent.h"


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

void AStudyEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (FEffect GameplayEffect : GameplayEffects)
	{
		if (GameplayEffect.GameplayEffectClass != nullptr)
		{
			if (GameplayEffect.ApplicationPolicy == EEffectPolicy::OnOverlap)
			{
				ApplyEffectToTarget(OtherActor, GameplayEffect);
			}
		}
	}
}

void AStudyEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!TargetAbilitySystemComponent)
	{
		return;
	}
	
	for (FEffect GameplayEffect : GameplayEffects)
	{
		if (GameplayEffect.GameplayEffectClass != nullptr)
		{
			if (GameplayEffect.ApplicationPolicy == EEffectPolicy::OnEndOverlap)
			{
				ApplyEffectToTarget(OtherActor, GameplayEffect);
			}
		}
	}

	TArray<int32> IndexToRemoveList;

	for (int i = 0; i < ActiveEffectsHandles.Num(); i++)
	{
		if (FEffectHandle EffectHandle = ActiveEffectsHandles[i]; EffectHandle.RemovalPolicy == EEffectPolicy::OnEndOverlap)
		{
			if (EffectHandle.TargetAbilitySystemComponent == TargetAbilitySystemComponent)
			{
				IndexToRemoveList.Add(i);
				RemoveEffectFromTarget(EffectHandle);
			}
		}
	}

	for (int i = IndexToRemoveList.Num() - 1; i >= 0; i--)
	{
		ActiveEffectsHandles.RemoveAt(IndexToRemoveList[i]);
	}
}

void AStudyEffectActor::ApplyEffectToTarget(AActor* TargetActor, const FEffect GameplayEffect)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetAbilitySystemComponent == nullptr)
	{
		return;
	}

	checkf(GameplayEffect.GameplayEffectClass, TEXT("Gameplay Effect Class Invalid on Apply Effect To Target at Study Effect Actor."));

	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffect.GameplayEffectClass, 1.f, EffectContextHandle);
	const FActiveGameplayEffectHandle EffectHandleRef = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	if (EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Instant)
	{
		return;
	}

	if (GameplayEffect.RemovalPolicy == EEffectPolicy::None)
	{
		return;
	}

	ActiveEffectsHandles.Add(FEffectHandle(TargetAbilitySystemComponent, EffectHandleRef, GameplayEffect.RemovalPolicy));
}

void AStudyEffectActor::RemoveEffectFromTarget(const FEffectHandle EffectHandle, const int32 StacksToRemove) const
{
	checkf(EffectHandle.TargetAbilitySystemComponent, TEXT("Target Ability System Component uninitialized on Remove Effect From Target at Study Effect Actor."));
	checkf(EffectHandle.EffectHandleRef.IsValid(), TEXT("Effect Handle Ref uninitialized on Remove Effect From Target at Study Effect Actor."));

	EffectHandle.TargetAbilitySystemComponent->RemoveActiveGameplayEffect(EffectHandle.EffectHandleRef, StacksToRemove);
}
