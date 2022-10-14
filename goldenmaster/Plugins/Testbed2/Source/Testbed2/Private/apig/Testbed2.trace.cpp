#include "Testbed2.trace.h"
#include "Testbed2.json.adapter.h"
#include "tracer.h"

Testbed2ManyParamInterfaceTracer::Testbed2ManyParamInterfaceTracer()
{
}

void Testbed2ManyParamInterfaceTracer::capture_state(UObject* Object, ITestbed2ManyParamInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	fields_["prop2"] = obj->Execute_GetProp2(Object);
	fields_["prop3"] = obj->Execute_GetProp3(Object);
	fields_["prop4"] = obj->Execute_GetProp4(Object);
	Tracer::instance()->state("testbed2/ManyParamInterface", fields_);
}
void Testbed2ManyParamInterfaceTracer::trace_callSetProp1(int32 InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("testbed2/ManyParamInterface#_set", fields_);
}
void Testbed2ManyParamInterfaceTracer::trace_callSetProp2(int32 InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("testbed2/ManyParamInterface#_set", fields_);
}
void Testbed2ManyParamInterfaceTracer::trace_callSetProp3(int32 InProp3)
{
	nlohmann::json fields_;
	fields_["prop3"] = InProp3;
	Tracer::instance()->call("testbed2/ManyParamInterface#_set", fields_);
}
void Testbed2ManyParamInterfaceTracer::trace_callSetProp4(int32 InProp4)
{
	nlohmann::json fields_;
	fields_["prop4"] = InProp4;
	Tracer::instance()->call("testbed2/ManyParamInterface#_set", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_signalSig1(int32 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("testbed2/ManyParamInterface#sig1", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_signalSig2(int32 Param1, int32 Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("testbed2/ManyParamInterface#sig2", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_signalSig3(int32 Param1, int32 Param2, int32 Param3)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	fields_["param3"] = Param3;
	Tracer::instance()->signal("testbed2/ManyParamInterface#sig3", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_signalSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	fields_["param3"] = Param3;
	fields_["param4"] = Param4;
	Tracer::instance()->signal("testbed2/ManyParamInterface#sig4", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_callFunc1(int32 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("testbed2/ManyParamInterface#func1", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_callFunc2(int32 Param1, int32 Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("testbed2/ManyParamInterface#func2", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_callFunc3(int32 Param1, int32 Param2, int32 Param3)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	fields_["param3"] = Param3;
	Tracer::instance()->call("testbed2/ManyParamInterface#func3", fields_);
}

void Testbed2ManyParamInterfaceTracer::trace_callFunc4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	fields_["param3"] = Param3;
	fields_["param4"] = Param4;
	Tracer::instance()->call("testbed2/ManyParamInterface#func4", fields_);
}

Testbed2NestedStruct1InterfaceTracer::Testbed2NestedStruct1InterfaceTracer()
{
}

void Testbed2NestedStruct1InterfaceTracer::capture_state(UObject* Object, ITestbed2NestedStruct1InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	Tracer::instance()->state("testbed2/NestedStruct1Interface", fields_);
}
void Testbed2NestedStruct1InterfaceTracer::trace_callSetProp1(const FTestbed2NestedStruct1& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("testbed2/NestedStruct1Interface#_set", fields_);
}

void Testbed2NestedStruct1InterfaceTracer::trace_signalSig1(const FTestbed2NestedStruct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("testbed2/NestedStruct1Interface#sig1", fields_);
}

void Testbed2NestedStruct1InterfaceTracer::trace_callFunc1(const FTestbed2NestedStruct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("testbed2/NestedStruct1Interface#func1", fields_);
}

Testbed2NestedStruct2InterfaceTracer::Testbed2NestedStruct2InterfaceTracer()
{
}

void Testbed2NestedStruct2InterfaceTracer::capture_state(UObject* Object, ITestbed2NestedStruct2InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	fields_["prop2"] = obj->Execute_GetProp2(Object);
	Tracer::instance()->state("testbed2/NestedStruct2Interface", fields_);
}
void Testbed2NestedStruct2InterfaceTracer::trace_callSetProp1(const FTestbed2NestedStruct1& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("testbed2/NestedStruct2Interface#_set", fields_);
}
void Testbed2NestedStruct2InterfaceTracer::trace_callSetProp2(const FTestbed2NestedStruct2& InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("testbed2/NestedStruct2Interface#_set", fields_);
}

void Testbed2NestedStruct2InterfaceTracer::trace_signalSig1(const FTestbed2NestedStruct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("testbed2/NestedStruct2Interface#sig1", fields_);
}

void Testbed2NestedStruct2InterfaceTracer::trace_signalSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("testbed2/NestedStruct2Interface#sig2", fields_);
}

void Testbed2NestedStruct2InterfaceTracer::trace_callFunc1(const FTestbed2NestedStruct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("testbed2/NestedStruct2Interface#func1", fields_);
}

void Testbed2NestedStruct2InterfaceTracer::trace_callFunc2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("testbed2/NestedStruct2Interface#func2", fields_);
}

Testbed2NestedStruct3InterfaceTracer::Testbed2NestedStruct3InterfaceTracer()
{
}

void Testbed2NestedStruct3InterfaceTracer::capture_state(UObject* Object, ITestbed2NestedStruct3InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	fields_["prop2"] = obj->Execute_GetProp2(Object);
	fields_["prop3"] = obj->Execute_GetProp3(Object);
	Tracer::instance()->state("testbed2/NestedStruct3Interface", fields_);
}
void Testbed2NestedStruct3InterfaceTracer::trace_callSetProp1(const FTestbed2NestedStruct1& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("testbed2/NestedStruct3Interface#_set", fields_);
}
void Testbed2NestedStruct3InterfaceTracer::trace_callSetProp2(const FTestbed2NestedStruct2& InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("testbed2/NestedStruct3Interface#_set", fields_);
}
void Testbed2NestedStruct3InterfaceTracer::trace_callSetProp3(const FTestbed2NestedStruct3& InProp3)
{
	nlohmann::json fields_;
	fields_["prop3"] = InProp3;
	Tracer::instance()->call("testbed2/NestedStruct3Interface#_set", fields_);
}

void Testbed2NestedStruct3InterfaceTracer::trace_signalSig1(const FTestbed2NestedStruct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("testbed2/NestedStruct3Interface#sig1", fields_);
}

void Testbed2NestedStruct3InterfaceTracer::trace_signalSig2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("testbed2/NestedStruct3Interface#sig2", fields_);
}

void Testbed2NestedStruct3InterfaceTracer::trace_signalSig3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	fields_["param3"] = Param3;
	Tracer::instance()->signal("testbed2/NestedStruct3Interface#sig3", fields_);
}

void Testbed2NestedStruct3InterfaceTracer::trace_callFunc1(const FTestbed2NestedStruct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("testbed2/NestedStruct3Interface#func1", fields_);
}

void Testbed2NestedStruct3InterfaceTracer::trace_callFunc2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("testbed2/NestedStruct3Interface#func2", fields_);
}

void Testbed2NestedStruct3InterfaceTracer::trace_callFunc3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	fields_["param3"] = Param3;
	Tracer::instance()->call("testbed2/NestedStruct3Interface#func3", fields_);
}
