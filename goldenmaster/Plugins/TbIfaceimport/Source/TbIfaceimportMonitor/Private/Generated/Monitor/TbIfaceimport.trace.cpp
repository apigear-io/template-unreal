#include "TbIfaceimport.trace.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport.json.adapter.h"
#include "tracer.h"

TbIfaceimportEmptyIfTracer::TbIfaceimportEmptyIfTracer()
{
}

void TbIfaceimportEmptyIfTracer::capture_state(UObject* Object, ITbIfaceimportEmptyIfInterface* obj)
{
	nlohmann::json fields_;
	Tracer::instance()->state("tb.ifaceimport/EmptyIf", fields_);
}
