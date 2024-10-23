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
#include "TbSimpleSettings.generated.h"

const FString TbSimpleLocalBackendIdentifier = "Local";

class FSubsystemCollectionBase;
class ITbSimpleVoidInterfaceInterface;
class ITbSimpleSimpleInterfaceInterface;
class ITbSimpleSimpleArrayInterfaceInterface;
class ITbSimpleNoPropertiesInterfaceInterface;
class ITbSimpleNoOperationsInterfaceInterface;
class ITbSimpleNoSignalsInterfaceInterface;
class ITbSimpleEmptyInterfaceInterface;

/**
 * Implements the settings for the TbSimple plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class TBSIMPLECORE_API UTbSimpleSettings : public UObject
{
	GENERATED_BODY()

	UTbSimpleSettings(const FObjectInitializer& ObjectInitializer);

public:
	/** Callback used to validate the settings once the engine is available */
	void ValidateSettingsPostEngineInit();

	/** Choose the backend service for the logging decorator to use */
	UPROPERTY(EditAnywhere, config, Category = TracerServiceSetup)
	FString TracerServiceIdentifier;

	/** Choose the olink connection to use */
	UPROPERTY(EditAnywhere, config, Category = OLinkConnectionSetup)
	FString OLinkConnectionIdentifier;
	static TScriptInterface<ITbSimpleVoidInterfaceInterface> GetITbSimpleVoidInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetITbSimpleSimpleInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetITbSimpleSimpleArrayInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetITbSimpleNoPropertiesInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetITbSimpleNoOperationsInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetITbSimpleNoSignalsInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetITbSimpleEmptyInterfaceInterfaceForLogging(FSubsystemCollectionBase& Collection);
};
