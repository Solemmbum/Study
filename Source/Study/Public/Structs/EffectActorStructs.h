// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "Enums/EffectActorEnums.h"

#include "EffectActorStructs.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FEffect
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;

	UPROPERTY(EditAnywhere)
	EEffectPolicy ApplicationPolicy = EEffectPolicy::None;

	UPROPERTY(EditAnywhere)
	EEffectPolicy RemovalPolicy = EEffectPolicy::None;
};

USTRUCT(BlueprintType)
struct FEffectHandle
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;

	UPROPERTY(EditAnywhere)
	FActiveGameplayEffectHandle EffectHandleRef;

	UPROPERTY(EditAnywhere)
	EEffectPolicy RemovalPolicy = EEffectPolicy::None;

	FEffectHandle() {}

	FEffectHandle(const TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponentIn, const FActiveGameplayEffectHandle EffectHandleRefIn, const EEffectPolicy RemovalPolicyIn)
	: TargetAbilitySystemComponent(TargetAbilitySystemComponentIn), EffectHandleRef(EffectHandleRefIn), RemovalPolicy(RemovalPolicyIn) {}
};