#pragma once

#include "TbSame2_apig.h"

class TbSame2SameStruct1InterfaceTracer
{
public:
	TbSame2SameStruct1InterfaceTracer();
	static void capture_state(UObject* Object, ITbSame2SameStruct1InterfaceInterface* obj);
	static void trace_callSetProp1(const FTbSame2Struct1& InProp1);
	static void trace_signalSig1(const FTbSame2Struct1& Param1);
	static void trace_callFunc1(const FTbSame2Struct1& Param1);
};

class TbSame2SameStruct2InterfaceTracer
{
public:
	TbSame2SameStruct2InterfaceTracer();
	static void capture_state(UObject* Object, ITbSame2SameStruct2InterfaceInterface* obj);
	static void trace_callSetProp1(const FTbSame2Struct2& InProp1);
	static void trace_callSetProp2(const FTbSame2Struct2& InProp2);
	static void trace_signalSig1(const FTbSame2Struct1& Param1);
	static void trace_signalSig2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);
	static void trace_callFunc1(const FTbSame2Struct1& Param1);
	static void trace_callFunc2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);
};

class TbSame2SameEnum1InterfaceTracer
{
public:
	TbSame2SameEnum1InterfaceTracer();
	static void capture_state(UObject* Object, ITbSame2SameEnum1InterfaceInterface* obj);
	static void trace_callSetProp1(ETbSame2Enum1 InProp1);
	static void trace_signalSig1(ETbSame2Enum1 Param1);
	static void trace_callFunc1(ETbSame2Enum1 Param1);
};

class TbSame2SameEnum2InterfaceTracer
{
public:
	TbSame2SameEnum2InterfaceTracer();
	static void capture_state(UObject* Object, ITbSame2SameEnum2InterfaceInterface* obj);
	static void trace_callSetProp1(ETbSame2Enum1 InProp1);
	static void trace_callSetProp2(ETbSame2Enum2 InProp2);
	static void trace_signalSig1(ETbSame2Enum1 Param1);
	static void trace_signalSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
	static void trace_callFunc1(ETbSame2Enum1 Param1);
	static void trace_callFunc2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);
};
