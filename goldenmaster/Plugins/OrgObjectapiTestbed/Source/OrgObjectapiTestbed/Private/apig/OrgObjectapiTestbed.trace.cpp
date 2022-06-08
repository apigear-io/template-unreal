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
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp1(bool bInProp1)
{
    nlohmann::json fields_;
    fields_["prop1"] = bInProp1;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp2(int32 InProp2)
{
    nlohmann::json fields_;
    fields_["prop2"] = InProp2;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp3(float InProp3)
{
    nlohmann::json fields_;
    fields_["prop3"] = InProp3;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp4(const FString& InProp4)
{
    nlohmann::json fields_;
    fields_["prop4"] = InProp4;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp5(const TArray<int32>& InProp5)
{
    nlohmann::json fields_;
    fields_["prop5"] = InProp5;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp6(const FOrgObjectapiTestbedStruct1& InProp6)
{
    nlohmann::json fields_;
    fields_["prop6"] = InProp6;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp7(int32 InProp7)
{
    nlohmann::json fields_;
    fields_["prop7"] = InProp7;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp10(const TArray<int32>& InProp10)
{
    nlohmann::json fields_;
    fields_["prop10"] = InProp10;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    nlohmann::json fields_;
    fields_["prop11"] = InProp11;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    nlohmann::json fields_;
    fields_["prop12"] = InProp12;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}
void OrgObjectapiTestbedInterface1Tracer::trace_callSetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    nlohmann::json fields_;
    fields_["prop14"] = InProp14;
    Tracer::instance()->call("org.objectapi.testbed/Interface1#_set", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_signalSig1()
{
    nlohmann::json fields_;
    Tracer::instance()->signal("org.objectapi.testbed/Interface1#sig1", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_signalSig2(int32 Step, const FString& Step2)
{
    nlohmann::json fields_;
    fields_["step"] = Step;
    fields_["step2"] = Step2;
    Tracer::instance()->signal("org.objectapi.testbed/Interface1#sig2", fields_);
}

void OrgObjectapiTestbedInterface1Tracer::trace_signalSig3(float Step)
{
    nlohmann::json fields_;
    fields_["step"] = Step;
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
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp200(int32 InProp200)
{
    nlohmann::json fields_;
    fields_["prop200"] = InProp200;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp201(int32 InProp201)
{
    nlohmann::json fields_;
    fields_["prop201"] = InProp201;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp202(int32 InProp202)
{
    nlohmann::json fields_;
    fields_["prop202"] = InProp202;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp203(float InProp203)
{
    nlohmann::json fields_;
    fields_["prop203"] = InProp203;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp204(float InProp204)
{
    nlohmann::json fields_;
    fields_["prop204"] = InProp204;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
void OrgObjectapiTestbedInterface2Tracer::trace_callSetProp205(const FString& InProp205)
{
    nlohmann::json fields_;
    fields_["prop205"] = InProp205;
    Tracer::instance()->call("org.objectapi.testbed/Interface2#_set", fields_);
}
