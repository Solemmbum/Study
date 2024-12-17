// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/StudyCharacterBase.h"
#include "Interfaces/InteractableInterface.h"
#include "StudyBaseEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBaseEnemyCharacter : public AStudyCharacterBase, public IInteractableInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AStudyBaseEnemyCharacter();

#pragma region Enemy Interface
	
	virtual void HightlightActor() override;
	virtual void UnHighlightActor() override;

#pragma endregion Enemy Interface
};
