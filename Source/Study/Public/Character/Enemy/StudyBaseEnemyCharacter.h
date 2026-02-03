// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/StudyBaseCharacter.h"
#include "Interfaces/InteractableInterface.h"
#include "StudyBaseEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBaseEnemyCharacter : public AStudyBaseCharacter, public IInteractableInterface
{
	GENERATED_BODY()
	
public:
	AStudyBaseEnemyCharacter();
	
	virtual void BeginPlay() override;
	
#pragma region Interactable Interface
	
	virtual void ChangeActorHighlightState_Implementation(const bool bShouldBeHighlighted) override;
	
#pragma endregion Interactable Interface
	
};