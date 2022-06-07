#include "OrgObjectapiTestbed.trace.h"
#include "OrgObjectapiTestbed.json.adapter.h"
#include "tracer.h"

OrgObjectapiTestbedInterface1Tracer::OrgObjectapiTestbedInterface1Tracer()
{
}

void OrgObjectapiTestbedInterface1Tracer::capture_state(IOrgObjectapiTestbedInterface1Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop1"] = obj->GetProp1();
    fields_["prop2"] = obj->GetProp2();
    fields_["prop3"] = obj->GetProp3();
    fields_["prop4"] = obj->GetProp4();
    fields_["prop5"] = obj->GetProp5();
    fields_["prop6"] = obj->GetProp6();
    fields_["prop7"] = obj->GetProp7();
    fields_["prop10"] = obj->GetProp10();
    fields_["prop11"] = obj->GetProp11();
    fields_["prop12"] = obj->GetProp12();
    fields_["prop14"] = obj->GetProp14();
    Tracer::instance()->state("org.objectapi.testbed/Interface1", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp1(bool Value)
{
    nlohmann::json fields_;
    fields_["prop1"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp2(int32 Value)
{
    nlohmann::json fields_;
    fields_["prop2"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp3(float Value)
{
    nlohmann::json fields_;
    fields_["prop3"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp4(FString Value)
{
    nlohmann::json fields_;
    fields_["prop4"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp5(const TArray<int32>& Value)
{
    nlohmann::json fields_;
    fields_["prop5"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp6(const FStruct1& Value)
{
    nlohmann::json fields_;
    fields_["prop6"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp7(int32 Value)
{
    nlohmann::json fields_;
    fields_["prop7"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp10(const TArray<int32>& Value)
{
    nlohmann::json fields_;
    fields_["prop10"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp11(const TArray<FStruct1>& Value)
{
    nlohmann::json fields_;
    fields_["prop11"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp12(const TArray<EEnum1>& Value)
{
    nlohmann::json fields_;
    fields_["prop12"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp14(const TArray<FStruct1>& Value)
{
    nlohmann::json fields_;
    fields_["prop14"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_signalSig1()
{
    nlohmann::json fields_;
    Tracer::instance()->signal("org.objectapi.testbed/Interface1#sig1", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_signalSig2(int32 Step)
{
    nlohmann::json fields_;
    fields_["step"] = Step;
    Tracer::instance()->signal("org.objectapi.testbed/Interface1#sig2", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_signalSig3()
{
    nlohmann::json fields_;
    Tracer::instance()->signal("org.objectapi.testbed/Interface1#sig3", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_callOp1()
{
    nlohmann::json fields_;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#op1", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_callOp2(int32 Step)
{
    nlohmann::json fields_;
    fields_["step"] = Step;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#op2", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_callOp3()
{
    nlohmann::json fields_;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#op3", fields_);
}

OrgObjectapiTestbedInterface2Tracer::OrgObjectapiTestbedInterface2Tracer()
{
}

void OrgObjectapiTestbedInterface2Tracer::capture_state(IOrgObjectapiTestbedInterface2Interface* obj)
{
    nlohmann::json fields_;
    fields_["prop200"] = obj->GetProp200();
    fields_["prop201"] = obj->GetProp201();
    fields_["prop202"] = obj->GetProp202();
    fields_["prop203"] = obj->GetProp203();
    fields_["prop204"] = obj->GetProp204();
    fields_["prop205"] = obj->GetProp205();
    Tracer::instance()->state("org.objectapi.testbed/Interface2", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp200(int32 Value)
{
    nlohmann::json fields_;
    fields_["prop200"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp201(int32 Value)
{
    nlohmann::json fields_;
    fields_["prop201"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp202(int32 Value)
{
    nlohmann::json fields_;
    fields_["prop202"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp203(float Value)
{
    nlohmann::json fields_;
    fields_["prop203"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp204(float Value)
{
    nlohmann::json fields_;
    fields_["prop204"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp205(FString Value)
{
    nlohmann::json fields_;
    fields_["prop205"] = Value;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
