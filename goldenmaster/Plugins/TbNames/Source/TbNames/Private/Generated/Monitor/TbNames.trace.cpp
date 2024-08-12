#include "TbNames.trace.h"
#include "Generated/api/TbNames.json.adapter.h"
#include "tracer.h"

TbNamesNamEsTracer::TbNamesNamEsTracer()
{
}

void TbNamesNamEsTracer::capture_state(UObject* Object, ITbNamesNamEsInterface* obj)
{
	nlohmann::json fields_;
	fields_["Switch"] = obj->Execute_GetSwitch(Object);
	fields_["SOME_PROPERTY"] = obj->Execute_GetSomeProperty(Object);
	fields_["Some_Poperty2"] = obj->Execute_GetSomePoperty2(Object);
	Tracer::instance()->state("tb.names/Nam_Es", fields_);
}
void TbNamesNamEsTracer::trace_callSetSwitch(bool bInSwitch)
{
	nlohmann::json fields_;
	fields_["Switch"] = bInSwitch;
	Tracer::instance()->call("tb.names/Nam_Es#_set", fields_);
}
void TbNamesNamEsTracer::trace_callSetSomeProperty(int32 InSomeProperty)
{
	nlohmann::json fields_;
	fields_["SOME_PROPERTY"] = InSomeProperty;
	Tracer::instance()->call("tb.names/Nam_Es#_set", fields_);
}
void TbNamesNamEsTracer::trace_callSetSomePoperty2(int32 InSomePoperty2)
{
	nlohmann::json fields_;
	fields_["Some_Poperty2"] = InSomePoperty2;
	Tracer::instance()->call("tb.names/Nam_Es#_set", fields_);
}

void TbNamesNamEsTracer::trace_signalSomeSignal(bool bSomeParam)
{
	nlohmann::json fields_;
	fields_["SOME_PARAM"] = bSomeParam;
	Tracer::instance()->signal("tb.names/Nam_Es#SOME_SIGNAL", fields_);
}

void TbNamesNamEsTracer::trace_signalSomeSignal2(bool bSomeParam)
{
	nlohmann::json fields_;
	fields_["Some_Param"] = bSomeParam;
	Tracer::instance()->signal("tb.names/Nam_Es#Some_Signal2", fields_);
}

void TbNamesNamEsTracer::trace_callSomeFunction(bool bSomeParam)
{
	nlohmann::json fields_;
	fields_["SOME_PARAM"] = bSomeParam;
	Tracer::instance()->call("tb.names/Nam_Es#SOME_FUNCTION", fields_);
}

void TbNamesNamEsTracer::trace_callSomeFunction2(bool bSomeParam)
{
	nlohmann::json fields_;
	fields_["Some_Param"] = bSomeParam;
	Tracer::instance()->call("tb.names/Nam_Es#Some_Function2", fields_);
}
