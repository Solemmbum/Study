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
	
	virtual void BeginPlay() override;
	
	void SetCollision(const TObjectPtr<UShapeComponent> CollisionIn);
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	/**
	 * @brief Applies an Effect to a Target Actor. Gameplay Effect must never be Invalid.
	 * @param TargetActor The Target Actor that will receive the Effect.
	 * @param GameplayEffect The Effect that will be applied.
	 */
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, const FEffect& GameplayEffect);
	
public:	
	AStudyEffectActor();

};
