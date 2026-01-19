#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "TbRefIfacesJniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbRefIfacesJniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbRefIfacesJniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

/** @brief Used when the jni service fully started.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbRefIfacesJniServiceStartedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbRefIfacesJniServiceStartedDelegate);

/** @brief Used when the jni service died.
 * Will not occur when when closed intentionally.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbRefIfacesJniServiceDiedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbRefIfacesJniServiceDiedDelegate);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class TBREFIFACESJNI_API UTbRefIfacesDelegatesDummy : public UObject
{
	GENERATED_BODY()
};
