// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StudyHUD.generated.h"

class UStudyUserWidget;
/**
 * 
 */
UCLASS()
class STUDY_API AStudyHUD : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UStudyUserWidget> OverlayWidgetClass;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	TObjectPtr<UStudyUserWidget> OverlayWidget;
	
};
