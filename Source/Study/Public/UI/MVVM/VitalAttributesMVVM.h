// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "UI/MVVM/StudyBaseMVVM.h"
#include "VitalAttributesMVVM.generated.h"

class AStudyBasePlayerState;
/**
 * 
 */
UCLASS()
class STUDY_API UVitalAttributesMVVM : public UStudyBaseMVVM
{
	GENERATED_BODY()
	
private:
#pragma region Attribute Variables
	
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess))
	float CurrentHealth;
	
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess))
	float MaxHealth;
	
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess))
	float CurrentMana;
	
	UPROPERTY(BlueprintReadOnly, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess))
	float MaxMana;
	
#pragma endregion Attribute Variables
	
public:
	UFUNCTION(BlueprintCallable)
	void Initialize();
	
#pragma region Attribute Delegate Functions
	
	void OnCurrentHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData);
	void OnMaxHealthChanged(const FOnAttributeChangeData& OnAttributeChangeData);
	void OnCurrentManaChanged(const FOnAttributeChangeData& OnAttributeChangeData);
	void OnMaxManaChanged(const FOnAttributeChangeData& OnAttributeChangeData);
	
#pragma endregion Attribute Delegate Functions
	
#pragma region Attribute Accessors
	
	void SetCurrentHealth(const float& NewCurrentHealth);
	float GetCurrentHealth() const { return CurrentHealth; }
	
	void SetMaxHealth(const float& NewMaxHealth);
	float GetMaxHealth() const { return MaxHealth; }
	
	void SetCurrentMana(const float& NewCurrentMana);
	float GetCurrentMana() const { return CurrentMana; }
	
	void SetMaxMana(const float& NewMaxMana);
	float GetMaxMana() const { return MaxMana; }
	
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercentage() const;
	
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetManaPercentage() const;
	
#pragma endregion Attribute Accessors
	
};
