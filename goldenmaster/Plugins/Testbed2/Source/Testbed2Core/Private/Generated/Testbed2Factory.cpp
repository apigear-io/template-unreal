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
#include "Testbed2Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTestbed2ModuleFactory::FTestbed2ManyParamInterfaceFactoryFunction> FTestbed2ModuleFactory::Testbed2ManyParamInterfaceFactories{};
TMap<FString, FTestbed2ModuleFactory::FTestbed2NestedStruct1InterfaceFactoryFunction> FTestbed2ModuleFactory::Testbed2NestedStruct1InterfaceFactories{};
TMap<FString, FTestbed2ModuleFactory::FTestbed2NestedStruct2InterfaceFactoryFunction> FTestbed2ModuleFactory::Testbed2NestedStruct2InterfaceFactories{};
TMap<FString, FTestbed2ModuleFactory::FTestbed2NestedStruct3InterfaceFactoryFunction> FTestbed2ModuleFactory::Testbed2NestedStruct3InterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTestbed2ModuleFactory);

bool FTestbed2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTestbed2ManyParamInterfaceFactoryFunction FactoryFunction)
{
	if (Testbed2ManyParamInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTestbed2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	Testbed2ManyParamInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ModuleFactory::GetTestbed2ManyParamInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (Testbed2ManyParamInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return Testbed2ManyParamInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTestbed2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTestbed2NestedStruct1InterfaceFactoryFunction FactoryFunction)
{
	if (Testbed2NestedStruct1InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTestbed2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	Testbed2NestedStruct1InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2ModuleFactory::GetTestbed2NestedStruct1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (Testbed2NestedStruct1InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return Testbed2NestedStruct1InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTestbed2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTestbed2NestedStruct2InterfaceFactoryFunction FactoryFunction)
{
	if (Testbed2NestedStruct2InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTestbed2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	Testbed2NestedStruct2InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2ModuleFactory::GetTestbed2NestedStruct2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (Testbed2NestedStruct2InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return Testbed2NestedStruct2InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTestbed2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTestbed2NestedStruct3InterfaceFactoryFunction FactoryFunction)
{
	if (Testbed2NestedStruct3InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTestbed2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	Testbed2NestedStruct3InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2ModuleFactory::GetTestbed2NestedStruct3InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (Testbed2NestedStruct3InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return Testbed2NestedStruct3InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
