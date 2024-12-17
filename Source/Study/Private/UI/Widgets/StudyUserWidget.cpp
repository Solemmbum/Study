// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.


#include "UI/Widgets/StudyUserWidget.h"

void UStudyUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
