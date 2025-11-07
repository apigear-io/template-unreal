#pragma once
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sJNI_API" (CAMEL .Module.Name) }}
#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "{{$ModuleName}}JniConnectionStatus.generated.h"

/** @brief Used when the interface client changes its subscription status:
 * either is connected with the service side (true) or connection couldn't be established or ended (false).
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$ModuleName}}JniConnectionStatusChangedDelegateBP, bool, IsConnected);
DECLARE_MULTICAST_DELEGATE_OneParam(F{{$ModuleName}}JniConnectionStatusChangedDelegate, bool /* IsSubscribed */);

// Dummy class required for getting the .generated.h file without which the delegates are properly compiled.
UCLASS()
class {{ $API_MACRO }} U{{$ModuleName}}DelegatesDummy : public UObject
{
	GENERATED_BODY()
};
