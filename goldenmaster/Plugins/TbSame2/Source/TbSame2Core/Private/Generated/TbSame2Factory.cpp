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

#include "Generated/TbSame2Factory.h"
#include "TbSame2Settings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbSame2ModuleFactory::FTbSame2SameStruct1InterfaceFactoryFunction> FTbSame2ModuleFactory::TbSame2SameStruct1InterfaceFactories{};
TMap<FString, FTbSame2ModuleFactory::FTbSame2SameStruct2InterfaceFactoryFunction> FTbSame2ModuleFactory::TbSame2SameStruct2InterfaceFactories{};
TMap<FString, FTbSame2ModuleFactory::FTbSame2SameEnum1InterfaceFactoryFunction> FTbSame2ModuleFactory::TbSame2SameEnum1InterfaceFactories{};
TMap<FString, FTbSame2ModuleFactory::FTbSame2SameEnum2InterfaceFactoryFunction> FTbSame2ModuleFactory::TbSame2SameEnum2InterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbSame2ModuleFactory);

bool FTbSame2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame2SameStruct1InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame2SameStruct1InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame2SameStruct1InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2ModuleFactory::GetTbSame2SameStruct1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame2SameStruct1InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame2SameStruct1InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSame2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame2SameStruct2InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame2SameStruct2InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame2SameStruct2InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2ModuleFactory::GetTbSame2SameStruct2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame2SameStruct2InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame2SameStruct2InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSame2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame2SameEnum1InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame2SameEnum1InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame2SameEnum1InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame2SameEnum1InterfaceInterface> FTbSame2ModuleFactory::GetTbSame2SameEnum1InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame2SameEnum1InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame2SameEnum1InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSame2ModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSame2SameEnum2InterfaceFactoryFunction FactoryFunction)
{
	if (TbSame2SameEnum2InterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSame2ModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSame2SameEnum2InterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2ModuleFactory::GetTbSame2SameEnum2InterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSame2SameEnum2InterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSame2SameEnum2InterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
