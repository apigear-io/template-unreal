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

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "TbSame1Settings.generated.h"

/**
 * Enumeration ETbSame1Connection
 */
UENUM(BlueprintType)
enum class ETbSame1Connection : uint8
{
    CONNECTION_LOCAL UMETA(Displayname = "Local"),
    CONNECTION_WAMP  UMETA(Displayname = "Remote WAMP"),
    CONNECTION_OLINK  UMETA(Displayname = "Remote OLink"),
    CONNECTION_SIMU  UMETA(Displayname = "Remote Simulation")
};

/**
* Implements the settings for the TbSame1 plugin.
*/
UCLASS(Config = Engine, DefaultConfig)
class TBSAME1_API UTbSame1Settings : public UObject
{
	GENERATED_UCLASS_BODY()

	// Choose the backend service to use
	UPROPERTY(EditAnywhere, config, Category = ServiceSetup)
	ETbSame1Connection ServiceConnection;
};
