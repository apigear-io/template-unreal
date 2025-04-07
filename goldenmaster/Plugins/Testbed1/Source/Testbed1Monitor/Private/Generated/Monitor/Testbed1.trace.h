#pragma once

#include "Testbed1/Generated/api/Testbed1_apig.h"

class Testbed1StructInterfaceTracer
{
public:
	Testbed1StructInterfaceTracer();
	static void capture_state(UObject* Object, ITestbed1StructInterfaceInterface* obj);
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
	static void capture_state(UObject* Object, ITestbed1StructArrayInterfaceInterface* obj);
	static void trace_callSetPropBool(const TArray<FTestbed1StructBool>& InPropBool);
	static void trace_callSetPropInt(const TArray<FTestbed1StructInt>& InPropInt);
	static void trace_callSetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat);
	static void trace_callSetPropString(const TArray<FTestbed1StructString>& InPropString);
	static void trace_callSetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum);
	static void trace_signalSigBool(const TArray<FTestbed1StructBool>& ParamBool);
	static void trace_signalSigInt(const TArray<FTestbed1StructInt>& ParamInt);
	static void trace_signalSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	static void trace_signalSigString(const TArray<FTestbed1StructString>& ParamString);
	static void trace_signalSigEnum(const TArray<ETestbed1Enum0>& ParamEnum);
	static void trace_callFuncBool(const TArray<FTestbed1StructBool>& ParamBool);
	static void trace_callFuncInt(const TArray<FTestbed1StructInt>& ParamInt);
	static void trace_callFuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	static void trace_callFuncString(const TArray<FTestbed1StructString>& ParamString);
	static void trace_callFuncEnum(const TArray<ETestbed1Enum0>& ParamEnum);
};

class Testbed1StructArray2InterfaceTracer
{
public:
	Testbed1StructArray2InterfaceTracer();
	static void capture_state(UObject* Object, ITestbed1StructArray2InterfaceInterface* obj);
	static void trace_callSetPropBool(const FTestbed1StructBoolWithArray& InPropBool);
	static void trace_callSetPropInt(const FTestbed1StructIntWithArray& InPropInt);
	static void trace_callSetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat);
	static void trace_callSetPropString(const FTestbed1StructStringWithArray& InPropString);
	static void trace_callSetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum);
	static void trace_signalSigBool(const FTestbed1StructBoolWithArray& ParamBool);
	static void trace_signalSigInt(const FTestbed1StructIntWithArray& ParamInt);
	static void trace_signalSigFloat(const FTestbed1StructFloatWithArray& ParamFloat);
	static void trace_signalSigString(const FTestbed1StructStringWithArray& ParamString);
	static void trace_callFuncBool(const FTestbed1StructBoolWithArray& ParamBool);
	static void trace_callFuncInt(const FTestbed1StructIntWithArray& ParamInt);
	static void trace_callFuncFloat(const FTestbed1StructFloatWithArray& ParamFloat);
	static void trace_callFuncString(const FTestbed1StructStringWithArray& ParamString);
	static void trace_callFuncEnum(const FTestbed1StructEnumWithArray& ParamEnum);
};
