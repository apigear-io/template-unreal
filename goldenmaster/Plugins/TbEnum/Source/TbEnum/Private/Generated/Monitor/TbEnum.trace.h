#pragma once

#include "TbEnum_apig.h"

class TbEnumEnumInterfaceTracer
{
public:
	TbEnumEnumInterfaceTracer();
	static void capture_state(UObject* Object, ITbEnumEnumInterfaceInterface* obj);
	static void trace_callSetProp0(const ETbEnumEnum0& InProp0);
	static void trace_callSetProp1(const ETbEnumEnum1& InProp1);
	static void trace_callSetProp2(const ETbEnumEnum2& InProp2);
	static void trace_callSetProp3(const ETbEnumEnum3& InProp3);
	static void trace_signalSig0(const ETbEnumEnum0& Param0);
	static void trace_signalSig1(const ETbEnumEnum1& Param1);
	static void trace_signalSig2(const ETbEnumEnum2& Param2);
	static void trace_signalSig3(const ETbEnumEnum3& Param3);
	static void trace_callFunc0(const ETbEnumEnum0& Param0);
	static void trace_callFunc1(const ETbEnumEnum1& Param1);
	static void trace_callFunc2(const ETbEnumEnum2& Param2);
	static void trace_callFunc3(const ETbEnumEnum3& Param3);
};
