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

#include "TbSame1Factory.h"
#include "Implementation/TbSame1SameStruct1Interface.h"
#include "Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "Generated/Simulation/TbSame1SameStruct1InterfaceSimulationClient.h"
#include "Implementation/TbSame1SameStruct2Interface.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkClient.h"
#include "Generated/Simulation/TbSame1SameStruct2InterfaceSimulationClient.h"
#include "Implementation/TbSame1SameEnum1Interface.h"
#include "Generated/OLink/TbSame1SameEnum1InterfaceOLinkClient.h"
#include "Generated/Simulation/TbSame1SameEnum1InterfaceSimulationClient.h"
#include "Implementation/TbSame1SameEnum2Interface.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkClient.h"
#include "Generated/Simulation/TbSame1SameEnum2InterfaceSimulationClient.h"
#include "TbSame1Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame1ModuleFactory);

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> createTbSame1SameStruct1InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using OLink service backend"));
	UTbSame1SameStruct1InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameStruct1InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameStruct1InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> createTbSame1SameStruct1InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using simulation service backend"));
	UTbSame1SameStruct1InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTbSame1SameStruct1InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameStruct1InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameStruct1InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameStruct1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		return createTbSame1SameStruct1InterfaceOLink(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_SIMU:
		return createTbSame1SameStruct1InterfaceSimulation(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameStruct1Interface>();
	}
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> createTbSame1SameStruct2InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using OLink service backend"));
	UTbSame1SameStruct2InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame1SameStruct2InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameStruct2InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameStruct2InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> createTbSame1SameStruct2InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using simulation service backend"));
	UTbSame1SameStruct2InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTbSame1SameStruct2InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameStruct2InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameStruct2InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameStruct2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		return createTbSame1SameStruct2InterfaceOLink(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_SIMU:
		return createTbSame1SameStruct2InterfaceSimulation(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameStruct2Interface>();
	}
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> createTbSame1SameEnum1InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using OLink service backend"));
	UTbSame1SameEnum1InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame1SameEnum1InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameEnum1InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameEnum1InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> createTbSame1SameEnum1InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using simulation service backend"));
	UTbSame1SameEnum1InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTbSame1SameEnum1InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameEnum1InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameEnum1InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameEnum1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		return createTbSame1SameEnum1InterfaceOLink(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_SIMU:
		return createTbSame1SameEnum1InterfaceSimulation(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameEnum1Interface>();
	}
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> createTbSame1SameEnum2InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using OLink service backend"));
	UTbSame1SameEnum2InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame1SameEnum2InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameEnum2InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameEnum2InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> createTbSame1SameEnum2InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using simulation service backend"));
	UTbSame1SameEnum2InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTbSame1SameEnum2InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame1SameEnum2InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame1SameEnum2InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameEnum2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* settings = GetMutableDefault<UTbSame1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame1Connection::CONNECTION_OLINK:
		return createTbSame1SameEnum2InterfaceOLink(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_SIMU:
		return createTbSame1SameEnum2InterfaceSimulation(GameInstance, Collection);
	case ETbSame1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame1SameEnum2Interface>();
	}
}
