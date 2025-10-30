#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "CustomTypesJniConnectionStatus.generated.h"


/**
 * @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCustomTypesJniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FCustomTypesJniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class CUSTOMTYPESJNI_API UCustomTypesDelegatesDummy : public UObject
{
	GENERATED_BODY()
};