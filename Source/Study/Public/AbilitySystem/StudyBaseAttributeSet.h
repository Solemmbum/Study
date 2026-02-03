// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "StudyBaseAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API UStudyBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
private:
	UPROPERTY(ReplicatedUsing = OnRep_Health, Getter)
	FGameplayAttributeData Health;
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth, Getter)
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(ReplicatedUsing = OnRep_Mana, Getter)
	FGameplayAttributeData Mana;
	
	UPROPERTY(ReplicatedUsing = OnRep_MaxMana, Getter)
	FGameplayAttributeData MaxMana;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
public:
	UStudyBaseAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	FGameplayAttributeData GetHealth() const { return Health; }
	FGameplayAttributeData GetMaxHealth() const { return MaxHealth; }
	FGameplayAttributeData GetMana() const { return Mana; }
	FGameplayAttributeData GetMaxMana() const { return MaxMana; }
	
};
