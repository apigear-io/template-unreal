#pragma once

#include "TbSimple_apig.h"

class TbSimpleSimpleInterfaceTracer
{
public:
	TbSimpleSimpleInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleSimpleInterfaceInterface* obj);
	static void trace_callSetPropBool(bool bInPropBool);
	static void trace_callSetPropInt(int32 InPropInt);
	static void trace_callSetPropFloat(float InPropFloat);
	static void trace_callSetPropString(const FString& InPropString);
	static void trace_signalSigBool(bool bParamBool);
	static void trace_signalSigInt(int32 ParamInt);
	static void trace_signalSigFloat(float ParamFloat);
	static void trace_signalSigString(const FString& ParamString);
	static void trace_callFuncBool(bool bParamBool);
	static void trace_callFuncInt(int32 ParamInt);
	static void trace_callFuncFloat(float ParamFloat);
	static void trace_callFuncString(const FString& ParamString);
};

class TbSimpleSimpleArrayInterfaceTracer
{
public:
	TbSimpleSimpleArrayInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleSimpleArrayInterfaceInterface* obj);
	static void trace_callSetPropBool(const TArray<bool>& InPropBool);
	static void trace_callSetPropInt(const TArray<int32>& InPropInt);
	static void trace_callSetPropFloat(const TArray<float>& InPropFloat);
	static void trace_callSetPropString(const TArray<FString>& InPropString);
	static void trace_signalSigBool(const TArray<bool>& ParamBool);
	static void trace_signalSigInt(const TArray<int32>& ParamInt);
	static void trace_signalSigFloat(const TArray<float>& ParamFloat);
	static void trace_signalSigString(const TArray<FString>& ParamString);
	static void trace_callFuncBool(const TArray<bool>& ParamBool);
	static void trace_callFuncInt(const TArray<int32>& ParamInt);
	static void trace_callFuncFloat(const TArray<float>& ParamFloat);
	static void trace_callFuncString(const TArray<FString>& ParamString);
};
