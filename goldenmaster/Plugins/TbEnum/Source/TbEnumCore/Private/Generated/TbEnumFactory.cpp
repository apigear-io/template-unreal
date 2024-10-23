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

#include "Generated/TbEnumFactory.h"
#include "TbEnumSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbEnumModuleFactory::FTbEnumEnumInterfaceFactoryFunction> FTbEnumModuleFactory::TbEnumEnumInterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbEnumModuleFactory);

bool FTbEnumModuleFactory::RegisterFactory(FString TypeIdentifier, FTbEnumEnumInterfaceFactoryFunction FactoryFunction)
{
	if (TbEnumEnumInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbEnumModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbEnumEnumInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumModuleFactory::GetTbEnumEnumInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbEnumEnumInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbEnumEnumInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
