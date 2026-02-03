// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "StudyBaseAbilitySystemComponent.h"
#include "StudyBaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class STUDY_API UStudyBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
private:
#pragma region Attributes
	
	UPROPERTY(ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	
#pragma endregion Attributes
	
#pragma region Attribute Rep Notifies
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
#pragma endregion Attribute Rep Notifies
	
public:
	UStudyBaseAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
#pragma region Attribute Accessors
	
	ATTRIBUTE_ACCESSORS(UStudyBaseAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UStudyBaseAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UStudyBaseAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UStudyBaseAttributeSet, MaxMana);
	
#pragma endregion Attribute Accessors
	
};
