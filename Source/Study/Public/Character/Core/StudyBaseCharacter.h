// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "StudyBaseCharacter.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class STUDY_API AStudyBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Combat", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	virtual void BeginPlay() override;

public:
	AStudyBaseCharacter();
	
	USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }
	
#pragma region Ability System Interface
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	
#pragma endregion Ability System Interface

};
