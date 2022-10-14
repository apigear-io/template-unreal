#include "TbEnum.trace.h"
#include "TbEnum.json.adapter.h"
#include "tracer.h"

TbEnumEnumInterfaceTracer::TbEnumEnumInterfaceTracer()
{
}

void TbEnumEnumInterfaceTracer::capture_state(UObject* Object, ITbEnumEnumInterfaceInterface* obj)
{
	nlohmann::json fields_;
	ETbEnumEnum0 outProp0;
	obj->Execute_GetProp0(Object, outProp0);
	fields_["prop0"] = outProp0;
	ETbEnumEnum1 outProp1;
	obj->Execute_GetProp1(Object, outProp1);
	fields_["prop1"] = outProp1;
	ETbEnumEnum2 outProp2;
	obj->Execute_GetProp2(Object, outProp2);
	fields_["prop2"] = outProp2;
	ETbEnumEnum3 outProp3;
	obj->Execute_GetProp3(Object, outProp3);
	fields_["prop3"] = outProp3;
	Tracer::instance()->state("tb.enum/EnumInterface", fields_);
}
void TbEnumEnumInterfaceTracer::trace_callSetProp0(const ETbEnumEnum0& InProp0)
{
	nlohmann::json fields_;
	fields_["prop0"] = InProp0;
	Tracer::instance()->call("tb.enum/EnumInterface#_set", fields_);
}
void TbEnumEnumInterfaceTracer::trace_callSetProp1(const ETbEnumEnum1& InProp1)
{
	nlohmann::json fields_;
	fields_["prop1"] = InProp1;
	Tracer::instance()->call("tb.enum/EnumInterface#_set", fields_);
}
void TbEnumEnumInterfaceTracer::trace_callSetProp2(const ETbEnumEnum2& InProp2)
{
	nlohmann::json fields_;
	fields_["prop2"] = InProp2;
	Tracer::instance()->call("tb.enum/EnumInterface#_set", fields_);
}
void TbEnumEnumInterfaceTracer::trace_callSetProp3(const ETbEnumEnum3& InProp3)
{
	nlohmann::json fields_;
	fields_["prop3"] = InProp3;
	Tracer::instance()->call("tb.enum/EnumInterface#_set", fields_);
}

void TbEnumEnumInterfaceTracer::trace_signalSig0(const ETbEnumEnum0& Param0)
{
	nlohmann::json fields_;
	fields_["param0"] = Param0;
	Tracer::instance()->signal("tb.enum/EnumInterface#sig0", fields_);
}

void TbEnumEnumInterfaceTracer::trace_signalSig1(const ETbEnumEnum1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->signal("tb.enum/EnumInterface#sig1", fields_);
}

void TbEnumEnumInterfaceTracer::trace_signalSig2(const ETbEnumEnum2& Param2)
{
	nlohmann::json fields_;
	fields_["param2"] = Param2;
	Tracer::instance()->signal("tb.enum/EnumInterface#sig2", fields_);
}

void TbEnumEnumInterfaceTracer::trace_signalSig3(const ETbEnumEnum3& Param3)
{
	nlohmann::json fields_;
	fields_["param3"] = Param3;
	Tracer::instance()->signal("tb.enum/EnumInterface#sig3", fields_);
}

void TbEnumEnumInterfaceTracer::trace_callFunc0(const ETbEnumEnum0& Param0)
{
	nlohmann::json fields_;
	fields_["param0"] = Param0;
	Tracer::instance()->call("tb.enum/EnumInterface#func0", fields_);
}

void TbEnumEnumInterfaceTracer::trace_callFunc1(const ETbEnumEnum1& Param1)
{
	nlohmann::json fields_;
	fields_["param1"] = Param1;
	Tracer::instance()->call("tb.enum/EnumInterface#func1", fields_);
}

void TbEnumEnumInterfaceTracer::trace_callFunc2(const ETbEnumEnum2& Param2)
{
	nlohmann::json fields_;
	fields_["param2"] = Param2;
	Tracer::instance()->call("tb.enum/EnumInterface#func2", fields_);
}

void TbEnumEnumInterfaceTracer::trace_callFunc3(const ETbEnumEnum3& Param3)
{
	nlohmann::json fields_;
	fields_["param3"] = Param3;
	Tracer::instance()->call("tb.enum/EnumInterface#func3", fields_);
}
