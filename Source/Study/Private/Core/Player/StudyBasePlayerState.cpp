// Copyright Solemmbum


#include "Core/Player/StudyBasePlayerState.h"

#include "AbilitySystem/StudyBaseAbilitySystemComponent.h"
#include "AbilitySystem/StudyBaseAttributeSet.h"

AStudyBasePlayerState::AStudyBasePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UStudyBaseAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	
	AttributeSet = CreateDefaultSubobject<UStudyBaseAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.f);
}
