// Copyright Solemmbum


#include "UI/HUD/StudyBaseHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/StudyBaseUserWidget.h"

void AStudyBaseHUD::BeginPlay()
{
	Super::BeginPlay();
	
	OverlayWidget = CreateWidget<UStudyBaseUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
