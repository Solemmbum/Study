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

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UStudyAttributeSet* StudyAttributeSet = CastChecked<UStudyAttributeSet>(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(StudyAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(StudyAttributeSet->GetHealthAttribute())   .AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(StudyAttributeSet->GetMaxManaAttribute())  .AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(StudyAttributeSet->GetManaAttribute())     .AddUObject(this, &UOverlayWidgetController::ManaChanged);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}
