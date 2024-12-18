// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Actors/StudyEffectActor.h"
#include "StudyBaseConsumableActor.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBaseConsumableActor : public AStudyEffectActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UShapeComponent> Collision;

protected:
	void SetCollision(const TObjectPtr<UShapeComponent> CollisionIn);
	
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:
	AStudyBaseConsumableActor();
};
