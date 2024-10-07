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

#include "Generated/TbSame1Factory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "TbSame1Settings.h"
#include "Implementation/TbSame1SameStruct1Interface.h"
#include "Generated/OLink/TbSame1SameStruct1InterfaceOLinkClient.h"
#include "Implementation/TbSame1SameStruct2Interface.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkClient.h"
#include "Implementation/TbSame1SameEnum1Interface.h"
#include "Generated/OLink/TbSame1SameEnum1InterfaceOLinkClient.h"
#include "Implementation/TbSame1SameEnum2Interface.h"
#include "Generated/OLink/TbSame1SameEnum2InterfaceOLinkClient.h"
#include "TbSame1Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame1ModuleFactory);

namespace
{
bool IsTbSame1LogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> createTbSame1SameStruct1InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using OLink service backend"));
	}

	UTbSame1SameStruct1InterfaceOLinkClient* Instance = Cast<UTbSame1SameStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameStruct1InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> createTbSame1SameStruct1Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct1InterfaceInterface: Using local service backend"));
	}

	UTbSame1SameStruct1Interface* Instance = Cast<UTbSame1SameStruct1Interface>(Collection.InitializeDependency(UTbSame1SameStruct1Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameStruct1InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return createTbSame1SameStruct1Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame1Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame1SameStruct1InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame1SameStruct1InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame1SameStruct1Interface(Collection);
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> createTbSame1SameStruct2InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using OLink service backend"));
	}

	UTbSame1SameStruct2InterfaceOLinkClient* Instance = Cast<UTbSame1SameStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameStruct2InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> createTbSame1SameStruct2Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameStruct2InterfaceInterface: Using local service backend"));
	}

	UTbSame1SameStruct2Interface* Instance = Cast<UTbSame1SameStruct2Interface>(Collection.InitializeDependency(UTbSame1SameStruct2Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameStruct2InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return createTbSame1SameStruct2Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame1Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame1SameStruct2InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame1SameStruct2InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame1SameStruct2Interface(Collection);
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> createTbSame1SameEnum1InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using OLink service backend"));
	}

	UTbSame1SameEnum1InterfaceOLinkClient* Instance = Cast<UTbSame1SameEnum1InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameEnum1InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> createTbSame1SameEnum1Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum1InterfaceInterface: Using local service backend"));
	}

	UTbSame1SameEnum1Interface* Instance = Cast<UTbSame1SameEnum1Interface>(Collection.InitializeDependency(UTbSame1SameEnum1Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameEnum1InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return createTbSame1SameEnum1Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame1Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame1SameEnum1InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame1SameEnum1InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame1SameEnum1Interface(Collection);
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> createTbSame1SameEnum2InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using OLink service backend"));
	}

	UTbSame1SameEnum2InterfaceOLinkClient* Instance = Cast<UTbSame1SameEnum2InterfaceOLinkClient>(Collection.InitializeDependency(UTbSame1SameEnum2InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> createTbSame1SameEnum2Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTbSame1LogEnabled())
	{
		UE_LOG(LogFTbSame1ModuleFactory, Log, TEXT("createITbSame1SameEnum2InterfaceInterface: Using local service backend"));
	}

	UTbSame1SameEnum2Interface* Instance = Cast<UTbSame1SameEnum2Interface>(Collection.InitializeDependency(UTbSame1SameEnum2Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1ModuleFactory::createITbSame1SameEnum2InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTbSame1Settings* TbSame1Settings = GetMutableDefault<UTbSame1Settings>();

	if (TbSame1Settings->TracerServiceIdentifier == TbSame1LocalBackendIdentifier)
	{
		return createTbSame1SameEnum2Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(TbSame1Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTbSame1SameEnum2InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTbSame1SameEnum2InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTbSame1SameEnum2Interface(Collection);
}
