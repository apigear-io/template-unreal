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

#include "Generated/Testbed2Factory.h"
#include "ApiGearSettings.h"
#include "ApiGearOLink.h"
#include "Testbed2Settings.h"
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
bool IsTestbed2LogEnabled()
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();
	return settings->Tracer_EnableDebugLog;
}
} // namespace

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using OLink service backend"));
	}

	UTestbed2ManyParamInterfaceOLinkClient* Instance = Cast<UTestbed2ManyParamInterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2ManyParamInterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> createTestbed2ManyParamInterface(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using local service backend"));
	}

	UTestbed2ManyParamInterface* Instance = Cast<UTestbed2ManyParamInterface>(Collection.InitializeDependency(UTestbed2ManyParamInterface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* Testbed2Settings = GetMutableDefault<UTestbed2Settings>();

	if (Testbed2Settings->TracerServiceIdentifier == Testbed2LocalBackendIdentifier)
	{
		return createTestbed2ManyParamInterface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(Testbed2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTestbed2ManyParamInterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTestbed2ManyParamInterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTestbed2ManyParamInterface(Collection);
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct1InterfaceOLinkClient* Instance = Cast<UTestbed2NestedStruct1InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct1InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> createTestbed2NestedStruct1Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct1Interface* Instance = Cast<UTestbed2NestedStruct1Interface>(Collection.InitializeDependency(UTestbed2NestedStruct1Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* Testbed2Settings = GetMutableDefault<UTestbed2Settings>();

	if (Testbed2Settings->TracerServiceIdentifier == Testbed2LocalBackendIdentifier)
	{
		return createTestbed2NestedStruct1Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(Testbed2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTestbed2NestedStruct1InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTestbed2NestedStruct1InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTestbed2NestedStruct1Interface(Collection);
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct2InterfaceOLinkClient* Instance = Cast<UTestbed2NestedStruct2InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct2InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> createTestbed2NestedStruct2Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct2Interface* Instance = Cast<UTestbed2NestedStruct2Interface>(Collection.InitializeDependency(UTestbed2NestedStruct2Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* Testbed2Settings = GetMutableDefault<UTestbed2Settings>();

	if (Testbed2Settings->TracerServiceIdentifier == Testbed2LocalBackendIdentifier)
	{
		return createTestbed2NestedStruct2Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(Testbed2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTestbed2NestedStruct2InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTestbed2NestedStruct2InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTestbed2NestedStruct2Interface(Collection);
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3InterfaceOLink(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using OLink service backend"));
	}

	UTestbed2NestedStruct3InterfaceOLinkClient* Instance = Cast<UTestbed2NestedStruct3InterfaceOLinkClient>(Collection.InitializeDependency(UTestbed2NestedStruct3InterfaceOLinkClient::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> createTestbed2NestedStruct3Interface(FSubsystemCollectionBase& Collection)
{
	if (IsTestbed2LogEnabled())
	{
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using local service backend"));
	}

	UTestbed2NestedStruct3Interface* Instance = Cast<UTestbed2NestedStruct3Interface>(Collection.InitializeDependency(UTestbed2NestedStruct3Interface::StaticClass()));
	return Instance;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface(FSubsystemCollectionBase& Collection)
{
	UTestbed2Settings* Testbed2Settings = GetMutableDefault<UTestbed2Settings>();

	if (Testbed2Settings->TracerServiceIdentifier == Testbed2LocalBackendIdentifier)
	{
		return createTestbed2NestedStruct3Interface(Collection);
	}

	UApiGearSettings* ApiGearSettings = GetMutableDefault<UApiGearSettings>();
	FApiGearConnectionSetting* ConnectionSetting = ApiGearSettings->Connections.Find(Testbed2Settings->TracerServiceIdentifier);

	// Other protocols not supported. To support it edit templates:
	// add protocol handler class for this interface like createTestbed2NestedStruct3InterfaceOLink and other necessary infrastructure
	// extend this function in templates to handle protocol of your choice
	if (ConnectionSetting && ConnectionSetting->ProtocolIdentifier == ApiGearOLinkProtocolIdentifier)
	{
		return createTestbed2NestedStruct3InterfaceOLink(Collection);
	}

	// fallback to local implementation
	return createTestbed2NestedStruct3Interface(Collection);
}
