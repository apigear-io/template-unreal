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

class FTbSimpleModuleFactory
{
public:
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	static TScriptInterface<ITbSimpleVoidInterfaceInterface> createITbSimpleVoidInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleInterfaceInterface> createITbSimpleSimpleInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createITbSimpleSimpleArrayInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> createITbSimpleNoPropertiesInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> createITbSimpleNoOperationsInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> createITbSimpleNoSignalsInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleEmptyInterfaceInterface> createITbSimpleEmptyInterfaceInterface(UGameInstance* GameInstance, FSubsystemCollectionBase& Collection);
#else
	static TScriptInterface<ITbSimpleVoidInterfaceInterface> createITbSimpleVoidInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleInterfaceInterface> createITbSimpleSimpleInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> createITbSimpleSimpleArrayInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> createITbSimpleNoPropertiesInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> createITbSimpleNoOperationsInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> createITbSimpleNoSignalsInterfaceInterface(FSubsystemCollectionBase& Collection);
	static TScriptInterface<ITbSimpleEmptyInterfaceInterface> createITbSimpleEmptyInterfaceInterface(FSubsystemCollectionBase& Collection);
#endif
};
