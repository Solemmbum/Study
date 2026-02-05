// Copyright Solemmbum


#include "UI/HUD/StudyBaseHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/StudyBaseUserWidget.h"

void AStudyBaseHUD::InitializeOverlay()
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out the HUD."))
	
	OverlayWidget = CreateWidget<UStudyBaseUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
