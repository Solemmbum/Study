// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StudyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class STUDY_API UStudyUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
};
