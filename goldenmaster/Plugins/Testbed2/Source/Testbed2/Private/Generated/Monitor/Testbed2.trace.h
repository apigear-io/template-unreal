#pragma once

#include "Testbed2_apig.h"

class Testbed2ManyParamInterfaceTracer
{
public:
	Testbed2ManyParamInterfaceTracer();
	static void capture_state(UObject* Object, ITestbed2ManyParamInterfaceInterface* obj);
	static void trace_callSetProp1(int32 InProp1);
	static void trace_callSetProp2(int32 InProp2);
	static void trace_callSetProp3(int32 InProp3);
	static void trace_callSetProp4(int32 InProp4);
	static void trace_signalSig1(int32 Param1);
	static void trace_signalSig2(int32 Param1, int32 Param2);
	static void trace_signalSig3(int32 Param1, int32 Param2, int32 Param3);
	static void trace_signalSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
	static void trace_callFunc1(int32 Param1);
	static void trace_callFunc2(int32 Param1, int32 Param2);
	static void trace_callFunc3(int32 Param1, int32 Param2, int32 Param3);
	static void trace_callFunc4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);
};

class Testbed2NestedStruct1InterfaceTracer
{
public:
	Testbed2NestedStruct1InterfaceTracer();
	static void capture_state(UObject* Object, ITestbed2NestedStruct1InterfaceInterface* obj);
	static void trace_callSetProp1(const FTestbed2NestedStruct1& InProp1);
	static void trace_signalSig1(const FTestbed2NestedStruct1& Param1);
	static void trace_callFunc1(const FTestbed2NestedStruct1& Param1);
};

class Testbed2NestedStruct2InterfaceTracer
{
public:
	Testbed2NestedStruct2InterfaceTracer();
	static void capture_state(UObject* Object, ITestbed2NestedStruct2InterfaceInterface* obj);
	static void trace_callSetProp1(const FTestbed2NestedStruct1& InProp1);
	static void trace_callSetProp2(const FTestbed2NestedStruct2& InProp2);
	static void trace_signalSig1(const FTestbed2NestedStruct1& Param1);
	static void trace_signalSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	static void trace_callFunc1(const FTestbed2NestedStruct1& Param1);
	static void trace_callFunc2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
};

class Testbed2NestedStruct3InterfaceTracer
{
public:
	Testbed2NestedStruct3InterfaceTracer();
	static void capture_state(UObject* Object, ITestbed2NestedStruct3InterfaceInterface* obj);
	static void trace_callSetProp1(const FTestbed2NestedStruct1& InProp1);
	static void trace_callSetProp2(const FTestbed2NestedStruct2& InProp2);
	static void trace_callSetProp3(const FTestbed2NestedStruct3& InProp3);
	static void trace_signalSig1(const FTestbed2NestedStruct1& Param1);
	static void trace_signalSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	static void trace_signalSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
	static void trace_callFunc1(const FTestbed2NestedStruct1& Param1);
	static void trace_callFunc2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);
	static void trace_callFunc3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);
};
