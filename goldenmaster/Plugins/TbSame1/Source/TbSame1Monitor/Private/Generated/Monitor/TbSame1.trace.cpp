#include "TbSame1.trace.h"
#include "TbSame1/Generated/api/TbSame1.json.adapter.h"
#include "tracer.h"

TbSame1SameStruct1InterfaceTracer::TbSame1SameStruct1InterfaceTracer()
{
}

void TbSame1SameStruct1InterfaceTracer::capture_state(UObject* Object, ITbSame1SameStruct1InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->GetProp1();
	Tracer::instance()->state("tb.same1/SameStruct1Interface", fields_);
}
void TbSame1SameStruct1InterfaceTracer::trace_callSetProp1(const FTbSame1Struct1& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same1/SameStruct1Interface#_set", fields_);
}

void TbSame1SameStruct1InterfaceTracer::trace_signalSig1(const FTbSame1Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same1/SameStruct1Interface#sig1", fields_);
}

void TbSame1SameStruct1InterfaceTracer::trace_callFunc1(const FTbSame1Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same1/SameStruct1Interface#func1", fields_);
}

TbSame1SameStruct2InterfaceTracer::TbSame1SameStruct2InterfaceTracer()
{
}

void TbSame1SameStruct2InterfaceTracer::capture_state(UObject* Object, ITbSame1SameStruct2InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->GetProp1();
	fields_["prop2"] = obj->GetProp2();
	Tracer::instance()->state("tb.same1/SameStruct2Interface", fields_);
}
void TbSame1SameStruct2InterfaceTracer::trace_callSetProp1(const FTbSame1Struct2& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same1/SameStruct2Interface#_set", fields_);
}
void TbSame1SameStruct2InterfaceTracer::trace_callSetProp2(const FTbSame1Struct2& InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("tb.same1/SameStruct2Interface#_set", fields_);
}

void TbSame1SameStruct2InterfaceTracer::trace_signalSig1(const FTbSame1Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same1/SameStruct2Interface#sig1", fields_);
}

void TbSame1SameStruct2InterfaceTracer::trace_signalSig2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("tb.same1/SameStruct2Interface#sig2", fields_);
}

void TbSame1SameStruct2InterfaceTracer::trace_callFunc1(const FTbSame1Struct1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same1/SameStruct2Interface#func1", fields_);
}

void TbSame1SameStruct2InterfaceTracer::trace_callFunc2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("tb.same1/SameStruct2Interface#func2", fields_);
}

TbSame1SameEnum1InterfaceTracer::TbSame1SameEnum1InterfaceTracer()
{
}

void TbSame1SameEnum1InterfaceTracer::capture_state(UObject* Object, ITbSame1SameEnum1InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->GetProp1();
	Tracer::instance()->state("tb.same1/SameEnum1Interface", fields_);
}
void TbSame1SameEnum1InterfaceTracer::trace_callSetProp1(ETbSame1Enum1 InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same1/SameEnum1Interface#_set", fields_);
}

void TbSame1SameEnum1InterfaceTracer::trace_signalSig1(ETbSame1Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same1/SameEnum1Interface#sig1", fields_);
}

void TbSame1SameEnum1InterfaceTracer::trace_callFunc1(ETbSame1Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same1/SameEnum1Interface#func1", fields_);
}

TbSame1SameEnum2InterfaceTracer::TbSame1SameEnum2InterfaceTracer()
{
}

void TbSame1SameEnum2InterfaceTracer::capture_state(UObject* Object, ITbSame1SameEnum2InterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["prop1"] = obj->GetProp1();
	fields_["prop2"] = obj->GetProp2();
	Tracer::instance()->state("tb.same1/SameEnum2Interface", fields_);
}
void TbSame1SameEnum2InterfaceTracer::trace_callSetProp1(ETbSame1Enum1 InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.same1/SameEnum2Interface#_set", fields_);
}
void TbSame1SameEnum2InterfaceTracer::trace_callSetProp2(ETbSame1Enum2 InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("tb.same1/SameEnum2Interface#_set", fields_);
}

void TbSame1SameEnum2InterfaceTracer::trace_signalSig1(ETbSame1Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.same1/SameEnum2Interface#sig1", fields_);
}

void TbSame1SameEnum2InterfaceTracer::trace_signalSig2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("tb.same1/SameEnum2Interface#sig2", fields_);
}

void TbSame1SameEnum2InterfaceTracer::trace_callFunc1(ETbSame1Enum1 Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.same1/SameEnum2Interface#func1", fields_);
}

void TbSame1SameEnum2InterfaceTracer::trace_callFunc2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	fields_["param2"] = Param2;
	Tracer::instance()->call("tb.same1/SameEnum2Interface#func2", fields_);
}
