// Copyright Solemmbum


#include "UI/MVVM/VitalAttributesMVVM.h"

#include "AbilitySystem/StudyBaseAttributeSet.h"
#include "Core/Player/StudyBasePlayerState.h"
#include "AbilitySystemComponent.h"

void UVitalAttributesMVVM::Initialize()
{
	const APlayerController* LocalController = GEngine->GetFirstLocalPlayerController(GetWorld());
	if (!IsValid(LocalController))
	{
		return;
	}
	
	const AStudyBasePlayerState* LocalPlayerState = LocalController->GetPlayerState<AStudyBasePlayerState>();
	if (!IsValid(LocalPlayerState))
	{
		return;
	}
	
	UAbilitySystemComponent* AbilitySystemComponent = LocalPlayerState->GetAbilitySystemComponent();
	const UStudyBaseAttributeSet* AttributeSet = Cast<UStudyBaseAttributeSet>(LocalPlayerState->GetAttributeSet());
	if (!IsValid(AbilitySystemComponent) || !IsValid(AttributeSet))
	{
		return;
	}
	
#pragma region Attribute Bindings
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddUObject(this, &UVitalAttributesMVVM::OnCurrentHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UVitalAttributesMVVM::OnMaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddUObject(this, &UVitalAttributesMVVM::OnCurrentManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute()).AddUObject(this, &UVitalAttributesMVVM::OnMaxManaChanged);
	
#pragma endregion Attribute Bindings
	
#pragma region Attribute Setup
	
	SetCurrentHealth(AttributeSet->GetHealth());
	SetMaxHealth(AttributeSet->GetMaxHealth());
	SetCurrentMana(AttributeSet->GetMana());
	SetMaxMana(AttributeSet->GetMana());
	
#pragma endregion Attribute Setup
}

#pragma region Attribute Delegate Functions

void UVitalAttributesMVVM::OnCurrentHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	SetCurrentHealth(OnAttributeChangeData.NewValue);
}

void UVitalAttributesMVVM::OnMaxHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	SetMaxHealth(OnAttributeChangeData.NewValue);
}

void UVitalAttributesMVVM::OnCurrentManaChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	SetCurrentMana(OnAttributeChangeData.NewValue);
}

void UVitalAttributesMVVM::OnMaxManaChanged(const FOnAttributeChangeData& OnAttributeChangeData)
{
	SetMaxMana(OnAttributeChangeData.NewValue);
}

#pragma endregion Attribute Delegate Functions

#pragma region Attribute Accessors

void UVitalAttributesMVVM::SetCurrentHealth(const float& NewCurrentHealth)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, NewCurrentHealth))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercentage);
	}
}

void UVitalAttributesMVVM::SetMaxHealth(const float& NewMaxHealth)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, NewMaxHealth))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercentage);
	}
}

void UVitalAttributesMVVM::SetCurrentMana(const float& NewCurrentMana)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(CurrentMana, NewCurrentMana))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetManaPercentage);
	}
}

void UVitalAttributesMVVM::SetMaxMana(const float& NewMaxMana)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(MaxMana, NewMaxMana))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetManaPercentage);
	}
}

float UVitalAttributesMVVM::GetHealthPercentage() const
{
	if (MaxHealth == 0.f)
	{
		return 0.f;
	}
	
	return GetCurrentHealth() / GetMaxHealth();
}

float UVitalAttributesMVVM::GetManaPercentage() const
{
	if (MaxMana == 0.f)
	{
		return 0.f;
	}
	
	return GetCurrentMana() / GetMaxMana();
}

#pragma endregion Attribute Accessors