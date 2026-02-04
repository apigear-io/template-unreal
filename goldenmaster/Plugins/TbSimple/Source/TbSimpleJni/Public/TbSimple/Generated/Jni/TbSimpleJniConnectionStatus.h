#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "TbSimpleJniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSimpleJniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSimpleJniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

/** @brief Used when the jni service fully started.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleJniServiceStartedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbSimpleJniServiceStartedDelegate);

/** @brief Used when the jni service died.
 * Will not occur when when closed intentionally.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSimpleJniServiceDiedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbSimpleJniServiceDiedDelegate);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class TBSIMPLEJNI_API UTbSimpleDelegatesDummy : public UObject
{
	GENERATED_BODY()
};
