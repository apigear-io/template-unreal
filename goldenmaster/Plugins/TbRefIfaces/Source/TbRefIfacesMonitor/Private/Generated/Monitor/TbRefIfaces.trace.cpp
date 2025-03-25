#include "TbRefIfaces.trace.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces.json.adapter.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport.json.adapter.h"
#include "tracer.h"

TbRefIfacesSimpleLocalIfTracer::TbRefIfacesSimpleLocalIfTracer()
{
}

void TbRefIfacesSimpleLocalIfTracer::capture_state(UObject* Object, ITbRefIfacesSimpleLocalIfInterface* obj)
{
	nlohmann::json fields_;
	fields_["intProperty"] = obj->GetIntProperty();
	Tracer::instance()->state("tb.ref_ifaces/SimpleLocalIf", fields_);
}
void TbRefIfacesSimpleLocalIfTracer::trace_callSetIntProperty(int32 InIntProperty)
{
	nlohmann::json fields_;
	fields_["intProperty"] = InIntProperty;
	Tracer::instance()->call("tb.ref_ifaces/SimpleLocalIf#_set", fields_);
}

void TbRefIfacesSimpleLocalIfTracer::trace_signalIntSignal(int32 Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->signal("tb.ref_ifaces/SimpleLocalIf#intSignal", fields_);
}

void TbRefIfacesSimpleLocalIfTracer::trace_callIntMethod(int32 Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->call("tb.ref_ifaces/SimpleLocalIf#intMethod", fields_);
}

TbRefIfacesParentIfTracer::TbRefIfacesParentIfTracer()
{
}

void TbRefIfacesParentIfTracer::capture_state(UObject* Object, ITbRefIfacesParentIfInterface* obj)
{
	nlohmann::json fields_;
	fields_["localIf"] = obj->GetLocalIf();
	fields_["importedIf"] = obj->GetImportedIf();
	Tracer::instance()->state("tb.ref_ifaces/ParentIf", fields_);
}
void TbRefIfacesParentIfTracer::trace_callSetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InLocalIf)
{
	nlohmann::json fields_;
	fields_["localIf"] = InLocalIf;
	Tracer::instance()->call("tb.ref_ifaces/ParentIf#_set", fields_);
}
void TbRefIfacesParentIfTracer::trace_callSetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InImportedIf)
{
	nlohmann::json fields_;
	fields_["importedIf"] = InImportedIf;
	Tracer::instance()->call("tb.ref_ifaces/ParentIf#_set", fields_);
}

void TbRefIfacesParentIfTracer::trace_signalLocalIfSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->signal("tb.ref_ifaces/ParentIf#localIfSignal", fields_);
}

void TbRefIfacesParentIfTracer::trace_signalImportedIfSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->signal("tb.ref_ifaces/ParentIf#importedIfSignal", fields_);
}

void TbRefIfacesParentIfTracer::trace_callLocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->call("tb.ref_ifaces/ParentIf#localIfMethod", fields_);
}

void TbRefIfacesParentIfTracer::trace_callImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param)
{
	nlohmann::json fields_;
	fields_["param"] = Param;
	Tracer::instance()->call("tb.ref_ifaces/ParentIf#importedIfMethod", fields_);
}
