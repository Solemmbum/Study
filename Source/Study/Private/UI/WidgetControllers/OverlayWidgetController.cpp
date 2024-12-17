// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "AbilitySystem/StudyAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UStudyAttributeSet* StudyAttributeSet = CastChecked<UStudyAttributeSet>(AttributeSet);

	OnMaxHealthChanged.Broadcast(StudyAttributeSet->GetMaxHealth());
	OnHealthChanged.Broadcast(StudyAttributeSet->GetHealth());

	OnMaxManaChanged.Broadcast(StudyAttributeSet->GetMaxMana());
	OnManaChanged.Broadcast(StudyAttributeSet->GetMana());
}
