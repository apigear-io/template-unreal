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

#include "CounterFactory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "CounterSettings.h"
#include "Implementation/CounterCounter.h"
#include "Generated/OLink/CounterCounterOLinkClient.h"
#include "CounterSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFCounterModuleFactory);

namespace
{
bool IsCounterLogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ICounterCounterInterface> createCounterCounterOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsCounterLogEnabled())
	{
		UE_LOG(LogFCounterModuleFactory, Log, TEXT("createICounterCounterInterface: Using OLink service backend"));
	}

	UCounterCounterOLinkClient* Instance = GameInstance->GetSubsystem<UCounterCounterOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UCounterCounterOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UCounterCounterOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ICounterCounterInterface> createCounterCounter(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsCounterLogEnabled())
	{
		UE_LOG(LogFCounterModuleFactory, Log, TEXT("createICounterCounterInterface: Using local service backend"));
	}

	UCounterCounter* Instance = GameInstance->GetSubsystem<UCounterCounter>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UCounterCounter::StaticClass());
		Instance = GameInstance->GetSubsystem<UCounterCounter>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ICounterCounterInterface> FCounterModuleFactory::createICounterCounterInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UCounterSettings* CounterSettings = GetMutableDefault<UCounterSettings>();

	if (CounterSettings->TracerServiceIdentifier == CounterLocalBackendIdentifier)
	{
		return createCounterCounter(GameInstance, Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(CounterSettings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createCounterCounterOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createCounterCounterOLink(GameInstance, Collection);
	}

	// fallback to local implementation
	return createCounterCounter(GameInstance, Collection);
}

#else

TScriptInterface<ICounterCounterInterface> createCounterCounterOLink(FSubsystemCollectionBase& Collection)
{
	if (IsCounterLogEnabled())
	{
		UE_LOG(LogFCounterModuleFactory, Log, TEXT("createICounterCounterInterface: Using OLink service backend"));
	}

	UCounterCounterOLinkClient* Instance = Cast<UCounterCounterOLinkClient>(Collection.InitializeDependency(UCounterCounterOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ICounterCounterInterface> createCounterCounter(FSubsystemCollectionBase& Collection)
{
	if (IsCounterLogEnabled())
	{
		UE_LOG(LogFCounterModuleFactory, Log, TEXT("createICounterCounterInterface: Using local service backend"));
	}

	UCounterCounter* Instance = Cast<UCounterCounter>(Collection.InitializeDependency(UCounterCounter::StaticClass()));
	return Instance;
}

TScriptInterface<ICounterCounterInterface> FCounterModuleFactory::createICounterCounterInterface(FSubsystemCollectionBase& Collection)
{
	UCounterSettings* CounterSettings = GetMutableDefault<UCounterSettings>();

	if (CounterSettings->TracerServiceIdentifier == CounterLocalBackendIdentifier)
	{
		return createCounterCounter(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(CounterSettings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createCounterCounterOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createCounterCounterOLink(Collection);
	}

	// fallback to local implementation
	return createCounterCounter(Collection);
}
#endif
