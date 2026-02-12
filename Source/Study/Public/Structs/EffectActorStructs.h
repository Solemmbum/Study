#pragma once

#include "CoreMinimal.h"

#include "EffectActorStructs.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FEffect
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;
};
