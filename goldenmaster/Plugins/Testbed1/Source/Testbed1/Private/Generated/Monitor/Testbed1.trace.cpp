#include "Generated/Monitor/Testbed1.trace.h"
#include "Generated/api/Testbed1.json.adapter.h"
#include "tracer.h"

Testbed1StructInterfaceTracer::Testbed1StructInterfaceTracer()
{
}

void Testbed1StructInterfaceTracer::capture_state(UObject* Object, ITestbed1StructInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	fields_["propFloat"] = obj->Execute_GetPropFloat(Object);
	fields_["propString"] = obj->Execute_GetPropString(Object);
	Tracer::instance()->state("testbed1/StructInterface", fields_);
}
void Testbed1StructInterfaceTracer::trace_callSetPropBool(const FTestbed1StructBool& InPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = InPropBool;
	Tracer::instance()->call("testbed1/StructInterface#_set", fields_);
}
void Testbed1StructInterfaceTracer::trace_callSetPropInt(const FTestbed1StructInt& InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("testbed1/StructInterface#_set", fields_);
}
void Testbed1StructInterfaceTracer::trace_callSetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	nlohmann::json fields_;
	fields_["propFloat"] = InPropFloat;
	Tracer::instance()->call("testbed1/StructInterface#_set", fields_);
}
void Testbed1StructInterfaceTracer::trace_callSetPropString(const FTestbed1StructString& InPropString)
{
	nlohmann::json fields_;
	fields_["propString"] = InPropString;
	Tracer::instance()->call("testbed1/StructInterface#_set", fields_);
}

void Testbed1StructInterfaceTracer::trace_signalSigBool(const FTestbed1StructBool& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->signal("testbed1/StructInterface#sigBool", fields_);
}

void Testbed1StructInterfaceTracer::trace_signalSigInt(const FTestbed1StructInt& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->signal("testbed1/StructInterface#sigInt", fields_);
}

void Testbed1StructInterfaceTracer::trace_signalSigFloat(const FTestbed1StructFloat& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->signal("testbed1/StructInterface#sigFloat", fields_);
}

void Testbed1StructInterfaceTracer::trace_signalSigString(const FTestbed1StructString& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->signal("testbed1/StructInterface#sigString", fields_);
}

void Testbed1StructInterfaceTracer::trace_callFuncBool(const FTestbed1StructBool& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->call("testbed1/StructInterface#funcBool", fields_);
}

void Testbed1StructInterfaceTracer::trace_callFuncInt(const FTestbed1StructInt& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->call("testbed1/StructInterface#funcInt", fields_);
}

void Testbed1StructInterfaceTracer::trace_callFuncFloat(const FTestbed1StructFloat& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->call("testbed1/StructInterface#funcFloat", fields_);
}

void Testbed1StructInterfaceTracer::trace_callFuncString(const FTestbed1StructString& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->call("testbed1/StructInterface#funcString", fields_);
}

Testbed1StructArrayInterfaceTracer::Testbed1StructArrayInterfaceTracer()
{
}

