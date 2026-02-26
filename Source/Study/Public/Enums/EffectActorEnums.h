#pragma once

#include "CoreMinimal.h"
#include "EffectActorEnums.generated.h"

UENUM(BlueprintType)
enum class EEffectPolicy : uint8
{
	OnOverlap,
	OnEndOverlap,
	None
};