#pragma once

#include "TbSame1_apig.h"

class TbSame1SameStruct1InterfaceTracer
{
public:
  TbSame1SameStruct1InterfaceTracer();
  static void capture_state(ITbSame1SameStruct1InterfaceInterface* obj);
  static void trace_callSetProp1(const FTbSame1Struct1& InProp1);
  static void trace_signalSig1(const FTbSame1Struct1& Param1);
  static void trace_callFunc1(const FTbSame1Struct1& Param1);
};

class TbSame1SameStruct2InterfaceTracer
{
public:
  TbSame1SameStruct2InterfaceTracer();
  static void capture_state(ITbSame1SameStruct2InterfaceInterface* obj);
  static void trace_callSetProp1(const FTbSame1Struct2& InProp1);
  static void trace_callSetProp2(const FTbSame1Struct2& InProp2);
  static void trace_signalSig1(const FTbSame1Struct1& Param1);
  static void trace_signalSig2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);
  static void trace_callFunc1(const FTbSame1Struct1& Param1);
  static void trace_callFunc2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);
};

class TbSame1SameEnum1InterfaceTracer
{
public:
  TbSame1SameEnum1InterfaceTracer();
  static void capture_state(ITbSame1SameEnum1InterfaceInterface* obj);
  static void trace_callSetProp1(const ETbSame1Enum1& InProp1);
  static void trace_signalSig1(const ETbSame1Enum1& Param1);
  static void trace_callFunc1(const ETbSame1Enum1& Param1);
};

class TbSame1SameEnum2InterfaceTracer
{
public:
  TbSame1SameEnum2InterfaceTracer();
  static void capture_state(ITbSame1SameEnum2InterfaceInterface* obj);
  static void trace_callSetProp1(const ETbSame1Enum1& InProp1);
  static void trace_callSetProp2(const ETbSame1Enum2& InProp2);
  static void trace_signalSig1(const ETbSame1Enum1& Param1);
  static void trace_signalSig2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2);
  static void trace_callFunc1(const ETbSame1Enum1& Param1);
  static void trace_callFunc2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2);
};
