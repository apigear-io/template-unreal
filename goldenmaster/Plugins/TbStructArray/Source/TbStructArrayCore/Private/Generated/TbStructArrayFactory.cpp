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

#include "TbStructArray/Generated/TbStructArrayFactory.h"
#include "TbStructArraySettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbStructArrayModuleFactory::FTbStructArrayStructArrayFieldInterfaceFactoryFunction> FTbStructArrayModuleFactory::TbStructArrayStructArrayFieldInterfaceFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbStructArrayModuleFactory);

bool FTbStructArrayModuleFactory::RegisterFactory(FString TypeIdentifier, FTbStructArrayStructArrayFieldInterfaceFactoryFunction FactoryFunction)
{
	if (TbStructArrayStructArrayFieldInterfaceFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbStructArrayModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbStructArrayStructArrayFieldInterfaceFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> FTbStructArrayModuleFactory::GetTbStructArrayStructArrayFieldInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbStructArrayStructArrayFieldInterfaceFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbStructArrayStructArrayFieldInterfaceFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
