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

#include "Generated/Testbed1Factory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Testbed1Settings.h"
#include "Implementation/Testbed1StructInterface.h"
#include "Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Implementation/Testbed1StructArrayInterface.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "Testbed1Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed1ModuleFactory);

namespace
{
bool IsTestbed1LogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

TScriptInterface<ITestbed1StructInterfaceInterface> createTestbed1StructInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed1LogEnabled())
	{
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using OLink service backend"));
	}

	UTestbed1StructInterfaceOLinkClient* Instance = Cast<UTestbed1StructInterfaceOLinkClient>(Collection.InitializeDependency(UTestbed1StructInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed1StructInterfaceInterface> createTestbed1StructInterface(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed1LogEnabled())
	{
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using local service backend"));
	}

	UTestbed1StructInterface* Instance = Cast<UTestbed1StructInterface>(Collection.InitializeDependency(UTestbed1StructInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed1Settings* Testbed1Settings = GetMutableDefault<UTestbed1Settings>();

	if (Testbed1Settings->TracerServiceIdentifier == Testbed1LocalBackendIdentifier)
	{
		return createTestbed1StructInterface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(Testbed1Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTestbed1StructInterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTestbed1StructInterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTestbed1StructInterface(Collection);
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> createTestbed1StructArrayInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed1LogEnabled())
	{
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using OLink service backend"));
	}

	UTestbed1StructArrayInterfaceOLinkClient* Instance = Cast<UTestbed1StructArrayInterfaceOLinkClient>(Collection.InitializeDependency(UTestbed1StructArrayInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> createTestbed1StructArrayInterface(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed1LogEnabled())
	{
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using local service backend"));
	}

	UTestbed1StructArrayInterface* Instance = Cast<UTestbed1StructArrayInterface>(Collection.InitializeDependency(UTestbed1StructArrayInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1ModuleFactory::createITestbed1StructArrayInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed1Settings* Testbed1Settings = GetMutableDefault<UTestbed1Settings>();

	if (Testbed1Settings->TracerServiceIdentifier == Testbed1LocalBackendIdentifier)
	{
		return createTestbed1StructArrayInterface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(Testbed1Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTestbed1StructArrayInterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTestbed1StructArrayInterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTestbed1StructArrayInterface(Collection);
}
