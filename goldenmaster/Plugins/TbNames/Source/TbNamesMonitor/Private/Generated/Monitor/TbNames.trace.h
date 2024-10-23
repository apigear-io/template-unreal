#pragma once

#include "TbNames/Generated/api/TbNames_apig.h"

class TbNamesNamEsTracer
{
public:
	TbNamesNamEsTracer();
	static void capture_state(UObject* Object, ITbNamesNamEsInterface* obj);
	static void trace_callSetSwitch(bool bInSwitch);
	static void trace_callSetSomeProperty(int32 InSomeProperty);
	static void trace_callSetSomePoperty2(int32 InSomePoperty2);
	static void trace_signalSomeSignal(bool bSomeParam);
	static void trace_signalSomeSignal2(bool bSomeParam);
	static void trace_callSomeFunction(bool bSomeParam);
	static void trace_callSomeFunction2(bool bSomeParam);
};
