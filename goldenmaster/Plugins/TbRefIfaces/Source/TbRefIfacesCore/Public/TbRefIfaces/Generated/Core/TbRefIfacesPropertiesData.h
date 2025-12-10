
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
#include "TbIfaceimport/Generated/api/TbIfaceimportEmptyIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfacesSimpleLocalIfInterface.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBREFIFACESCORE_API TbRefIfacesSimpleLocalIfPropertiesData
{
public:
	std::atomic<int32> IntProperty{0};

private:
};

/**
	\brief data structure to hold interface property values

	This can be used for caching, e.g. last sent value over the network.

	Simple atomic types are directly exposed for read, write.
	All other properties expose setter, getter functions to wrap thread-safety functionality.
*/
class TBREFIFACESCORE_API TbRefIfacesParentIfPropertiesData
{
public:
	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const;
	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList);
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const;
	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const;
	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList);
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const;

private:
	mutable FCriticalSection LocalIfCS;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIf{TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>()};
	mutable FCriticalSection LocalIfListCS;
	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfList{TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>()};
	mutable FCriticalSection ImportedIfCS;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIf{TScriptInterface<ITbIfaceimportEmptyIfInterface>()};
	mutable FCriticalSection ImportedIfListCS;
	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfList{TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>()};
};
