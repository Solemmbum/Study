// // Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StudyCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AStudyCharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AStudyCharacterBase();

};
