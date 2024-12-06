#pragma once

#include "Generated/api/TbSimple_apig.h"

class TbSimpleVoidInterfaceTracer
{
public:
	TbSimpleVoidInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleVoidInterfaceInterface* obj);
	static void trace_signalSigVoid();
	static void trace_callFuncVoid();
};

class TbSimpleSimpleInterfaceTracer
{
public:
	TbSimpleSimpleInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleSimpleInterfaceInterface* obj);
	static void trace_callSetPropBool(bool bInPropBool);
	static void trace_callSetPropInt(int32 InPropInt);
	static void trace_callSetPropInt32(int32 InPropInt32);
	static void trace_callSetPropInt64(int64 InPropInt64);
	static void trace_callSetPropFloat(float InPropFloat);
	static void trace_callSetPropFloat32(float InPropFloat32);
	static void trace_callSetPropFloat64(double InPropFloat64);
	static void trace_callSetPropString(const FString& InPropString);
	static void trace_signalSigBool(bool bParamBool);
	static void trace_signalSigInt(int32 ParamInt);
	static void trace_signalSigInt32(int32 ParamInt32);
	static void trace_signalSigInt64(int64 ParamInt64);
	static void trace_signalSigFloat(float ParamFloat);
	static void trace_signalSigFloat32(float ParamFloat32);
	static void trace_signalSigFloat64(double ParamFloat64);
	static void trace_signalSigString(const FString& ParamString);
	static void trace_callFuncNoReturnValue(bool bParamBool);
	static void trace_callFuncBool(bool bParamBool);
	static void trace_callFuncInt(int32 ParamInt);
	static void trace_callFuncInt32(int32 ParamInt32);
	static void trace_callFuncInt64(int64 ParamInt64);
	static void trace_callFuncFloat(float ParamFloat);
	static void trace_callFuncFloat32(float ParamFloat32);
	static void trace_callFuncFloat64(double ParamFloat);
	static void trace_callFuncString(const FString& ParamString);
};

class TbSimpleSimpleArrayInterfaceTracer
{
public:
	TbSimpleSimpleArrayInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleSimpleArrayInterfaceInterface* obj);
	static void trace_callSetPropBool(const TArray<bool>& InPropBool);
	static void trace_callSetPropInt(const TArray<int32>& InPropInt);
	static void trace_callSetPropInt32(const TArray<int32>& InPropInt32);
	static void trace_callSetPropInt64(const TArray<int64>& InPropInt64);
	static void trace_callSetPropFloat(const TArray<float>& InPropFloat);
	static void trace_callSetPropFloat32(const TArray<float>& InPropFloat32);
	static void trace_callSetPropFloat64(const TArray<double>& InPropFloat64);
	static void trace_callSetPropString(const TArray<FString>& InPropString);
	static void trace_signalSigBool(const TArray<bool>& ParamBool);
	static void trace_signalSigInt(const TArray<int32>& ParamInt);
	static void trace_signalSigInt32(const TArray<int32>& ParamInt32);
	static void trace_signalSigInt64(const TArray<int64>& ParamInt64);
	static void trace_signalSigFloat(const TArray<float>& ParamFloat);
	static void trace_signalSigFloat32(const TArray<float>& ParamFloa32);
	static void trace_signalSigFloat64(const TArray<double>& ParamFloat64);
	static void trace_signalSigString(const TArray<FString>& ParamString);
	static void trace_callFuncBool(const TArray<bool>& ParamBool);
	static void trace_callFuncInt(const TArray<int32>& ParamInt);
	static void trace_callFuncInt32(const TArray<int32>& ParamInt32);
	static void trace_callFuncInt64(const TArray<int64>& ParamInt64);
	static void trace_callFuncFloat(const TArray<float>& ParamFloat);
	static void trace_callFuncFloat32(const TArray<float>& ParamFloat32);
	static void trace_callFuncFloat64(const TArray<double>& ParamFloat);
	static void trace_callFuncString(const TArray<FString>& ParamString);
};

class TbSimpleNoPropertiesInterfaceTracer
{
public:
	TbSimpleNoPropertiesInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleNoPropertiesInterfaceInterface* obj);
	static void trace_signalSigVoid();
	static void trace_signalSigBool(bool bParamBool);
	static void trace_callFuncVoid();
	static void trace_callFuncBool(bool bParamBool);
};

class TbSimpleNoOperationsInterfaceTracer
{
public:
	TbSimpleNoOperationsInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleNoOperationsInterfaceInterface* obj);
	static void trace_callSetPropBool(bool bInPropBool);
	static void trace_callSetPropInt(int32 InPropInt);
	static void trace_signalSigVoid();
	static void trace_signalSigBool(bool bParamBool);
};

class TbSimpleNoSignalsInterfaceTracer
{
public:
	TbSimpleNoSignalsInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleNoSignalsInterfaceInterface* obj);
	static void trace_callSetPropBool(bool bInPropBool);
	static void trace_callSetPropInt(int32 InPropInt);
	static void trace_callFuncVoid();
	static void trace_callFuncBool(bool bParamBool);
};

class TbSimpleEmptyInterfaceTracer
{
public:
	TbSimpleEmptyInterfaceTracer();
	static void capture_state(UObject* Object, ITbSimpleEmptyInterfaceInterface* obj);
};
