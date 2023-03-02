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
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "Implementation/TbSimpleNoOperationsInterface.h"
#include "Generated/OLink/TbSimpleNoOperationsInterfaceOLinkClient.h"
#include "Implementation/TbSimpleNoSignalsInterface.h"
#include "Generated/OLink/TbSimpleNoSignalsInterfaceOLinkClient.h"
#include "Implementation/TbSimpleEmptyInterface.h"
#include "Generated/OLink/TbSimpleEmptyInterfaceOLinkClient.h"
#include "TbSimpleSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSimpleModuleFactory);

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
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

TScriptInterface<ITbSimpleSimpleInterfaceInterface> createTbSimpleSimpleInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using local service backend"));

	UTbSimpleSimpleInterface* Instance = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleSimpleInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleSimpleInterface>(GameInstance);
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
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleSimpleInterface(GameInstance, Collection);
	default:
		return createTbSimpleSimpleInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbSimpleSimpleInterfaceInterface> createTbSimpleSimpleInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using OLink service backend"));
	UTbSimpleSimpleInterfaceOLinkClient* Instance = Cast<UTbSimpleSimpleInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleSimpleInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> createTbSimpleSimpleInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleInterfaceInterface: Using local service backend"));
	UTbSimpleSimpleInterface* Instance = Cast<UTbSimpleSimpleInterface>(Collection.InitializeDependency(UTbSimpleSimpleInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleSimpleInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleSimpleInterfaceOLink(Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleSimpleInterface(Collection);
	default:
		return createTbSimpleSimpleInterface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
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

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createTbSimpleSimpleArrayInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using local service backend"));

	UTbSimpleSimpleArrayInterface* Instance = GameInstance->GetSubsystem<UTbSimpleSimpleArrayInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleSimpleArrayInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleSimpleArrayInterface>(GameInstance);
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
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleSimpleArrayInterface(GameInstance, Collection);
	default:
		return createTbSimpleSimpleArrayInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createTbSimpleSimpleArrayInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using OLink service backend"));
	UTbSimpleSimpleArrayInterfaceOLinkClient* Instance = Cast<UTbSimpleSimpleArrayInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleSimpleArrayInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createTbSimpleSimpleArrayInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleSimpleArrayInterfaceInterface: Using local service backend"));
	UTbSimpleSimpleArrayInterface* Instance = Cast<UTbSimpleSimpleArrayInterface>(Collection.InitializeDependency(UTbSimpleSimpleArrayInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleSimpleArrayInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleSimpleArrayInterfaceOLink(Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleSimpleArrayInterface(Collection);
	default:
		return createTbSimpleSimpleArrayInterface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> createTbSimpleNoPropertiesInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoPropertiesInterfaceInterface: Using OLink service backend"));

	UTbSimpleNoPropertiesInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSimpleNoPropertiesInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleNoPropertiesInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleNoPropertiesInterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> createTbSimpleNoPropertiesInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoPropertiesInterfaceInterface: Using local service backend"));

	UTbSimpleNoPropertiesInterface* Instance = GameInstance->GetSubsystem<UTbSimpleNoPropertiesInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleNoPropertiesInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleNoPropertiesInterface>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleNoPropertiesInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleNoPropertiesInterfaceOLink(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleNoPropertiesInterface(GameInstance, Collection);
	default:
		return createTbSimpleNoPropertiesInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> createTbSimpleNoPropertiesInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoPropertiesInterfaceInterface: Using OLink service backend"));
	UTbSimpleNoPropertiesInterfaceOLinkClient* Instance = Cast<UTbSimpleNoPropertiesInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoPropertiesInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> createTbSimpleNoPropertiesInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoPropertiesInterfaceInterface: Using local service backend"));
	UTbSimpleNoPropertiesInterface* Instance = Cast<UTbSimpleNoPropertiesInterface>(Collection.InitializeDependency(UTbSimpleNoPropertiesInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleNoPropertiesInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleNoPropertiesInterfaceOLink(Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleNoPropertiesInterface(Collection);
	default:
		return createTbSimpleNoPropertiesInterface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> createTbSimpleNoOperationsInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoOperationsInterfaceInterface: Using OLink service backend"));

	UTbSimpleNoOperationsInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleNoOperationsInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleNoOperationsInterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> createTbSimpleNoOperationsInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoOperationsInterfaceInterface: Using local service backend"));

	UTbSimpleNoOperationsInterface* Instance = GameInstance->GetSubsystem<UTbSimpleNoOperationsInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleNoOperationsInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleNoOperationsInterface>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleNoOperationsInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleNoOperationsInterfaceOLink(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleNoOperationsInterface(GameInstance, Collection);
	default:
		return createTbSimpleNoOperationsInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> createTbSimpleNoOperationsInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoOperationsInterfaceInterface: Using OLink service backend"));
	UTbSimpleNoOperationsInterfaceOLinkClient* Instance = Cast<UTbSimpleNoOperationsInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoOperationsInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> createTbSimpleNoOperationsInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoOperationsInterfaceInterface: Using local service backend"));
	UTbSimpleNoOperationsInterface* Instance = Cast<UTbSimpleNoOperationsInterface>(Collection.InitializeDependency(UTbSimpleNoOperationsInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleNoOperationsInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleNoOperationsInterfaceOLink(Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleNoOperationsInterface(Collection);
	default:
		return createTbSimpleNoOperationsInterface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> createTbSimpleNoSignalsInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoSignalsInterfaceInterface: Using OLink service backend"));

	UTbSimpleNoSignalsInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSimpleNoSignalsInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleNoSignalsInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleNoSignalsInterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> createTbSimpleNoSignalsInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoSignalsInterfaceInterface: Using local service backend"));

	UTbSimpleNoSignalsInterface* Instance = GameInstance->GetSubsystem<UTbSimpleNoSignalsInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleNoSignalsInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleNoSignalsInterface>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleNoSignalsInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleNoSignalsInterfaceOLink(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleNoSignalsInterface(GameInstance, Collection);
	default:
		return createTbSimpleNoSignalsInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> createTbSimpleNoSignalsInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoSignalsInterfaceInterface: Using OLink service backend"));
	UTbSimpleNoSignalsInterfaceOLinkClient* Instance = Cast<UTbSimpleNoSignalsInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleNoSignalsInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> createTbSimpleNoSignalsInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleNoSignalsInterfaceInterface: Using local service backend"));
	UTbSimpleNoSignalsInterface* Instance = Cast<UTbSimpleNoSignalsInterface>(Collection.InitializeDependency(UTbSimpleNoSignalsInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleNoSignalsInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleNoSignalsInterfaceOLink(Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleNoSignalsInterface(Collection);
	default:
		return createTbSimpleNoSignalsInterface(Collection);
	}
}
#endif

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITbSimpleEmptyInterfaceInterface> createTbSimpleEmptyInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleEmptyInterfaceInterface: Using OLink service backend"));

	UTbSimpleEmptyInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbSimpleEmptyInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleEmptyInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleEmptyInterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> createTbSimpleEmptyInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleEmptyInterfaceInterface: Using local service backend"));

	UTbSimpleEmptyInterface* Instance = GameInstance->GetSubsystem<UTbSimpleEmptyInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbSimpleEmptyInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbSimpleEmptyInterface>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleEmptyInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleEmptyInterfaceOLink(GameInstance, Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleEmptyInterface(GameInstance, Collection);
	default:
		return createTbSimpleEmptyInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbSimpleEmptyInterfaceInterface> createTbSimpleEmptyInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleEmptyInterfaceInterface: Using OLink service backend"));
	UTbSimpleEmptyInterfaceOLinkClient* Instance = Cast<UTbSimpleEmptyInterfaceOLinkClient>(Collection.InitializeDependency(UTbSimpleEmptyInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> createTbSimpleEmptyInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbSimpleModuleFactory, Log, TEXT("createITbSimpleEmptyInterfaceInterface: Using local service backend"));
	UTbSimpleEmptyInterface* Instance = Cast<UTbSimpleEmptyInterface>(Collection.InitializeDependency(UTbSimpleEmptyInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleModuleFactory::createITbSimpleEmptyInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSimpleSettings* settings = GetMutableDefault<UTbSimpleSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbSimpleConnection::CONNECTION_OLINK:
		return createTbSimpleEmptyInterfaceOLink(Collection);
	case ETbSimpleConnection::CONNECTION_LOCAL:
		return createTbSimpleEmptyInterface(Collection);
	default:
		return createTbSimpleEmptyInterface(Collection);
	}
}
#endif
