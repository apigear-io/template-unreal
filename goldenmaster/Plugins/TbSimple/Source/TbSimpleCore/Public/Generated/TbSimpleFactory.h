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
class ITbSimpleVoidInterfaceInterface;
class ITbSimpleSimpleInterfaceInterface;
class ITbSimpleSimpleArrayInterfaceInterface;
class ITbSimpleNoPropertiesInterfaceInterface;
class ITbSimpleNoOperationsInterfaceInterface;
class ITbSimpleNoSignalsInterfaceInterface;
class ITbSimpleEmptyInterfaceInterface;

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogFTbSimpleModuleFactory, Log, All);

class TBSIMPLECORE_API FTbSimpleModuleFactory
{
public:
	/** type of function for creating implementations*/
	using FTbSimpleVoidInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleVoidInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleSimpleInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleSimpleInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleSimpleArrayInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleNoPropertiesInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleNoOperationsInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleNoOperationsInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleNoSignalsInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleNoSignalsInterfaceInterface>(FSubsystemCollectionBase& Collection)>;
	using FTbSimpleEmptyInterfaceFactoryFunction = TFunction<TScriptInterface<ITbSimpleEmptyInterfaceInterface>(FSubsystemCollectionBase& Collection)>;

	/** register factories for different types of implementations and interfaces */
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleVoidInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleSimpleInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleSimpleArrayInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleNoPropertiesInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleNoOperationsInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleNoSignalsInterfaceFactoryFunction FactoryFunction);
	static bool RegisterFactory(FString TypeIdentifier, FTbSimpleEmptyInterfaceFactoryFunction FactoryFunction);
	static TScriptInterface<ITbSimpleVoidInterfaceInterface> GetTbSimpleVoidInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetTbSimpleSimpleInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetTbSimpleSimpleArrayInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetTbSimpleNoPropertiesInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetTbSimpleNoOperationsInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetTbSimpleNoSignalsInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetTbSimpleEmptyInterfaceImplementation(FString UniqueImplementationIdentifier, FSubsystemCollectionBase& Collection);

private:
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleVoidInterfaceFactoryFunction> TbSimpleVoidInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleSimpleInterfaceFactoryFunction> TbSimpleSimpleInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleSimpleArrayInterfaceFactoryFunction> TbSimpleSimpleArrayInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoPropertiesInterfaceFactoryFunction> TbSimpleNoPropertiesInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoOperationsInterfaceFactoryFunction> TbSimpleNoOperationsInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleNoSignalsInterfaceFactoryFunction> TbSimpleNoSignalsInterfaceFactories;
	static TMap<FString, FTbSimpleModuleFactory::FTbSimpleEmptyInterfaceFactoryFunction> TbSimpleEmptyInterfaceFactories;
};
