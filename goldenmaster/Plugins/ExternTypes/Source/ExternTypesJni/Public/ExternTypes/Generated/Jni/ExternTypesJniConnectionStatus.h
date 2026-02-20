#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "ExternTypesJniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExternTypesJniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FExternTypesJniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

/** @brief Used when the jni service fully started.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FExternTypesJniServiceStartedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FExternTypesJniServiceStartedDelegate);

/** @brief Used when the jni service died.
 * Will not occur when when closed intentionally.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FExternTypesJniServiceDiedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FExternTypesJniServiceDiedDelegate);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class EXTERNTYPESJNI_API UExternTypesDelegatesDummy : public UObject
{
	GENERATED_BODY()
};
