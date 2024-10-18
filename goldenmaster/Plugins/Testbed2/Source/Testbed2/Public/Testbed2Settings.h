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
#include "Testbed2Settings.generated.h"

const FString Testbed2LocalBackendIdentifier = "Local";

class FSubsystemCollectionBase;
class ITestbed2ManyParamInterfaceInterface;
class ITestbed2NestedStruct1InterfaceInterface;
class ITestbed2NestedStruct2InterfaceInterface;
class ITestbed2NestedStruct3InterfaceInterface;

/**
 * Implements the settings for the Testbed2 plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class TESTBED2_API UTestbed2Settings : public UObject
{
	GENERATED_BODY()

	UTestbed2Settings(const FObjectInitializer& ObjectInitializer);

public:
	/** Callback used to validate the settings once the engine is available */
	void ValidateSettingsPostEngineInit();

	/** Choose the backend service for the logging decorator to use */
	UPROPERTY(EditAnywhere, config, Category = TracerServiceSetup)
	FString TracerServiceIdentifier;

	/** Choose the olink connection to use */
	UPROPERTY(EditAnywhere, config, Category = OLinkConnectionSetup)
	FString OLinkConnectionIdentifier;
	static TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetITestbed2ManyParamInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetITestbed2NestedStruct1InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetITestbed2NestedStruct2InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetITestbed2NestedStruct3InterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
};
