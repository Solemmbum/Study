// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "StudyBaseMVVM.generated.h"

/**
 * 
 */
UCLASS() 
class STUDY_API UStudyBaseMVVM : public UMVVMViewModelBase
{
	GENERATED_BODY()
	
public:
	virtual void Initialize();
	
};
