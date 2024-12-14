// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StudyBasePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

/**
 * 
 */
UCLASS()
class STUDY_API AStudyBasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AStudyBasePlayerController();

private:
	UPROPERTY()
	TObjectPtr<UEnhancedInputComponent> EnhancedInput;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> StudyContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& Value);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	
};