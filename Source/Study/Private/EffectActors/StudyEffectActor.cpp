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
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!IsValid(TargetAbilitySystemComponent))
	{
		return;
	}
	
	AddEffectsToActorBasedOnPolicy(TargetAbilitySystemComponent, EEffectPolicy::OnOverlap);
	RemoveEffectsFromActorBasedOnPolicy(TargetAbilitySystemComponent, EEffectPolicy::OnOverlap);
}

void AStudyEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!IsValid(TargetAbilitySystemComponent))
	{
		return;
	}
	
	AddEffectsToActorBasedOnPolicy(TargetAbilitySystemComponent, EEffectPolicy::OnEndOverlap);
	RemoveEffectsFromActorBasedOnPolicy(TargetAbilitySystemComponent, EEffectPolicy::OnEndOverlap);
}

void AStudyEffectActor::AddEffectsToActorBasedOnPolicy(UAbilitySystemComponent* TargetAbilitySystemComponent, const EEffectPolicy Policy)
{
	for (FEffect GameplayEffect : GameplayEffects)
	{
		if (GameplayEffect.GameplayEffectClass != nullptr && GameplayEffect.ApplicationPolicy == Policy)
		{
			ApplyEffectToTarget(TargetAbilitySystemComponent, GameplayEffect);
		}
	}
}

void AStudyEffectActor::RemoveEffectsFromActorBasedOnPolicy(UAbilitySystemComponent* TargetAbilitySystemComponent, const EEffectPolicy Policy)
{
	TArray<int32> IndexToRemove;
	
	for (int32 i = 0; i < ActiveEffectsHandles.Num(); i++)
	{
		if (const FEffectHandle& EffectHandle = ActiveEffectsHandles[i]; EffectHandle.TargetAbilitySystemComponent == TargetAbilitySystemComponent && EffectHandle.RemovalPolicy == Policy)
		{
			IndexToRemove.Add(i);
			RemoveEffectFromTarget(EffectHandle);
		}
	}
	
	for (int32 i = IndexToRemove.Num() -1; i >= 0; i--)
	{
		ActiveEffectsHandles.RemoveAt(IndexToRemove[i]);
	}
}

void AStudyEffectActor::ApplyEffectToTarget(UAbilitySystemComponent* TargetAbilitySystemComponent, const FEffect& GameplayEffect)
{
	checkf(GameplayEffect.GameplayEffectClass, TEXT("Gameplay Effect Class Invalid on Apply Effect To Target at Study Effect Actor."));
	
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffect.GameplayEffectClass, 1.f, EffectContextHandle);
	const FActiveGameplayEffectHandle EffectHandleRef = TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	
	if (EffectSpecHandle.Data.Get()->Def->DurationPolicy == EGameplayEffectDurationType::Instant || GameplayEffect.RemovalPolicy == EEffectPolicy::None)
	{
		return;
	}
	
	ActiveEffectsHandles.Add(FEffectHandle(TargetAbilitySystemComponent, EffectHandleRef, GameplayEffect.RemovalPolicy));
}

void AStudyEffectActor::RemoveEffectFromTarget(const FEffectHandle& EffectHandle, const int32 StacksToRemove)
{
	checkf(EffectHandle.TargetAbilitySystemComponent, TEXT("Target Ability System Component uninitialized on Remove Effect From Target at Study Effect Actor"));
	checkf(EffectHandle.EffectHandleRef.IsValid(), TEXT("Effect Handle Ref uninitialized on Remove Effect From Target at Study Effect Actor."));
	
	EffectHandle.TargetAbilitySystemComponent->RemoveActiveGameplayEffect(EffectHandle.EffectHandleRef);
}
