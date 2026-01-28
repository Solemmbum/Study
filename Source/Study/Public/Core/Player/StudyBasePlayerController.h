// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "StudyBasePlayerController.generated.h"

struct FInputActionValue;

class UInputMappingContext;
class UInputAction;

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
	
	UPROPERTY(EditAnywhere, Category = "Input|Movement")
	TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& InputActionValue);
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
public:
	AStudyBasePlayerController();
};
