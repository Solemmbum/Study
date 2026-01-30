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
	UPROPERTY(EditAnywhere, Category = "Combat", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

protected:
	virtual void BeginPlay() override;

public:
	AStudyBaseCharacter();
	
	USkeletalMeshComponent* GetWeaponMesh() const { return WeaponMesh; }

};
