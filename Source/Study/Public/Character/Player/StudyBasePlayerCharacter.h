// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Character/Core/StudyCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "StudyBasePlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBasePlayerCharacter : public AStudyCharacterBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, CAtegory = "Camera")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

public:
	AStudyBasePlayerCharacter();
	
};
