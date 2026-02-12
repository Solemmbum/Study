// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "EffectActors/StudyEffectActor.h"
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
	
protected:
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
public:
	AStudyBaseConsumableActor();
	
};
