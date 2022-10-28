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

#include <cinttypes>
#include <string>
#include <list>
#include "UObject/Interface.h"
#include "Engine/LatentActionManager.h"
#include "Testbed2_data.h"
#include "Testbed2EmptyInterfaceInterface.generated.h"

/**
 * Declaration for EmptyInterface
 */
// signal delegates
// property delegates
/**
 * Interface UTestbed2EmptyInterfaceInterface only for Unreal Engine's reflection system
 */
UINTERFACE(Blueprintable, MinimalAPI)
class UTestbed2EmptyInterfaceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface ITestbed2EmptyInterfaceInterface
 */
class TESTBED2_API ITestbed2EmptyInterfaceInterface
{
	GENERATED_BODY()

public:
	// signals

	// methods

	// properties

protected:
	// signals
};
