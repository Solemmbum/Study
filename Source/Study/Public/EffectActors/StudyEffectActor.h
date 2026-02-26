// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structs/EffectActorStructs.h"
#include "StudyEffectActor.generated.h"

class UShapeComponent;

UCLASS()
class STUDY_API AStudyEffectActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UShapeComponent> Collision;

protected:
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TArray<FEffect> GameplayEffects;
	
	UPROPERTY()
	TArray<FEffectHandle> ActiveEffectsHandles;
	
	virtual void BeginPlay() override;
	
	void SetCollision(const TObjectPtr<UShapeComponent> CollisionIn);
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	virtual void AddEffectsToActorBasedOnPolicy(UAbilitySystemComponent* TargetAbilitySystemComponent, const EEffectPolicy Policy);
	
	virtual void RemoveEffectsFromActorBasedOnPolicy(UAbilitySystemComponent* TargetAbilitySystemComponent, const EEffectPolicy Policy);
	
	/**
	 * @brief Applies an Effect to a Target Actor. Gameplay Effect must never be Invalid.
	 * @param TargetAbilitySystemComponent The Target Actor that will receive the Effect.
	 * @param GameplayEffect The Effect that will be applied.
	 */
	UFUNCTION()
	void ApplyEffectToTarget(UAbilitySystemComponent* TargetAbilitySystemComponent, const FEffect& GameplayEffect);
	
	UFUNCTION()
	void RemoveEffectFromTarget(const FEffectHandle& EffectHandle, const int32 StacksToRemove = 1);
	
public:	
	AStudyEffectActor();

};
