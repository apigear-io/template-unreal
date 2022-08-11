#pragma once

#include "Testbed1_apig.h"

class Testbed1StructInterfaceTracer
{
public:
  Testbed1StructInterfaceTracer();
  static void capture_state(ITestbed1StructInterfaceInterface* obj);
  static void trace_callSetPropBool(const FTestbed1StructBool& InPropBool);
  static void trace_callSetPropInt(const FTestbed1StructInt& InPropInt);
  static void trace_callSetPropFloat(const FTestbed1StructFloat& InPropFloat);
  static void trace_callSetPropString(const FTestbed1StructString& InPropString);
  static void trace_signalSigBool(const FTestbed1StructBool& ParamBool);
  static void trace_signalSigInt(const FTestbed1StructInt& ParamInt);
  static void trace_signalSigFloat(const FTestbed1StructFloat& ParamFloat);
  static void trace_signalSigString(const FTestbed1StructString& ParamString);
  static void trace_callFuncBool(const FTestbed1StructBool& ParamBool);
  static void trace_callFuncInt(const FTestbed1StructInt& ParamInt);
  static void trace_callFuncFloat(const FTestbed1StructFloat& ParamFloat);
  static void trace_callFuncString(const FTestbed1StructString& ParamString);
};

class Testbed1StructArrayInterfaceTracer
{
public:
  Testbed1StructArrayInterfaceTracer();
  static void capture_state(ITestbed1StructArrayInterfaceInterface* obj);
  static void trace_callSetPropBool(const TArray<FTestbed1StructBool>& InPropBool);
  static void trace_callSetPropInt(const TArray<FTestbed1StructInt>& InPropInt);
  static void trace_callSetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat);
  static void trace_callSetPropString(const TArray<FTestbed1StructString>& InPropString);
  static void trace_signalSigBool(const TArray<FTestbed1StructBool>& ParamBool);
  static void trace_signalSigInt(const TArray<FTestbed1StructInt>& ParamInt);
  static void trace_signalSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
  static void trace_signalSigString(const TArray<FTestbed1StructString>& ParamString);
  static void trace_callFuncBool(const TArray<FTestbed1StructBool>& ParamBool);
  static void trace_callFuncInt(const TArray<FTestbed1StructInt>& ParamInt);
  static void trace_callFuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
  static void trace_callFuncString(const TArray<FTestbed1StructString>& ParamString);
};
