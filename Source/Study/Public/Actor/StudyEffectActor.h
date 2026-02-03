// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StudyEffectActor.generated.h"

class USphereComponent;

UCLASS()
class STUDY_API AStudyEffectActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

protected:
	virtual void BeginPlay() override;
	
public:	
	AStudyEffectActor();
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
