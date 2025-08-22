/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "UObject/Interface.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbRefIfacesSimpleLocalIfBPHelperInterface.generated.h"

/**
 * Helper interface for TbRefIfacesSimpleLocalIf events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UTbRefIfacesSimpleLocalIfBPHelperInterface : public UInterface
{
	GENERATED_BODY()
};

class TBREFIFACESAPI_API ITbRefIfacesSimpleLocalIfBPHelperInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "On IntSignal Signal")
	void OnIntSignalSignal(int32 Param);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|TbRefIfaces|SimpleLocalIf|Signals", DisplayName = "On Property IntProperty Changed")
	void OnIntPropertyChanged(UPARAM(DisplayName = "IntProperty") int32 InIntProperty);
};
