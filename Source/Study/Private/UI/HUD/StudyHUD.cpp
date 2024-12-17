// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "UI/HUD/StudyHUD.h"

#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "UI/Widgets/StudyUserWidget.h"

UOverlayWidgetController* AStudyHUD::GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WidgetControllerParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	
	return OverlayWidgetController;
}

void AStudyHUD::InitOverlay(APlayerController* PlayerController, APlayerState* PlayerState,
	UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_StudyHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_StudyHUD"));
	
	OverlayWidget = Cast<UStudyUserWidget>(CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass));

	const FWidgetControllerParams WidgetControllerParams = FWidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	OverlayWidget->AddToViewport();
}
