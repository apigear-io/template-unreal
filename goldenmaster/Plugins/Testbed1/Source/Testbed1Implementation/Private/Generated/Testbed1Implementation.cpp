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

#include "Testbed1/Testbed1Implementation.h"
#include "Testbed1/Generated/Testbed1Factory.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Engine/Engine.h"
#include "Testbed1Settings.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "Testbed1Implementation"

void FTestbed1ImplementationModule::StartupModule()
{
	FTestbed1ModuleFactory::RegisterFactory(Testbed1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed1StructInterfaceInterface>
		{
		return Cast<UTestbed1StructInterface>(Collection.InitializeDependency(UTestbed1StructInterface::StaticClass()));
	});
	FTestbed1ModuleFactory::RegisterFactory(Testbed1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed1StructArrayInterfaceInterface>
		{
		return Cast<UTestbed1StructArrayInterface>(Collection.InitializeDependency(UTestbed1StructArrayInterface::StaticClass()));
	});
	FTestbed1ModuleFactory::RegisterFactory(Testbed1LocalBackendIdentifier, [](FSubsystemCollectionBase& Collection) -> TScriptInterface<ITestbed1StructArray2InterfaceInterface>
		{
		return Cast<UTestbed1StructArray2Interface>(Collection.InitializeDependency(UTestbed1StructArray2Interface::StaticClass()));
	});
}

void FTestbed1ImplementationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

IMPLEMENT_MODULE(FTestbed1ImplementationModule, Testbed1Implementation)

#undef LOCTEXT_NAMESPACE
