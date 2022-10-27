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

#include "Testbed1Factory.h"
#include "Implementation/Testbed1StructInterface.h"
#include "Generated/OLink/Testbed1StructInterfaceOLink.h"
#include "Generated/Simulation/Testbed1StructInterfaceSimulation.h"
#include "Implementation/Testbed1StructArrayInterface.h"
#include "Generated/OLink/Testbed1StructArrayInterfaceOLink.h"
#include "Generated/Simulation/Testbed1StructArrayInterfaceSimulation.h"
#include "Testbed1Settings.h"

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed1ModuleFactory);

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1ModuleFactory::createITestbed1StructInterfaceInterface()
{
	UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed1Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed1StructInterfaceOLinkService>();
	case ETestbed1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed1StructInterfaceSimulationService>();
	case ETestbed1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed1StructInterface>();
	}
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1ModuleFactory::createITestbed1StructArrayInterfaceInterface()
{
	UTestbed1Settings* settings = GetMutableDefault<UTestbed1Settings>();

	switch (settings->ServiceConnection)
	{
	case ETestbed1Connection::CONNECTION_OLINK:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using OLink service backend"));
		return NewObject<UTestbed1StructArrayInterfaceOLinkService>();
	case ETestbed1Connection::CONNECTION_SIMU:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using simulation service backend"));
		return NewObject<UTestbed1StructArrayInterfaceSimulationService>();
	case ETestbed1Connection::CONNECTION_LOCAL:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Using local service backend"));
	default:
		UE_LOG(LogFTestbed1ModuleFactory, Log, TEXT("createITestbed1StructArrayInterfaceInterface: Defaulting to local service backend"));
		return NewObject<UTestbed1StructArrayInterface>();
	}
}
