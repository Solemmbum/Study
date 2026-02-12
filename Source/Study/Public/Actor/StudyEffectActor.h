// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structs/EffectActorStructs.h"
#include "StudyEffectActor.generated.h"

class USphereComponent;

UCLASS()
class STUDY_API AStudyEffectActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

protected:
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TArray<FEffect> GameplayEffects;
	
	virtual void BeginPlay() override;
	
	/**
	 * @brief Applies an Effect to a Target Actor. Gameplay Effect must never be Invalid.
	 * @param TargetActor The Target Actor that will receive the Effect.
	 * @param GameplayEffect The Effect that will be applied.
	 */
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, const FEffect& GameplayEffect);
	
public:	
	AStudyEffectActor();
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
