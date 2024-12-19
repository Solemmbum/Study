// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EffectActorEnums.generated.h"

UENUM(BlueprintType)
enum class EEffectPolicy
{
	OnOverlap,
	OnEndOverlap,
	None
};