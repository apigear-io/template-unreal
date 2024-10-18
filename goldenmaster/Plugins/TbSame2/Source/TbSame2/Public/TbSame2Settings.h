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

const FString TbSame2LocalBackendIdentifier = "Local";

class FSubsystemCollectionBase;
class ITbSame2SameStruct1InterfaceInterface;
class ITbSame2SameStruct2InterfaceInterface;
class ITbSame2SameEnum1InterfaceInterface;
class ITbSame2SameEnum2InterfaceInterface;

/**
 * Implements the settings for the TbSame2 plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class TBSAME2_API UTbSame2Settings : public UObject
{
	GENERATED_BODY()

	UTbSame2Settings(const FObjectInitializer& ObjectInitializer);

public:
	/** Callback used to validate the settings once the engine is available */
	void ValidateSettingsPostEngineInit();

	/** Choose the backend service for the logging decorator to use */
	UPROPERTY(EditAnywhere, config, Category = TracerServiceSetup)
	FString TracerServiceIdentifier;

	/** Choose the olink connection to use */
	UPROPERTY(EditAnywhere, config, Category = OLinkConnectionSetup)
	FString OLinkConnectionIdentifier;
	static TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetITbSame2SameStruct1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetITbSame2SameStruct2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetITbSame2SameEnum1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetITbSame2SameEnum2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
};
