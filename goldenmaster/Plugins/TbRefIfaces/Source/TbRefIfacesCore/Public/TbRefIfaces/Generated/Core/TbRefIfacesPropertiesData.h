
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
#include <atomic>
#include "HAL/CriticalSection.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_apig.h"

/**
	\brief data structure to hold the last sent property values
*/
struct TbRefIfacesSimpleLocalIfPropertiesData
{
	std::atomic<int32> IntProperty{0};
};

/**
	\brief data structure to hold the last sent property values
*/
struct TbRefIfacesParentIfPropertiesData
{
	FCriticalSection LocalIfMutex;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIf{TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>()};
	FCriticalSection LocalIfListMutex;
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfList{TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>()};
	FCriticalSection ImportedIfMutex;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf{TScriptInterface<ITbIfaceimportEmptyIfInterface>()};
	FCriticalSection ImportedIfListMutex;
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfList{TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>()};
};
