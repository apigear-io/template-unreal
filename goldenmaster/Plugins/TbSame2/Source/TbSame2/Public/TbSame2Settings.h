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
#include "TbSame2Settings.generated.h"

/**
 * Enumeration ETbSame2Connection
 */
UENUM(BlueprintType)
enum class ETbSame2Connection : uint8
{
	CONNECTION_LOCAL UMETA(Displayname = "Local"),
	CONNECTION_OLINK UMETA(Displayname = "Remote OLink")
};

/**
 * Implements the settings for the TbSame2 plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class TBSAME2_API UTbSame2Settings : public UObject
{
	GENERATED_UCLASS_BODY()

	// Choose the backend service to use
	UPROPERTY(EditAnywhere, config, Category = ServiceSetup)
	ETbSame2Connection ServiceConnection;
};
