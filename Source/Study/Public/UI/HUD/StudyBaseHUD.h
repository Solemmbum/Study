// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StudyBaseHUD.generated.h"

class UStudyBaseUserWidget;
/**
 * 
 */
UCLASS()
class STUDY_API AStudyBaseHUD : public AHUD
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "Overlay")
	TSubclassOf<UStudyBaseUserWidget> OverlayWidgetClass;
	
public:
	UPROPERTY()
	TObjectPtr<UStudyBaseUserWidget> OverlayWidget;
	
	void InitializeOverlay();
	
	
};
