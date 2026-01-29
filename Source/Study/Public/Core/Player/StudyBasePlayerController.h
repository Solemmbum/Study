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
	
	TSoftObjectPtr<AActor> CurrentInteractableActor;
	
	void Move(const FInputActionValue& InputActionValue);
	void CursorTrace();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
public:
	AStudyBasePlayerController();
	
	virtual void Tick(float DeltaTime) override;
};
