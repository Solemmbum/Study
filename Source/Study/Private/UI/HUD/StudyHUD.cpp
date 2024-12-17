// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "UI/HUD/StudyHUD.h"

#include "UI/Widgets/StudyUserWidget.h"

void AStudyHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
