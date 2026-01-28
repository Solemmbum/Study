// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StudyBasePlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> BaseInputContext;
	
protected:
	virtual void BeginPlay() override;
	
public:
	AStudyBasePlayerController();
};
