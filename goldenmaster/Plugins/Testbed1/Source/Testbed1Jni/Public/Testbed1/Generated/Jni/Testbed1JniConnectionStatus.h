#pragma once
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "Testbed1JniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTestbed1JniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(FTestbed1JniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

/** @brief Used when the jni service fully started.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestbed1JniServiceStartedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTestbed1JniServiceStartedDelegate);

/** @brief Used when the jni service died.
 * Will not occur when when closed intentionally.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestbed1JniServiceDiedDelegateBP);
DECLARE_MULTICAST_DELEGATE(FTestbed1JniServiceDiedDelegate);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class TESTBED1JNI_API UTestbed1DelegatesDummy : public UObject
{
	GENERATED_BODY()
};
