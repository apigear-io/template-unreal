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

#include "TbEnumFactory.h"
#include "Implementation/TbEnumEnumInterface.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "TbEnumSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbEnumModuleFactory);

#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
TScriptInterface<ITbEnumEnumInterfaceInterface> createTbEnumEnumInterfaceOLink(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using OLink service backend"));

	UTbEnumEnumInterfaceOLinkClient* Instance = GameInstance->GetSubsystem<UTbEnumEnumInterfaceOLinkClient>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbEnumEnumInterfaceOLinkClient::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbEnumEnumInterfaceOLinkClient>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> createTbEnumEnumInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using local service backend"));

	UTbEnumEnumInterface* Instance = GameInstance->GetSubsystem<UTbEnumEnumInterface>(GameInstance);
	if (!Instance)
	{
		Collection.InitializeDependency(UTbEnumEnumInterface::StaticClass());
		Instance = GameInstance->GetSubsystem<UTbEnumEnumInterface>(GameInstance);
	}

	return Instance;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection)
{
	UTbEnumSettings* settings = GetMutableDefault<UTbEnumSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbEnumConnection::CONNECTION_OLINK:
		return createTbEnumEnumInterfaceOLink(GameInstance, Collection);
	case ETbEnumConnection::CONNECTION_LOCAL:
		return createTbEnumEnumInterface(GameInstance, Collection);
	default:
		return createTbEnumEnumInterface(GameInstance, Collection);
	}
}

#else

TScriptInterface<ITbEnumEnumInterfaceInterface> createTbEnumEnumInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using OLink service backend"));
	UTbEnumEnumInterfaceOLinkClient* Instance = Cast<UTbEnumEnumInterfaceOLinkClient>(Collection.InitializeDependency(UTbEnumEnumInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> createTbEnumEnumInterface(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogFTbEnumModuleFactory, Log, TEXT("createITbEnumEnumInterfaceInterface: Using local service backend"));
	UTbEnumEnumInterface* Instance = Cast<UTbEnumEnumInterface>(Collection.InitializeDependency(UTbEnumEnumInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumModuleFactory::createITbEnumEnumInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbEnumSettings* settings = GetMutableDefault<UTbEnumSettings>();

	switch (settings->ServiceConnection)
	{
	case ETbEnumConnection::CONNECTION_OLINK:
		return createTbEnumEnumInterfaceOLink(Collection);
	case ETbEnumConnection::CONNECTION_LOCAL:
		return createTbEnumEnumInterface(Collection);
	default:
		return createTbEnumEnumInterface(Collection);
	}
}
#endif