void Testbed1StructArrayInterfaceTracer::capture_state(UObject* Object, ITestbed1StructArrayInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	fields_["propFloat"] = obj->Execute_GetPropFloat(Object);
	fields_["propString"] = obj->Execute_GetPropString(Object);
	fields_["propEnum"] = obj->Execute_GetPropEnum(Object);
	Tracer::instance()->state("testbed1/StructArrayInterface", fields_);
}
void Testbed1StructArrayInterfaceTracer::trace_callSetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = InPropBool;
	Tracer::instance()->call("testbed1/StructArrayInterface#_set", fields_);
}
void Testbed1StructArrayInterfaceTracer::trace_callSetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("testbed1/StructArrayInterface#_set", fields_);
}
void Testbed1StructArrayInterfaceTracer::trace_callSetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	nlohmann::json fields_;
	fields_["propFloat"] = InPropFloat;
	Tracer::instance()->call("testbed1/StructArrayInterface#_set", fields_);
}
void Testbed1StructArrayInterfaceTracer::trace_callSetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	nlohmann::json fields_;
	fields_["propString"] = InPropString;
	Tracer::instance()->call("testbed1/StructArrayInterface#_set", fields_);
}
void Testbed1StructArrayInterfaceTracer::trace_callSetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum)
{
	nlohmann::json fields_;
	fields_["propEnum"] = InPropEnum;
	Tracer::instance()->call("testbed1/StructArrayInterface#_set", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_signalSigBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->signal("testbed1/StructArrayInterface#sigBool", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_signalSigInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->signal("testbed1/StructArrayInterface#sigInt", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_signalSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->signal("testbed1/StructArrayInterface#sigFloat", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_signalSigString(const TArray<FTestbed1StructString>& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->signal("testbed1/StructArrayInterface#sigString", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_signalSigEnum(const TArray<ETestbed1Enum0>& ParamEnum)
{
	nlohmann::json fields_;
	fields_["paramEnum"] = ParamEnum;
	Tracer::instance()->signal("testbed1/StructArrayInterface#sigEnum", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_callFuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->call("testbed1/StructArrayInterface#funcBool", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_callFuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->call("testbed1/StructArrayInterface#funcInt", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_callFuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->call("testbed1/StructArrayInterface#funcFloat", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_callFuncString(const TArray<FTestbed1StructString>& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->call("testbed1/StructArrayInterface#funcString", fields_);
}

void Testbed1StructArrayInterfaceTracer::trace_callFuncEnum(const TArray<ETestbed1Enum0>& ParamEnum)
{
	nlohmann::json fields_;
	fields_["paramEnum"] = ParamEnum;
	Tracer::instance()->call("testbed1/StructArrayInterface#funcEnum", fields_);
}

Testbed1StructArray2InterfaceTracer::Testbed1StructArray2InterfaceTracer()
{
}

void Testbed1StructArray2InterfaceTracer::capture_state(UObject* Object, ITestbed1StructArray2InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propBool"] = obj->Execute_GetPropBool(Object);
	fields_["propInt"] = obj->Execute_GetPropInt(Object);
	fields_["propFloat"] = obj->Execute_GetPropFloat(Object);
	fields_["propString"] = obj->Execute_GetPropString(Object);
	fields_["propEnum"] = obj->Execute_GetPropEnum(Object);
	Tracer::instance()->state("testbed1/StructArray2Interface", fields_);
}
void Testbed1StructArray2InterfaceTracer::trace_callSetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	nlohmann::json fields_;
	fields_["propBool"] = InPropBool;
	Tracer::instance()->call("testbed1/StructArray2Interface#_set", fields_);
}
void Testbed1StructArray2InterfaceTracer::trace_callSetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	nlohmann::json fields_;
	fields_["propInt"] = InPropInt;
	Tracer::instance()->call("testbed1/StructArray2Interface#_set", fields_);
}
void Testbed1StructArray2InterfaceTracer::trace_callSetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	nlohmann::json fields_;
	fields_["propFloat"] = InPropFloat;
	Tracer::instance()->call("testbed1/StructArray2Interface#_set", fields_);
}
void Testbed1StructArray2InterfaceTracer::trace_callSetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	nlohmann::json fields_;
	fields_["propString"] = InPropString;
	Tracer::instance()->call("testbed1/StructArray2Interface#_set", fields_);
}
void Testbed1StructArray2InterfaceTracer::trace_callSetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	nlohmann::json fields_;
	fields_["propEnum"] = InPropEnum;
	Tracer::instance()->call("testbed1/StructArray2Interface#_set", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_signalSigBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->signal("testbed1/StructArray2Interface#sigBool", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_signalSigInt(const FTestbed1StructIntWithArray& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->signal("testbed1/StructArray2Interface#sigInt", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_signalSigFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->signal("testbed1/StructArray2Interface#sigFloat", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_signalSigString(const FTestbed1StructStringWithArray& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->signal("testbed1/StructArray2Interface#sigString", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_callFuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	nlohmann::json fields_;
	fields_["paramBool"] = ParamBool;
	Tracer::instance()->call("testbed1/StructArray2Interface#funcBool", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_callFuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	nlohmann::json fields_;
	fields_["paramInt"] = ParamInt;
	Tracer::instance()->call("testbed1/StructArray2Interface#funcInt", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_callFuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	nlohmann::json fields_;
	fields_["paramFloat"] = ParamFloat;
	Tracer::instance()->call("testbed1/StructArray2Interface#funcFloat", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_callFuncString(const FTestbed1StructStringWithArray& ParamString)
{
	nlohmann::json fields_;
	fields_["paramString"] = ParamString;
	Tracer::instance()->call("testbed1/StructArray2Interface#funcString", fields_);
}

void Testbed1StructArray2InterfaceTracer::trace_callFuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	nlohmann::json fields_;
	fields_["paramEnum"] = ParamEnum;
	Tracer::instance()->call("testbed1/StructArray2Interface#funcEnum", fields_);
}
