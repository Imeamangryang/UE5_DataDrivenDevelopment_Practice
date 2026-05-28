#include "BasePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "BaseInputComponent.h"
#include "InputActionValue.h"
#include "InputGamePlayTags.h"

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UBaseInputComponent* BaseInputComponent = Cast<UBaseInputComponent>(InputComponent);
	
	checkf(InputConfig, TEXT("InputConfig is null on %s"), *GetName());

	BaseInputComponent->BindInputActionByTag(
		InputConfig,
		InputGamePlayTags::InputTag_Action_Move,
		ETriggerEvent::Triggered,
		this,
		&ThisClass::Input_Move);
	
	BaseInputComponent->BindInputActionByTag(
		InputConfig,
		InputGamePlayTags::InputTag_Action_LightAttack,
		ETriggerEvent::Triggered,
		this,
		&ThisClass::Input_LightAttack);
	
	BaseInputComponent->BindInputActionByTag(
		InputConfig,
		InputGamePlayTags::InputTag_Action_HeavyAttack,
		ETriggerEvent::Triggered,
		this,
		&ThisClass::Input_HeavyAttack);
}

void ABasePlayerController::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MoveValue = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Log, TEXT("Move: X=%.2f Y=%.2f"), MoveValue.X, MoveValue.Y);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Move: X=%.2f Y=%.2f"), MoveValue.X, MoveValue.Y));
}

void ABasePlayerController::Input_LightAttack(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Light Attack Triggered"));	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Light Attack Triggered"));
}

void ABasePlayerController::Input_HeavyAttack(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Log, TEXT("Heavy Attack Triggered"));	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Heavy Attack Triggered"));
}
