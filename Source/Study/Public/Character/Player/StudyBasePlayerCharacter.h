// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/StudyBaseCharacter.h"
#include "StudyBasePlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class STUDY_API AStudyBasePlayerCharacter : public AStudyBaseCharacter
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;
	
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;
	
	void InitializeAbilityActorInfo();
	void InitializeOverlay();
	
public:
	AStudyBasePlayerCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
};
