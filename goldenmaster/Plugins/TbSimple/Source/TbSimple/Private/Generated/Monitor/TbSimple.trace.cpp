#include "TbSimple.trace.h"
#include "Generated/api/TbSimple.json.adapter.h"
#include "tracer.h"

TbSimpleSimpleInterfaceTracer::TbSimpleSimpleInterfaceTracer()
{
}

void TbSimpleSimpleInterfaceTracer::capture_state(UObject* Object, ITbSimpleSimpleInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	fields_["propFloat"] = obj->Execute_GetPropFloat(Object);
	fields_["propString"] = obj->Execute_GetPropString(Object);
	Tracer::instance()->state("tb.simple/SimpleInterface", fields_);
}
void TbSimpleSimpleInterfaceTracer::trace_callSetPropBool(bool bInPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = bInPropBool;
	Tracer::instance()->call("tb.simple/SimpleInterface#_set", fields_);
}
void TbSimpleSimpleInterfaceTracer::trace_callSetPropInt(int32 InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("tb.simple/SimpleInterface#_set", fields_);
}
void TbSimpleSimpleInterfaceTracer::trace_callSetPropFloat(float InPropFloat)
{
	nlohmann::json fields_;
	fields_["propFloat"] = InPropFloat;
	Tracer::instance()->call("tb.simple/SimpleInterface#_set", fields_);
}
void TbSimpleSimpleInterfaceTracer::trace_callSetPropString(const FString& InPropString)
{
	nlohmann::json fields_;
	fields_["propString"] = InPropString;
	Tracer::instance()->call("tb.simple/SimpleInterface#_set", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_signalSigVoid()
{
	nlohmann::json fields_;
	Tracer::instance()->signal("tb.simple/SimpleInterface#sigVoid", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_signalSigBool(bool bParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = bParamBool;
	Tracer::instance()->signal("tb.simple/SimpleInterface#sigBool", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_signalSigInt(int32 ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->signal("tb.simple/SimpleInterface#sigInt", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_signalSigFloat(float ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->signal("tb.simple/SimpleInterface#sigFloat", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_signalSigString(const FString& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->signal("tb.simple/SimpleInterface#sigString", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_callFuncVoid()
{
	nlohmann::json fields_;
	Tracer::instance()->call("tb.simple/SimpleInterface#funcVoid", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_callFuncBool(bool bParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = bParamBool;
	Tracer::instance()->call("tb.simple/SimpleInterface#funcBool", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_callFuncInt(int32 ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->call("tb.simple/SimpleInterface#funcInt", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_callFuncFloat(float ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->call("tb.simple/SimpleInterface#funcFloat", fields_);
}

void TbSimpleSimpleInterfaceTracer::trace_callFuncString(const FString& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->call("tb.simple/SimpleInterface#funcString", fields_);
}

TbSimpleSimpleArrayInterfaceTracer::TbSimpleSimpleArrayInterfaceTracer()
{
}

void TbSimpleSimpleArrayInterfaceTracer::capture_state(UObject* Object, ITbSimpleSimpleArrayInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	fields_["propFloat"] = obj->Execute_GetPropFloat(Object);
	fields_["propString"] = obj->Execute_GetPropString(Object);
	Tracer::instance()->state("tb.simple/SimpleArrayInterface", fields_);
}
void TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropBool(const TArray<bool>& InPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = InPropBool;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#_set", fields_);
}
void TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropInt(const TArray<int32>& InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#_set", fields_);
}
void TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropFloat(const TArray<float>& InPropFloat)
{
	nlohmann::json fields_;
	fields_["propFloat"] = InPropFloat;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#_set", fields_);
}
void TbSimpleSimpleArrayInterfaceTracer::trace_callSetPropString(const TArray<FString>& InPropString)
{
	nlohmann::json fields_;
	fields_["propString"] = InPropString;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#_set", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_signalSigBool(const TArray<bool>& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->signal("tb.simple/SimpleArrayInterface#sigBool", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_signalSigInt(const TArray<int32>& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->signal("tb.simple/SimpleArrayInterface#sigInt", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_signalSigFloat(const TArray<float>& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->signal("tb.simple/SimpleArrayInterface#sigFloat", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_signalSigString(const TArray<FString>& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->signal("tb.simple/SimpleArrayInterface#sigString", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_callFuncBool(const TArray<bool>& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#funcBool", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_callFuncInt(const TArray<int32>& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#funcInt", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_callFuncFloat(const TArray<float>& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#funcFloat", fields_);
}

void TbSimpleSimpleArrayInterfaceTracer::trace_callFuncString(const TArray<FString>& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->call("tb.simple/SimpleArrayInterface#funcString", fields_);
}

TbSimpleNoPropertiesInterfaceTracer::TbSimpleNoPropertiesInterfaceTracer()
{
}

void TbSimpleNoPropertiesInterfaceTracer::capture_state(UObject* Object, ITbSimpleNoPropertiesInterfaceInterface* obj)
{
	nlohmann::json fields_;
	Tracer::instance()->state("tb.simple/NoPropertiesInterface", fields_);
}

void TbSimpleNoPropertiesInterfaceTracer::trace_signalSigVoid()
{
	nlohmann::json fields_;
	Tracer::instance()->signal("tb.simple/NoPropertiesInterface#sigVoid", fields_);
}

void TbSimpleNoPropertiesInterfaceTracer::trace_signalSigBool(bool bParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = bParamBool;
	Tracer::instance()->signal("tb.simple/NoPropertiesInterface#sigBool", fields_);
}

void TbSimpleNoPropertiesInterfaceTracer::trace_callFuncVoid()
{
	nlohmann::json fields_;
	Tracer::instance()->call("tb.simple/NoPropertiesInterface#funcVoid", fields_);
}

void TbSimpleNoPropertiesInterfaceTracer::trace_callFuncBool(bool bParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = bParamBool;
	Tracer::instance()->call("tb.simple/NoPropertiesInterface#funcBool", fields_);
}

TbSimpleNoOperationsInterfaceTracer::TbSimpleNoOperationsInterfaceTracer()
{
}

void TbSimpleNoOperationsInterfaceTracer::capture_state(UObject* Object, ITbSimpleNoOperationsInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	Tracer::instance()->state("tb.simple/NoOperationsInterface", fields_);
}
void TbSimpleNoOperationsInterfaceTracer::trace_callSetPropBool(bool bInPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = bInPropBool;
	Tracer::instance()->call("tb.simple/NoOperationsInterface#_set", fields_);
}
void TbSimpleNoOperationsInterfaceTracer::trace_callSetPropInt(int32 InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("tb.simple/NoOperationsInterface#_set", fields_);
}

void TbSimpleNoOperationsInterfaceTracer::trace_signalSigVoid()
{
	nlohmann::json fields_;
	Tracer::instance()->signal("tb.simple/NoOperationsInterface#sigVoid", fields_);
}

void TbSimpleNoOperationsInterfaceTracer::trace_signalSigBool(bool bParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = bParamBool;
	Tracer::instance()->signal("tb.simple/NoOperationsInterface#sigBool", fields_);
}

TbSimpleNoSignalsInterfaceTracer::TbSimpleNoSignalsInterfaceTracer()
{
}

void TbSimpleNoSignalsInterfaceTracer::capture_state(UObject* Object, ITbSimpleNoSignalsInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	Tracer::instance()->state("tb.simple/NoSignalsInterface", fields_);
}
void TbSimpleNoSignalsInterfaceTracer::trace_callSetPropBool(bool bInPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = bInPropBool;
	Tracer::instance()->call("tb.simple/NoSignalsInterface#_set", fields_);
}
void TbSimpleNoSignalsInterfaceTracer::trace_callSetPropInt(int32 InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("tb.simple/NoSignalsInterface#_set", fields_);
}

void TbSimpleNoSignalsInterfaceTracer::trace_callFuncVoid()
{
	nlohmann::json fields_;
	Tracer::instance()->call("tb.simple/NoSignalsInterface#funcVoid", fields_);
}

void TbSimpleNoSignalsInterfaceTracer::trace_callFuncBool(bool bParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = bParamBool;
	Tracer::instance()->call("tb.simple/NoSignalsInterface#funcBool", fields_);
}

TbSimpleEmptyInterfaceTracer::TbSimpleEmptyInterfaceTracer()
{
}

void TbSimpleEmptyInterfaceTracer::capture_state(UObject* Object, ITbSimpleEmptyInterfaceInterface* obj)
{
	nlohmann::json fields_;
	Tracer::instance()->state("tb.simple/EmptyInterface", fields_);
}
