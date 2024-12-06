#pragma once

#include "Generated/api/TbEnum_apig.h"

class TbEnumEnumInterfaceTracer
{
public:
	TbEnumEnumInterfaceTracer();
	static void capture_state(UObject* Object, ITbEnumEnumInterfaceInterface* obj);
	static void trace_callSetProp0(ETbEnumEnum0 InProp0);
	static void trace_callSetProp1(ETbEnumEnum1 InProp1);
	static void trace_callSetProp2(ETbEnumEnum2 InProp2);
	static void trace_callSetProp3(ETbEnumEnum3 InProp3);
	static void trace_signalSig0(ETbEnumEnum0 Param0);
	static void trace_signalSig1(ETbEnumEnum1 Param1);
	static void trace_signalSig2(ETbEnumEnum2 Param2);
	static void trace_signalSig3(ETbEnumEnum3 Param3);
	static void trace_callFunc0(ETbEnumEnum0 Param0);
	static void trace_callFunc1(ETbEnumEnum1 Param1);
	static void trace_callFunc2(ETbEnumEnum2 Param2);
	static void trace_callFunc3(ETbEnumEnum3 Param3);
};
