#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "InputConfig.h"
#include "BaseInputComponent.generated.h"

class UInputAction;

UCLASS(ClassGroup=(Input), meta=(BlueprintSpawnableComponent))
class UE5_DDD_API UBaseInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserClass, typename FuncType>
	void BindInputActionByTag(
		const UInputConfig* InputConfig,
		const FGameplayTag& InputTag,
		ETriggerEvent TriggerEvent,
		UserClass* Object,
		FuncType Func);
};

template <class UserClass, typename FuncType>
void UBaseInputComponent::BindInputActionByTag(
	const UInputConfig* InputConfig,
	const FGameplayTag& InputTag,
	ETriggerEvent TriggerEvent,
	UserClass* Object,
	FuncType Func)
{
	check(InputConfig);

	if (const UInputAction* InputAction = InputConfig->FindInputActionByTag(InputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, Func);
	}
}