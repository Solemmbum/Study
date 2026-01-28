// Copyright Solemmbum

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StudyBaseCharacter.generated.h"

UCLASS(Abstract)
class STUDY_API AStudyBaseCharacter : public ACharacter
{
	GENERATED_BODY()
	
private:

protected:
	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
	
	virtual void BeginPlay() override;

public:
	AStudyBaseCharacter();

};
