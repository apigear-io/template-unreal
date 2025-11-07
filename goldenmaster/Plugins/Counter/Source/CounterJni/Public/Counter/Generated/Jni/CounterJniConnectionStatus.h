#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "CounterJniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCounterJniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FCounterJniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class COUNTERJNI_API UCounterDelegatesDummy : public UObject
{
	GENERATED_BODY()
};
