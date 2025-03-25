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

#include "TbRefIfaces/Generated/TbRefIfacesFactory.h"
#include "TbRefIfacesSettings.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/GameInstance.h"

TMap<FString, FTbRefIfacesModuleFactory::FTbRefIfacesSimpleLocalIfFactoryFunction> FTbRefIfacesModuleFactory::TbRefIfacesSimpleLocalIfFactories{};
TMap<FString, FTbRefIfacesModuleFactory::FTbRefIfacesParentIfFactoryFunction> FTbRefIfacesModuleFactory::TbRefIfacesParentIfFactories{};

// General Log
DEFINE_LOG_CATEGORY(LogFTbRefIfacesModuleFactory);

bool FTbRefIfacesModuleFactory::RegisterFactory(FString TypeIdentifier, FTbRefIfacesSimpleLocalIfFactoryFunction FactoryFunction)
{
	if (TbRefIfacesSimpleLocalIfFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbRefIfacesModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbRefIfacesSimpleLocalIfFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> FTbRefIfacesModuleFactory::GetTbRefIfacesSimpleLocalIfImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbRefIfacesSimpleLocalIfFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbRefIfacesSimpleLocalIfFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}

bool FTbRefIfacesModuleFactory::RegisterFactory(FString TypeIdentifier, FTbRefIfacesParentIfFactoryFunction FactoryFunction)
{
	if (TbRefIfacesParentIfFactories.Contains(TypeIdentifier))
	{
		UE_LOG(LogFTbRefIfacesModuleFactory, Warning, TEXT("Register connection factory: %s - already registered"), *TypeIdentifier);
		return false;
	}

	TbRefIfacesParentIfFactories.Add(TypeIdentifier, FactoryFunction);

	return true;
}

TScriptInterface<ITbRefIfacesParentIfInterface> FTbRefIfacesModuleFactory::GetTbRefIfacesParentIfImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection)
{
	if (TbRefIfacesParentIfFactories.Contains(UniqueImplementationIdentifier))
	{
		return TbRefIfacesParentIfFactories[UniqueImplementationIdentifier](Collection);
	}

	return nullptr;
}
