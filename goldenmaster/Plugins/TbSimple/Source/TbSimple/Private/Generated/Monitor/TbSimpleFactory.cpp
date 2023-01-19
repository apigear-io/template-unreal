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

#include "TbSimpleFactory.h"
#include "Implementation/TbSimpleSimpleInterface.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "Generated/Simulation/TbSimpleSimpleInterfaceSimulationClient.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "Generated/Simulation/TbSimpleSimpleArrayInterfaceSimulationClient.h"
#include "TbSimpleSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSimpleModuleFactory);

TScriptInterface<ITbSimpleSimpleInterfaceInterface> createTbSimpleSimpleInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using OLink service backend"));
	UTbSimpleSimpleInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSimpleSimpleInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleSimpleInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleSimpleInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> createTbSimpleSimpleInterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using simulation service backend"));
	UTbSimpleSimpleInterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTbSimpleSimpleInterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleSimpleInterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleSimpleInterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleSimpleInterfaceOLink(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_SIMU:
		return createTbSimpleSimpleInterfaceSimulation(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSimpleSimpleInterface>();
	}
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createTbSimpleSimpleArrayInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using OLink service backend"));
	UTbSimpleSimpleArrayInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleSimpleArrayInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleSimpleArrayInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createTbSimpleSimpleArrayInterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using simulation service backend"));
	UTbSimpleSimpleArrayInterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTbSimpleSimpleArrayInterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleSimpleArrayInterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleSimpleArrayInterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleSimpleArrayInterfaceOLink(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_SIMU:
		return createTbSimpleSimpleArrayInterfaceSimulation(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSimpleSimpleArrayInterface>();
	}
}
