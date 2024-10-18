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

#include "Testbed2/Testbed2Implementation.h"
#include "Testbed2/Generated/Testbed2Factory.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct1Interface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"
#include "Engine/Engine.h"
#include "Testbed2Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "Testbed2Implementation"

void FTestbed2ImplementationModule::StartupModule()
{
	FTestbed2ModuleFactory::RegisterFactory(Testbed2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2ManyParamInterfaceInterface>
		{
		return Cast<UTestbed2ManyParamInterface>(Collection.InitializeDependency(UTestbed2ManyParamInterface::StaticClass()));
	});
	FTestbed2ModuleFactory::RegisterFactory(Testbed2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2NestedStruct1InterfaceInterface>
		{
		return Cast<UTestbed2NestedStruct1Interface>(Collection.InitializeDependency(UTestbed2NestedStruct1Interface::StaticClass()));
	});
	FTestbed2ModuleFactory::RegisterFactory(Testbed2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2NestedStruct2InterfaceInterface>
		{
		return Cast<UTestbed2NestedStruct2Interface>(Collection.InitializeDependency(UTestbed2NestedStruct2Interface::StaticClass()));
	});
	FTestbed2ModuleFactory::RegisterFactory(Testbed2LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed2NestedStruct3InterfaceInterface>
		{
		return Cast<UTestbed2NestedStruct3Interface>(Collection.InitializeDependency(UTestbed2NestedStruct3Interface::StaticClass()));
	});
}

void FTestbed2ImplementationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTestbed2ImplementationModule, Testbed2Implementation)

#undef LOCTEXT_NAMESPACE
