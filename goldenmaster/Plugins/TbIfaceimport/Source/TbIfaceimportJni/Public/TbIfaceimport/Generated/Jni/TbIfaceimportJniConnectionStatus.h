#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "TbIfaceimportJniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbIfaceimportJniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbIfaceimportJniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

/** @brief Used when the jni service fully started.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbIfaceimportJniServiceStartedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbIfaceimportJniServiceStartedDelegate);

/** @brief Used when the jni service died.
 * Will not occur when when closed intentionally.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbIfaceimportJniServiceDiedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbIfaceimportJniServiceDiedDelegate);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class TBIFACEIMPORTJNI_API UTbIfaceimportDelegatesDummy : public UObject
{
	GENERATED_BODY()
};
