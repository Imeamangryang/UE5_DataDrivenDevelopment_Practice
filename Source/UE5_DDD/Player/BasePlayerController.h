#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

class UInputConfig;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class UE5_DDD_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputConfig> InputConfig;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	void Input_Move(const FInputActionValue& Value);
	void Input_LightAttack(const FInputActionValue& Value);
	void Input_HeavyAttack(const FInputActionValue& Value);
};