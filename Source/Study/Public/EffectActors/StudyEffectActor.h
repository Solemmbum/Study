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

	/**
	 * @brief Adds Effects to Target Actor based on the given Policy. 
	 *		  If the Gameplay Effect's Application Policy matches the given Policy, the Effect will be applied to the Target Actor.
	 *		  Target Ability System Component must be valid.
	 * @param TargetAbilitySystemComponent The Ability System Component of the Target Actor that will receive the Effects.
	 * @param Policy The Policy that will be checked against the Gameplay Effects' Application Policy to determine which Effects to apply.
	 */
	virtual void AddEffectsToActorBasedOnPolicy(UAbilitySystemComponent* TargetAbilitySystemComponent, const EEffectPolicy Policy);
	
	/**
	 * @brief Removes Effects from the Target Actor based on the given Policy. 
	 *		  If the Gameplay Effect's Removal Policy matches the given Policy, the Effect will be removed from the Target Actor.
	 *		  Target Ability System Component must be valid.
	 * @param TargetAbilitySystemComponent The Ability System Component of the Target Actor that will have the Effect Removed from.
	 * @param Policy The Policy that will be checked against the Gameplay Effects' Removal Policy to determine which Effects to remove.
	 */
	virtual void RemoveEffectsFromActorBasedOnPolicy(UAbilitySystemComponent* TargetAbilitySystemComponent, const EEffectPolicy Policy);
	
	/**
	 * @brief Applies an Effect to a Target Actor. Gameplay Effect must never be Invalid.
	 * @param TargetAbilitySystemComponent The Target Actor that will receive the Effect.
	 * @param GameplayEffect The Effect that will be applied.
	 */
	UFUNCTION()
	void ApplyEffectToTarget(UAbilitySystemComponent* TargetAbilitySystemComponent, const FEffect& GameplayEffect);
	
	/**
	 * @brief Removes an Effect from a Target Actor.
	 * @param EffectHandle The Effect Handle of the Effect that needs to be removed.
	 * @param StacksToRemove The amount of Stacks of the Effect to Remove.
	 */
	UFUNCTION()
	void RemoveEffectFromTarget(const FEffectHandle& EffectHandle, const int32 StacksToRemove = 1);
	
public:	
	AStudyEffectActor();

};
