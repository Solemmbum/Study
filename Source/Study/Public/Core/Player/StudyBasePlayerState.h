// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "StudyBasePlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class STUDY_API AStudyBasePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
public:
	AStudyBasePlayerState();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
};
