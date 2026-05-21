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
		InputGamePlayTags::InputTag_Action_MouseLeft,
		ETriggerEvent::Started,
		this,
		&ThisClass::Input_MouseLeft);

	BaseInputComponent->BindInputActionByTag(
		InputConfig,
		InputGamePlayTags::InputTag_Action_MouseRight,
		ETriggerEvent::Started,
		this,
		&ThisClass::Input_MouseRight);

	BaseInputComponent->BindInputActionByTag(
		InputConfig,
		InputGamePlayTags::InputTag_Action_MouseMiddle,
		ETriggerEvent::Started,
		this,
		&ThisClass::Input_MouseMiddle);
}

void ABasePlayerController::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MoveValue = Value.Get<FVector2D>();
	UE_LOG(LogTemp, Log, TEXT("Move: X=%.2f Y=%.2f"), MoveValue.X, MoveValue.Y);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Move: X=%.2f Y=%.2f"), MoveValue.X, MoveValue.Y));
}

void ABasePlayerController::Input_MouseLeft(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MouseLeft"));
}

void ABasePlayerController::Input_MouseRight(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MouseRight"));
}

void ABasePlayerController::Input_MouseMiddle(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MouseMiddle"));
}