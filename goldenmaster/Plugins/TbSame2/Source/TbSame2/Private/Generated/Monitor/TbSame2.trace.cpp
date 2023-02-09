#include "TbSame2.trace.h"
#include "Generated/api/TbSame2.json.adapter.h"
#include "tracer.h"

TbSame2SameStruct1InterfaceTracer::TbSame2SameStruct1InterfaceTracer()
{
}

void TbSame2SameStruct1InterfaceTracer::capture_state(UObject* Object, ITbSame2SameStruct1InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	Tracer::instance()->state("tb.same2/SameStruct1Interface", fields_);
}
void TbSame2SameStruct1InterfaceTracer::trace_callSetProp1(const FTbSame2Struct1& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same2/SameStruct1Interface#_set", fields_);
}

void TbSame2SameStruct1InterfaceTracer::trace_signalSig1(const FTbSame2Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same2/SameStruct1Interface#sig1", fields_);
}

void TbSame2SameStruct1InterfaceTracer::trace_callFunc1(const FTbSame2Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same2/SameStruct1Interface#func1", fields_);
}

TbSame2SameStruct2InterfaceTracer::TbSame2SameStruct2InterfaceTracer()
{
}

void TbSame2SameStruct2InterfaceTracer::capture_state(UObject* Object, ITbSame2SameStruct2InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	fields_["prop2"] = obj->Execute_GetProp2(Object);
	Tracer::instance()->state("tb.same2/SameStruct2Interface", fields_);
}
void TbSame2SameStruct2InterfaceTracer::trace_callSetProp1(const FTbSame2Struct2& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same2/SameStruct2Interface#_set", fields_);
}
void TbSame2SameStruct2InterfaceTracer::trace_callSetProp2(const FTbSame2Struct2& InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("tb.same2/SameStruct2Interface#_set", fields_);
}

void TbSame2SameStruct2InterfaceTracer::trace_signalSig1(const FTbSame2Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same2/SameStruct2Interface#sig1", fields_);
}

void TbSame2SameStruct2InterfaceTracer::trace_signalSig2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("tb.same2/SameStruct2Interface#sig2", fields_);
}

void TbSame2SameStruct2InterfaceTracer::trace_callFunc1(const FTbSame2Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same2/SameStruct2Interface#func1", fields_);
}

void TbSame2SameStruct2InterfaceTracer::trace_callFunc2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("tb.same2/SameStruct2Interface#func2", fields_);
}

TbSame2SameEnum1InterfaceTracer::TbSame2SameEnum1InterfaceTracer()
{
}

void TbSame2SameEnum1InterfaceTracer::capture_state(UObject* Object, ITbSame2SameEnum1InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	Tracer::instance()->state("tb.same2/SameEnum1Interface", fields_);
}
void TbSame2SameEnum1InterfaceTracer::trace_callSetProp1(ETbSame2Enum1 InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same2/SameEnum1Interface#_set", fields_);
}

void TbSame2SameEnum1InterfaceTracer::trace_signalSig1(ETbSame2Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same2/SameEnum1Interface#sig1", fields_);
}

void TbSame2SameEnum1InterfaceTracer::trace_callFunc1(ETbSame2Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same2/SameEnum1Interface#func1", fields_);
}

TbSame2SameEnum2InterfaceTracer::TbSame2SameEnum2InterfaceTracer()
{
}

void TbSame2SameEnum2InterfaceTracer::capture_state(UObject* Object, ITbSame2SameEnum2InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->Execute_GetProp1(Object);
	fields_["prop2"] = obj->Execute_GetProp2(Object);
	Tracer::instance()->state("tb.same2/SameEnum2Interface", fields_);
}
void TbSame2SameEnum2InterfaceTracer::trace_callSetProp1(ETbSame2Enum1 InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same2/SameEnum2Interface#_set", fields_);
}
void TbSame2SameEnum2InterfaceTracer::trace_callSetProp2(ETbSame2Enum2 InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("tb.same2/SameEnum2Interface#_set", fields_);
}

void TbSame2SameEnum2InterfaceTracer::trace_signalSig1(ETbSame2Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same2/SameEnum2Interface#sig1", fields_);
}

void TbSame2SameEnum2InterfaceTracer::trace_signalSig2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("tb.same2/SameEnum2Interface#sig2", fields_);
}

void TbSame2SameEnum2InterfaceTracer::trace_callFunc1(ETbSame2Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same2/SameEnum2Interface#func1", fields_);
}

void TbSame2SameEnum2InterfaceTracer::trace_callFunc2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("tb.same2/SameEnum2Interface#func2", fields_);
}
