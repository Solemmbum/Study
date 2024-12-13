// // Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StudyBasePlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class AURA_API AStudyBasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AStudyBasePlayerController();

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

protected:
	virtual void BeginPlay() override;

public:
	
};