// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StudyEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class STUDY_API AStudyEffectActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Applied Effects")
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectClasses;
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass) const;
	
public:	
	AStudyEffectActor();
};
