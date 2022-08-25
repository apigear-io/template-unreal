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
#include "ManyParamInterface/Testbed2ManyParamInterfaceLocal.h"
#include "ManyParamInterface/Testbed2ManyParamInterfaceOLink.h"
#include "ManyParamInterface/Testbed2ManyParamInterfaceSimulation.h"
#include "NestedStruct1Interface/Testbed2NestedStruct1InterfaceLocal.h"
#include "NestedStruct1Interface/Testbed2NestedStruct1InterfaceOLink.h"
#include "NestedStruct1Interface/Testbed2NestedStruct1InterfaceSimulation.h"
#include "NestedStruct2Interface/Testbed2NestedStruct2InterfaceLocal.h"
#include "NestedStruct2Interface/Testbed2NestedStruct2InterfaceOLink.h"
#include "NestedStruct2Interface/Testbed2NestedStruct2InterfaceSimulation.h"
#include "NestedStruct3Interface/Testbed2NestedStruct3InterfaceLocal.h"
#include "NestedStruct3Interface/Testbed2NestedStruct3InterfaceOLink.h"
#include "NestedStruct3Interface/Testbed2NestedStruct3InterfaceSimulation.h"
#include "Testbed2Settings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed2ModuleFactory);

TSharedPtr<ITestbed2ManyParamInterfaceInterface, ESPMode::ThreadSafe> FTestbed2ModuleFactory::createITestbed2ManyParamInterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using OLink service backend"));
		return MakeShared<Testbed2::ManyParamInterface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using simulation service backend"));
		return MakeShared<Testbed2::ManyParamInterface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2ManyParamInterfaceInterface: Defaulting to local service backend"));
		return MakeShared<Testbed2::ManyParamInterface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITestbed2NestedStruct1InterfaceInterface, ESPMode::ThreadSafe> FTestbed2ModuleFactory::createITestbed2NestedStruct1InterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using OLink service backend"));
		return MakeShared<Testbed2::NestedStruct1Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using simulation service backend"));
		return MakeShared<Testbed2::NestedStruct1Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct1InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<Testbed2::NestedStruct1Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITestbed2NestedStruct2InterfaceInterface, ESPMode::ThreadSafe> FTestbed2ModuleFactory::createITestbed2NestedStruct2InterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using OLink service backend"));
		return MakeShared<Testbed2::NestedStruct2Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using simulation service backend"));
		return MakeShared<Testbed2::NestedStruct2Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct2InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<Testbed2::NestedStruct2Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}

TSharedPtr<ITestbed2NestedStruct3InterfaceInterface, ESPMode::ThreadSafe> FTestbed2ModuleFactory::createITestbed2NestedStruct3InterfaceInterface()
{
	UTestbed2Settings* settings = GetMutableDefault<UTestbed2Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed2Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using OLink service backend"));
		return MakeShared<Testbed2::NestedStruct3Interface::Private::OLinkService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using simulation service backend"));
		return MakeShared<Testbed2::NestedStruct3Interface::Private::SimulationService, ESPMode::ThreadSafe>();
	case ETestbed2Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed2ModuleFactory, Log, TEXT("createITestbed2NestedStruct3InterfaceInterface: Defaulting to local service backend"));
		return MakeShared<Testbed2::NestedStruct3Interface::Private::LocalService, ESPMode::ThreadSafe>();
	}
}
