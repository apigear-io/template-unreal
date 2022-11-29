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

#include "Testbed1Factory.h"
#include "Implementation/Testbed1StructInterface.h"
#include "Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed1StructInterfaceSimulationClient.h"
#include "Implementation/Testbed1StructArrayInterface.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed1StructArrayInterfaceSimulationClient.h"
#include "Testbed1Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed1ModuleFactory);

TScriptInterface<ITestbed1StructInterfaceInterface> createTestbed1StructInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using OLink service backend"));
	UTestbed1StructInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed1StructInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed1StructInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed1StructInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed1Connection::CONNECTION_OLINK:
		return createTestbed1StructInterfaceOLink(GameInstance, Collection);
	case ETestbed1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed1StructInterfaceSimulationClient>();
	case ETestbed1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed1StructInterface>();
	}
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> createTestbed1StructArrayInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using OLink service backend"));
	UTestbed1StructArrayInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed1StructArrayInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed1StructArrayInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed1StructArrayInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1ModuleFactory::createITestbed1StructArrayInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed1Connection::CONNECTION_OLINK:
		return createTestbed1StructArrayInterfaceOLink(GameInstance, Collection);
	case ETestbed1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed1StructArrayInterfaceSimulationClient>();
	case ETestbed1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed1StructArrayInterface>();
	}
}
