// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Core/Player/StudyPlayerState.h"

#include "AbilitySystem/StudyAbilitySystemComponent.h"
#include "AbilitySystem/StudyAttributeSet.h"

AStudyPlayerState::AStudyPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UStudyAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UStudyAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AStudyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AStudyPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
