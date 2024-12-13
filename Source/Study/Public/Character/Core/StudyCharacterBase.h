// // Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StudyCharacterBase.generated.h"

UCLASS(Abstract)
class STUDY_API AStudyCharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
	virtual void BeginPlay() override;

public:
	AStudyCharacterBase();

};
