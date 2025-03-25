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

#include "TbIfaceimport/Generated/TbIfaceimportFactory.h"
#include "TbIfaceimportSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbIfaceimportModuleFactory::FTbIfaceimportEmptyIfFactoryFunction> FTbIfaceimportModuleFactory::TbIfaceimportEmptyIfFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbIfaceimportModuleFactory);

bool FTbIfaceimportModuleFactory::RegisterFactory(FString TypeIdentifier, FTbIfaceimportEmptyIfFactoryFunction FactoryFunction)
{
	if (TbIfaceimportEmptyIfFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbIfaceimportModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbIfaceimportEmptyIfFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> FTbIfaceimportModuleFactory::GetTbIfaceimportEmptyIfImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbIfaceimportEmptyIfFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbIfaceimportEmptyIfFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
