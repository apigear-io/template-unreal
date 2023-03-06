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
#include "ApiGearSettings.h"
#include "Implementation/Testbed2ManyParamInterface.h"
#include "Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Generated/OLink/Testbed2NestedStruct1InterfaceOLinkClient.h"
#include "Implementation/Testbed2NestedStruct2Interface.h"
#include "Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Generated/OLink/Testbed2NestedStruct3InterfaceOLinkClient.h"
#include "Testbed2Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed2ModuleFactory);

namespace
{
bool IsLogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using OLink service backend"));
	}

	UTestbed2ManyParamInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2ManyParamInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using local service backend"));
	}

	UTestbed2ManyParamInterface* Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2ManyParamInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2ManyParamInterface>(GameInstance);
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
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2ManyParamInterface(GameInstance, Collection);
	default:
		return createTestbed2ManyParamInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using OLink service backend"));
	}

	UTestbed2ManyParamInterfaceOLinkClient* Instance = Cast<UTestbed2ManyParamInterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2ManyParamInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterface(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using local service backend"));
	}

	UTestbed2ManyParamInterface* Instance = Cast<UTestbed2ManyParamInterface>(Collection.InitializeDependency(UTestbed2ManyParamInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2ManyParamInterfaceOLink(Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2ManyParamInterface(Collection);
	default:
		return createTestbed2ManyParamInterface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct1InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct1InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1InterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1Interface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct1Interface* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1Interface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct1Interface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct1Interface>(GameInstance);
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
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2NestedStruct1Interface(GameInstance, Collection);
	default:
		return createTestbed2NestedStruct1Interface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct1InterfaceOLinkClient* Instance = Cast<UTestbed2NestedStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct1InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1Interface(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct1Interface* Instance = Cast<UTestbed2NestedStruct1Interface>(Collection.InitializeDependency(UTestbed2NestedStruct1Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NestedStruct1InterfaceOLink(Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2NestedStruct1Interface(Collection);
	default:
		return createTestbed2NestedStruct1Interface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct2InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct2InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2InterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2Interface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct2Interface* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2Interface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct2Interface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct2Interface>(GameInstance);
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
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2NestedStruct2Interface(GameInstance, Collection);
	default:
		return createTestbed2NestedStruct2Interface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct2InterfaceOLinkClient* Instance = Cast<UTestbed2NestedStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct2InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2Interface(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct2Interface* Instance = Cast<UTestbed2NestedStruct2Interface>(Collection.InitializeDependency(UTestbed2NestedStruct2Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NestedStruct2InterfaceOLink(Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2NestedStruct2Interface(Collection);
	default:
		return createTestbed2NestedStruct2Interface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct3InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct3InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3InterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3Interface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct3Interface* Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3Interface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTestbed2NestedStruct3Interface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTestbed2NestedStruct3Interface>(GameInstance);
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
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2NestedStruct3Interface(GameInstance, Collection);
	default:
		return createTestbed2NestedStruct3Interface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct3InterfaceOLinkClient* Instance = Cast<UTestbed2NestedStruct3InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct3InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3Interface(FSubsystemCollectionBase& Collection)
{
	if (IsLogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct3Interface* Instance = Cast<UTestbed2NestedStruct3Interface>(Collection.InitializeDependency(UTestbed2NestedStruct3Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		return createTestbed2NestedStruct3InterfaceOLink(Collection);
	case ETestbed2Connection::CONNECTION_LOCAL:
		return createTestbed2NestedStruct3Interface(Collection);
	default:
		return createTestbed2NestedStruct3Interface(Collection);
	}
}
#endif
