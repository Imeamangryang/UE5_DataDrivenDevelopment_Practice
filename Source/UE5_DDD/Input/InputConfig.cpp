#include "InputConfig.h"
#include "InputAction.h"

const UInputAction* UInputConfig::FindInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FTaggedInputAction& Action : InputActions)
	{
		if (Action.InputAction && Action.InputTag.MatchesTagExact(InputTag))
		{
			return Action.InputAction;
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("InputAction not found for tag [%s] in InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	
	return nullptr;
}
