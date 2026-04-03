#include "TbStructArray.trace.h"
#include "TbStructArray/Generated/api/TbStructArray.json.adapter.h"
#include "tracer.h"

TbStructArrayStructArrayFieldInterfaceTracer::TbStructArrayStructArrayFieldInterfaceTracer()
{
}

void TbStructArrayStructArrayFieldInterfaceTracer::capture_state(UObject* Object, ITbStructArrayStructArrayFieldInterfaceInterface* obj)
{
	nlohmann::json fields_;
	fields_["propStructArray"] = obj->GetPropStructArray();
	fields_["propEnumArray"] = obj->GetPropEnumArray();
	fields_["propIntArray"] = obj->GetPropIntArray();
	fields_["propMixed"] = obj->GetPropMixed();
	Tracer::instance()->state("tb.struct.array/StructArrayFieldInterface", fields_);
}
void TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	nlohmann::json fields_;
	fields_["propStructArray"] = InPropStructArray;
	Tracer::instance()->call("tb.struct.array/StructArrayFieldInterface#_set", fields_);
}
void TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	nlohmann::json fields_;
	fields_["propEnumArray"] = InPropEnumArray;
	Tracer::instance()->call("tb.struct.array/StructArrayFieldInterface#_set", fields_);
}
void TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	nlohmann::json fields_;
	fields_["propIntArray"] = InPropIntArray;
	Tracer::instance()->call("tb.struct.array/StructArrayFieldInterface#_set", fields_);
}
void TbStructArrayStructArrayFieldInterfaceTracer::trace_callSetPropMixed(const FTbStructArrayMixedStruct& InPropMixed)
{
	nlohmann::json fields_;
	fields_["propMixed"] = InPropMixed;
	Tracer::instance()->call("tb.struct.array/StructArrayFieldInterface#_set", fields_);
}

void TbStructArrayStructArrayFieldInterfaceTracer::trace_signalSigMixed(const FTbStructArrayMixedStruct& ParamMixed)
{
	nlohmann::json fields_;
	fields_["paramMixed"] = ParamMixed;
	Tracer::instance()->signal("tb.struct.array/StructArrayFieldInterface#sigMixed", fields_);
}

void TbStructArrayStructArrayFieldInterfaceTracer::trace_signalSigStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	nlohmann::json fields_;
	fields_["paramPoints"] = ParamPoints;
	Tracer::instance()->signal("tb.struct.array/StructArrayFieldInterface#sigStructArray", fields_);
}

void TbStructArrayStructArrayFieldInterfaceTracer::trace_callFuncMixed(const FTbStructArrayMixedStruct& ParamMixed)
{
	nlohmann::json fields_;
	fields_["paramMixed"] = ParamMixed;
	Tracer::instance()->call("tb.struct.array/StructArrayFieldInterface#funcMixed", fields_);
}

void TbStructArrayStructArrayFieldInterfaceTracer::trace_callFuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	nlohmann::json fields_;
	fields_["paramPoints"] = ParamPoints;
	Tracer::instance()->call("tb.struct.array/StructArrayFieldInterface#funcStructArray", fields_);
}
