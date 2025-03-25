#pragma once

#include "TbRefIfaces/Generated/api/TbRefIfaces_apig.h"

class TbRefIfacesSimpleLocalIfTracer
{
public:
	TbRefIfacesSimpleLocalIfTracer();
	static void capture_state(UObject* Object, ITbRefIfacesSimpleLocalIfInterface* obj);
	static void trace_callSetIntProperty(int32 InIntProperty);
	static void trace_signalIntSignal(int32 Param);
	static void trace_callIntMethod(int32 Param);
};

class TbRefIfacesParentIfTracer
{
public:
	TbRefIfacesParentIfTracer();
	static void capture_state(UObject* Object, ITbRefIfacesParentIfInterface* obj);
	static void trace_callSetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf);
	static void trace_callSetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf);
	static void trace_signalLocalIfSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);
	static void trace_signalImportedIfSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);
	static void trace_callLocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);
	static void trace_callImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);
};
