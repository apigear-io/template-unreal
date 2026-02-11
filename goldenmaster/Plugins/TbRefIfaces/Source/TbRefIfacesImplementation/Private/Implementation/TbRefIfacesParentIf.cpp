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

#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "Misc/ScopeRWLock.h"

UTbRefIfacesParentIfImplementation::~UTbRefIfacesParentIfImplementation() = default;
TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::GetLocalIf() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(LocalIfRWLock);
#endif
	return LocalIf;
}

void UTbRefIfacesParentIfImplementation::SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetLocalIf");
	if (LocalIf != InLocalIf)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(LocalIfRWLock);
			LocalIf = InLocalIf;
		}
#else
		LocalIf = InLocalIf;
#endif
		_GetPublisher()->BroadcastLocalIfChanged(LocalIf);
	}
}
TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfImplementation::GetLocalIfList() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(LocalIfListRWLock);
#endif
	return LocalIfList;
}

void UTbRefIfacesParentIfImplementation::SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InLocalIfList)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetLocalIfList");
	if (LocalIfList != InLocalIfList)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(LocalIfListRWLock);
			LocalIfList = InLocalIfList;
		}
#else
		LocalIfList = InLocalIfList;
#endif
		_GetPublisher()->BroadcastLocalIfListChanged(LocalIfList);
	}
}
TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfImplementation::GetImportedIf() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(ImportedIfRWLock);
#endif
	return ImportedIf;
}

void UTbRefIfacesParentIfImplementation::SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetImportedIf");
	if (ImportedIf != InImportedIf)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ImportedIfRWLock);
			ImportedIf = InImportedIf;
		}
#else
		ImportedIf = InImportedIf;
#endif
		_GetPublisher()->BroadcastImportedIfChanged(ImportedIf);
	}
}
TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfImplementation::GetImportedIfList() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(ImportedIfListRWLock);
#endif
	return ImportedIfList;
}

void UTbRefIfacesParentIfImplementation::SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InImportedIfList)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.SetImportedIfList");
	if (ImportedIfList != InImportedIfList)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ImportedIfListRWLock);
			ImportedIfList = InImportedIfList;
		}
#else
		ImportedIfList = InImportedIfList;
#endif
		_GetPublisher()->BroadcastImportedIfListChanged(ImportedIfList);
	}
}

TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> UTbRefIfacesParentIfImplementation::LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.LocalIfMethod");
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
}

TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> UTbRefIfacesParentIfImplementation::LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.LocalIfMethodList");
	(void)Param;
	// do business logic here
	return TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> UTbRefIfacesParentIfImplementation::ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.ImportedIfMethod");
	(void)Param;
	// do business logic here
	return TScriptInterface<ITbIfaceimportEmptyIfInterface>();
}

TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> UTbRefIfacesParentIfImplementation::ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.ParentIf.Impl.ImportedIfMethodList");
	(void)Param;
	// do business logic here
	return TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
}

void UTbRefIfacesParentIfImplementation::_ResetProperties()
{
	if (LocalIf != TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(LocalIfRWLock);
			LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
		}
#else
		LocalIf = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
#endif
		_GetPublisher()->BroadcastLocalIfChanged(LocalIf);
	}
	if (LocalIfList != TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(LocalIfListRWLock);
			LocalIfList = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
		}
#else
		LocalIfList = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>();
#endif
		_GetPublisher()->BroadcastLocalIfListChanged(LocalIfList);
	}
	if (ImportedIf != TScriptInterface<ITbIfaceimportEmptyIfInterface>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ImportedIfRWLock);
			ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
		}
#else
		ImportedIf = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
#endif
		_GetPublisher()->BroadcastImportedIfChanged(ImportedIf);
	}
	if (ImportedIfList != TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(ImportedIfListRWLock);
			ImportedIfList = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
		}
#else
		ImportedIfList = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>();
#endif
		_GetPublisher()->BroadcastImportedIfListChanged(ImportedIfList);
	}
}
