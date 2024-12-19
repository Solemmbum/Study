// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structs/EffectActorStructs.h"
#include "StudyEffectActor.generated.h"

UCLASS()
class STUDY_API AStudyEffectActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UShapeComponent> Collision;

protected:
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TArray<FEffect> GameplayEffects;

	UPROPERTY()
	TArray<FEffectHandle> ActiveEffectsHandles;
	
	virtual void BeginPlay() override;
	
	void SetCollision(const TObjectPtr<UShapeComponent> CollisionIn);
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, FEffect GameplayEffect);

	UFUNCTION(BlueprintCallable)
	void RemoveEffectFromTarget(FEffectHandle EffectHandle, const int32 StacksToRemove = 1) const;
	
public:	
	AStudyEffectActor();
};
