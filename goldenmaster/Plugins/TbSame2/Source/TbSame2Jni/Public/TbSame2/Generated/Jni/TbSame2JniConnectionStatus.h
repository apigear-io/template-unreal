#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "TbSame2JniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTbSame2JniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FTbSame2JniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

/** @brief Used when the jni service fully started.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSame2JniServiceStartedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbSame2JniServiceStartedDelegate);

/** @brief Used when the jni service died.
 * Will not occur when when closed intentionally.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTbSame2JniServiceDiedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTbSame2JniServiceDiedDelegate);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class TBSAME2JNI_API UTbSame2DelegatesDummy : public UObject
{
	GENERATED_BODY()
};
