// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "AbilitySystem/StudyAttributeSet.h"
#include "AbilitySystem/StudyAbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UStudyAttributeSet::UStudyAttributeSet()
{
	
}

void UStudyAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UStudyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UStudyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UStudyAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UStudyAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

#pragma region Attribute Replication Functions

void UStudyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStudyAttributeSet, Health, OldHealth);
}

void UStudyAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStudyAttributeSet, MaxHealth, OldMaxHealth);
}

void UStudyAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStudyAttributeSet, Mana, OldMana);
}

void UStudyAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UStudyAttributeSet, MaxMana, OldMaxMana);
}

#pragma endregion Attribute Replication Functions