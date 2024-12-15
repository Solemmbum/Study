// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/StudyCharacterBase.h"
#include "Study/Interfaces/InteractableInterface.h"
#include "StudyBaseEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBaseEnemyCharacter : public AStudyCharacterBase, public IInteractableInterface
{
	GENERATED_BODY()

private:
	bool bIsHighlighted;

public:
	AStudyBaseEnemyCharacter();
	
	virtual void HightlightActor() override;
	virtual void UnHighlightActor() override;
	virtual void Tick(float DeltaSeconds) override;
};
