// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "Study/Public/UI/WidgetControllers/StudyWidgetController.h"

void UStudyWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}
