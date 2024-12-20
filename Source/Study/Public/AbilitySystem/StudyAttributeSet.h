// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/StudyAbilitySystemComponent.h"
#include "StudyAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT(BlueprintType)
struct FEffectProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Effect")
	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY(EditAnywhere, Category = "Source")
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "Source")
	TObjectPtr<AActor> SourceAvatarActor;

	UPROPERTY(EditAnywhere, Category = "Source")
	TObjectPtr<AController> SourceController;

	UPROPERTY(EditAnywhere, Category = "Source")
	TObjectPtr<ACharacter> SourceCharacter;

	UPROPERTY(EditAnywhere, Category = "Target")
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category = "Target")
	TObjectPtr<AActor> TargetAvatarActor;

	UPROPERTY(EditAnywhere, Category = "Target")
	TObjectPtr<AController> TargetController;

	UPROPERTY(EditAnywhere, Category = "Target")
	TObjectPtr<ACharacter> TargetCharacter;

	FEffectProperties() {}
};

/**
 * 
 */
UCLASS()
class STUDY_API UStudyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

private:
	void SetEffectProperties(const struct FGameplayEffectModCallbackData& Data, FEffectProperties& Props);

public:
	UStudyAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

#pragma region Attribute Variables
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;

#pragma endregion Attribute Variables

#pragma region Attribute Accessors

	ATTRIBUTE_ACCESSORS(UStudyAttributeSet, Health);
	ATTRIBUTE_ACCESSORS(UStudyAttributeSet, MaxHealth);

	ATTRIBUTE_ACCESSORS(UStudyAttributeSet, Mana);
	ATTRIBUTE_ACCESSORS(UStudyAttributeSet, MaxMana);

#pragma endregion Attribute Accessors

#pragma region Attribute Replication Functions

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

#pragma endregion Attribute Replication Functions
};
