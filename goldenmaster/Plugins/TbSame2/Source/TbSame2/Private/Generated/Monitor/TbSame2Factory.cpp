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

#include "TbSame2Factory.h"
#include "Implementation/TbSame2SameStruct1Interface.h"
#include "Generated/OLink/TbSame2SameStruct1InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameStruct2Interface.h"
#include "Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameEnum1Interface.h"
#include "Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "Implementation/TbSame2SameEnum2Interface.h"
#include "Generated/OLink/TbSame2SameEnum2InterfaceOLinkClient.h"
#include "TbSame2Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame2ModuleFactory);

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> createTbSame2SameStruct1InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using OLink service backend"));
	UTbSame2SameStruct1InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame2SameStruct1InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame2SameStruct1InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame2SameStruct1InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameStruct1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		return createTbSame2SameStruct1InterfaceOLink(GameInstance, Collection);
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameStruct1Interface>();
	}
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> createTbSame2SameStruct2InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using OLink service backend"));
	UTbSame2SameStruct2InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame2SameStruct2InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame2SameStruct2InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameStruct2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		return createTbSame2SameStruct2InterfaceOLink(GameInstance, Collection);
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameStruct2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameStruct2Interface>();
	}
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> createTbSame2SameEnum1InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using OLink service backend"));
	UTbSame2SameEnum1InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame2SameEnum1InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame2SameEnum1InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameEnum1InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		return createTbSame2SameEnum1InterfaceOLink(GameInstance, Collection);
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameEnum1Interface>();
	}
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> createTbSame2SameEnum2InterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using OLink service backend"));
	UTbSame2SameEnum2InterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSame2SameEnum2InterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSame2SameEnum2InterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSame2SameEnum2InterfaceOLinkClient>(GameInstance);
	}
	return Instance;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2ModuleFactory::createITbSame2SameEnum2InterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSame2Settings* settings = GetMutableDefault<UTbSame2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETbSame2Connection::CONNECTION_OLINK:
		return createTbSame2SameEnum2InterfaceOLink(GameInstance, Collection);
	case ETbSame2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTbSame2ModuleFactory, Log, TEXT("createITbSame2SameEnum2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTbSame2SameEnum2Interface>();
	}
}
