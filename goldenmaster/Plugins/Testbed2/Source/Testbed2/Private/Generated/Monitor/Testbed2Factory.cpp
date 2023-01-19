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

#include "Testbed2Factory.h"
#include "Implementation/Testbed2ManyParamInterface.h"
#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed2ManyParamInterfaceSimulationClient.h"
#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Generated/OLink/Testbed2NestedStruct1InterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed2NestedStruct1InterfaceSimulationClient.h"
#include "Implementation/Testbed2NestedStruct2Interface.h"
#include "Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed2NestedStruct2InterfaceSimulationClient.h"
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Generated/OLink/Testbed2NestedStruct3InterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed2NestedStruct3InterfaceSimulationClient.h"
#include "Implementation/Testbed2NoPropertyInterface.h"
#include "Generated/OLink/Testbed2NoPropertyInterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed2NoPropertyInterfaceSimulationClient.h"
#include "Implementation/Testbed2EmptyInterface.h"
#include "Generated/OLink/Testbed2EmptyInterfaceOLinkClient.h"
#include "Generated/Simulation/Testbed2EmptyInterfaceSimulationClient.h"
#include "Testbed2Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed2ModuleFactory);

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using OLink service backend"));
	UTestbed2ManyParamInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2ManyParamInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using simulation service backend"));
	UTestbed2ManyParamInterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2ManyParamInterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2ManyParamInterfaceOLink(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_SIMU:
		return createTestbed2ManyParamInterfaceSimulation(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2ManyParamInterface>();
	}
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using OLink service backend"));
	UTestbed2NestedStruct1InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct1InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using simulation service backend"));
	UTestbed2NestedStruct1InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct1InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NestedStruct1InterfaceOLink(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_SIMU:
		return createTestbed2NestedStruct1InterfaceSimulation(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NestedStruct1Interface>();
	}
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using OLink service backend"));
	UTestbed2NestedStruct2InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct2InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using simulation service backend"));
	UTestbed2NestedStruct2InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct2InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NestedStruct2InterfaceOLink(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_SIMU:
		return createTestbed2NestedStruct2InterfaceSimulation(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NestedStruct2Interface>();
	}
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using OLink service backend"));
	UTestbed2NestedStruct3InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct3InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3InterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using simulation service backend"));
	UTestbed2NestedStruct3InterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3InterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct3InterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3InterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NestedStruct3InterfaceOLink(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_SIMU:
		return createTestbed2NestedStruct3InterfaceSimulation(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NestedStruct3Interface>();
	}
}

TScriptInterface<ITestbed2NoPropertyInterfaceInterface> createTestbed2NoPropertyInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Using OLink service backend"));
	UTestbed2NoPropertyInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NoPropertyInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NoPropertyInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NoPropertyInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NoPropertyInterfaceInterface> createTestbed2NoPropertyInterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Using simulation service backend"));
	UTestbed2NoPropertyInterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTestbed2NoPropertyInterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NoPropertyInterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NoPropertyInterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2NoPropertyInterfaceInterface> FTestbed2ModuleFactory::createITestbed2NoPropertyInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NoPropertyInterfaceOLink(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_SIMU:
		return createTestbed2NoPropertyInterfaceSimulation(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NoPropertyInterface>();
	}
}

TScriptInterface<ITestbed2EmptyInterfaceInterface> createTestbed2EmptyInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Using OLink service backend"));
	UTestbed2EmptyInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2EmptyInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2EmptyInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2EmptyInterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2EmptyInterfaceInterface> createTestbed2EmptyInterfaceSimulation(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Using simulation service backend"));
	UTestbed2EmptyInterfaceSimulationClient* Instance = GameInstance->GetSubsystem<UTestbed2EmptyInterfaceSimulationClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2EmptyInterfaceSimulationClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2EmptyInterfaceSimulationClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITestbed2EmptyInterfaceInterface> FTestbed2ModuleFactory::createITestbed2EmptyInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2EmptyInterfaceOLink(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_SIMU:
		return createTestbed2EmptyInterfaceSimulation(GameInstance, Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2EmptyInterface>();
	}
}
