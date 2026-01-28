// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StudyBaseCharacter.generated.h"

UCLASS(Abstract)
class STUDY_API AStudyBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AStudyBaseCharacter();

protected:
	virtual void BeginPlay() override;

};
