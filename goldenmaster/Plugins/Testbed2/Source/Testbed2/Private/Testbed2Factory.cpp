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
#include "Generated/OLink/Testbed2ManyParamInterfaceOLink.h"
#include "Generated/Simulation/Testbed2ManyParamInterfaceSimulationClient.h"
#include "Implementation/Testbed2NestedStruct1Interface.h"
#include "Generated/OLink/Testbed2NestedStruct1InterfaceOLink.h"
#include "Generated/Simulation/Testbed2NestedStruct1InterfaceSimulationClient.h"
#include "Implementation/Testbed2NestedStruct2Interface.h"
#include "Generated/OLink/Testbed2NestedStruct2InterfaceOLink.h"
#include "Generated/Simulation/Testbed2NestedStruct2InterfaceSimulationClient.h"
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Generated/OLink/Testbed2NestedStruct3InterfaceOLink.h"
#include "Generated/Simulation/Testbed2NestedStruct3InterfaceSimulationClient.h"
#include "Implementation/Testbed2NoPropertyInterface.h"
#include "Generated/OLink/Testbed2NoPropertyInterfaceOLink.h"
#include "Generated/Simulation/Testbed2NoPropertyInterfaceSimulationClient.h"
#include "Implementation/Testbed2EmptyInterface.h"
#include "Generated/OLink/Testbed2EmptyInterfaceOLink.h"
#include "Generated/Simulation/Testbed2EmptyInterfaceSimulationClient.h"
#include "Testbed2Settings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed2ModuleFactory);

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed2ManyParamInterfaceOLinkService>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed2ManyParamInterfaceSimulationClient>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2ManyParamInterface>();
	}
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed2NestedStruct1InterfaceOLinkService>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed2NestedStruct1InterfaceSimulationClient>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NestedStruct1Interface>();
	}
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed2NestedStruct2InterfaceOLinkService>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed2NestedStruct2InterfaceSimulationClient>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NestedStruct2Interface>();
	}
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed2NestedStruct3InterfaceOLinkService>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed2NestedStruct3InterfaceSimulationClient>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NestedStruct3Interface>();
	}
}

TScriptInterface<ITestbed2NoPropertyInterfaceInterface> FTestbed2ModuleFactory::createITestbed2NoPropertyInterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed2NoPropertyInterfaceOLinkService>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed2NoPropertyInterfaceSimulationClient>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NoPropertyInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2NoPropertyInterface>();
	}
}

TScriptInterface<ITestbed2EmptyInterfaceInterface> FTestbed2ModuleFactory::createITestbed2EmptyInterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed2EmptyInterfaceOLinkService>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed2EmptyInterfaceSimulationClient>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2EmptyInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed2EmptyInterface>();
	}
}
