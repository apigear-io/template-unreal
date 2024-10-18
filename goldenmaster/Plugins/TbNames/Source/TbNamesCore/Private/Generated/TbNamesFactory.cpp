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

#include "TbNames/Generated/TbNamesFactory.h"
#include "TbNamesSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbNamesModuleFactory::FTbNamesNamEsFactoryFunction> FTbNamesModuleFactory::TbNamesNamEsFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbNamesModuleFactory);

bool FTbNamesModuleFactory::RegisterFactory(FString TypeIdentifier, FTbNamesNamEsFactoryFunction FactoryFunction)
{
	if (TbNamesNamEsFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbNamesModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbNamesNamEsFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesModuleFactory::GetTbNamesNamEsImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbNamesNamEsFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbNamesNamEsFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
