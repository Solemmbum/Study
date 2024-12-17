// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Core/Player/StudyBasePlayerState.h"

#include "AbilitySystem/StudyAbilitySystemComponent.h"
#include "AbilitySystem/StudyAttributeSet.h"

AStudyBasePlayerState::AStudyBasePlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UStudyAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UStudyAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AStudyBasePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AStudyBasePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
