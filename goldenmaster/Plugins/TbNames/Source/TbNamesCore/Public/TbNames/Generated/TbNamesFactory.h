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
#pragma once

#include "Logging/LogMacros.h"
#include "UObject/ScriptInterface.h"
#include "Runtime/Launch/Resources/Version.h"

class UGameInstance;
class FSubsystemCollectionBase;
class ITbNamesNamEsInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbNamesModuleFactory, Log, All);

class TBNAMESCORE_API FTbNamesModuleFactory
{
public:
	/** type of function for creating implementations*/
	using FTbNamesNamEsFactoryFunction = TFunction<TScriptInterface<ITbNamesNamEsInterface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTbNamesNamEsFactoryFunction FactoryFunction);
	static TScriptInterface<ITbNamesNamEsInterface> GetTbNamesNamEsImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTbNamesModuleFactory::FTbNamesNamEsFactoryFunction> TbNamesNamEsFactories;
};
