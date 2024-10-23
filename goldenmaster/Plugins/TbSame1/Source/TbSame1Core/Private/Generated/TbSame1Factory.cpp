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
#include "TbSame1Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbSame1ModuleFactory::FTbSame1SameStruct1InterfaceFactoryFunction> FTbSame1ModuleFactory::TbSame1SameStruct1InterfaceFactories{};
TMap<FString, FTbSame1ModuleFactory::FTbSame1SameStruct2InterfaceFactoryFunction> FTbSame1ModuleFactory::TbSame1SameStruct2InterfaceFactories{};
TMap<FString, FTbSame1ModuleFactory::FTbSame1SameEnum1InterfaceFactoryFunction> FTbSame1ModuleFactory::TbSame1SameEnum1InterfaceFactories{};
TMap<FString, FTbSame1ModuleFactory::FTbSame1SameEnum2InterfaceFactoryFunction> FTbSame1ModuleFactory::TbSame1SameEnum2InterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame1ModuleFactory);

bool FTbSame1ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame1SameStruct1InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame1SameStruct1InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame1ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame1SameStruct1InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1ModuleFactory::GetTbSame1SameStruct1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame1SameStruct1InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame1SameStruct1InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSame1ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame1SameStruct2InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame1SameStruct2InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame1ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame1SameStruct2InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1ModuleFactory::GetTbSame1SameStruct2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame1SameStruct2InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame1SameStruct2InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSame1ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame1SameEnum1InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame1SameEnum1InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame1ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame1SameEnum1InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame1SameEnum1InterfaceInterface> FTbSame1ModuleFactory::GetTbSame1SameEnum1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame1SameEnum1InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame1SameEnum1InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSame1ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame1SameEnum2InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame1SameEnum2InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame1ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame1SameEnum2InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1ModuleFactory::GetTbSame1SameEnum2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame1SameEnum2InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame1SameEnum2InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
