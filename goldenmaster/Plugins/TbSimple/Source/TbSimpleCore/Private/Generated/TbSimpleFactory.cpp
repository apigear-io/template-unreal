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

#include "TbSimple/Generated/TbSimpleFactory.h"
#include "TbSimpleSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbSimpleModuleFactory::FTbSimpleVoidInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleVoidInterfaceFactories{};
TMap<FString, FTbSimpleModuleFactory::FTbSimpleSimpleInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleSimpleInterfaceFactories{};
TMap<FString, FTbSimpleModuleFactory::FTbSimpleSimpleArrayInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleSimpleArrayInterfaceFactories{};
TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoPropertiesInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleNoPropertiesInterfaceFactories{};
TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoOperationsInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleNoOperationsInterfaceFactories{};
TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoSignalsInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleNoSignalsInterfaceFactories{};
TMap<FString, FTbSimpleModuleFactory::FTbSimpleEmptyInterfaceFactoryFunction> FTbSimpleModuleFactory::TbSimpleEmptyInterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbSimpleModuleFactory);

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleVoidInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleVoidInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleVoidInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleVoidInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleVoidInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleVoidInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleSimpleInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleSimpleInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleSimpleInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleSimpleInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleSimpleInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleSimpleInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleSimpleArrayInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleSimpleArrayInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleSimpleArrayInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleSimpleArrayInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleSimpleArrayInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleSimpleArrayInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleNoPropertiesInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleNoPropertiesInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleNoPropertiesInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleNoPropertiesInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleNoPropertiesInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleNoPropertiesInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleNoOperationsInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleNoOperationsInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleNoOperationsInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleNoOperationsInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleNoOperationsInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleNoOperationsInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleNoSignalsInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleNoSignalsInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleNoSignalsInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleNoSignalsInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleNoSignalsInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleNoSignalsInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbSimpleModuleFactory::RegisterFactory(FString TypeIdentifier, FTbSimpleEmptyInterfaceFactoryFunction FactoryFunction)
{
	if (TbSimpleEmptyInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbSimpleModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbSimpleEmptyInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleModuleFactory::GetTbSimpleEmptyInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbSimpleEmptyInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbSimpleEmptyInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
