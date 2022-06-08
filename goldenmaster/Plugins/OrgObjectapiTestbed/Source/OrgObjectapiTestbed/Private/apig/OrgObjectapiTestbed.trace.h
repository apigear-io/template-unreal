#pragma once

#include "OrgObjectapiTestbed_apig.h"

class OrgObjectapiTestbedInterface1Tracer
{
public:
  OrgObjectapiTestbedInterface1Tracer();
  static void capture_state(IOrgObjectapiTestbedInterface1Interface* obj);
  static void trace_callSetProp1(bool bInProp1);
  static void trace_callSetProp2(int32 InProp2);
  static void trace_callSetProp3(float InProp3);
  static void trace_callSetProp4(const FString& InProp4);
  static void trace_callSetProp5(const TArray<int32>& InProp5);
  static void trace_callSetProp6(const FStruct1& InProp6);
  static void trace_callSetProp7(int32 InProp7);
  static void trace_callSetProp10(const TArray<int32>& InProp10);
  static void trace_callSetProp11(const TArray<FStruct1>& InProp11);
  static void trace_callSetProp12(const TArray<EEnum1>& InProp12);
  static void trace_callSetProp14(const TArray<FStruct1>& InProp14);
  static void trace_signalSig1();
  static void trace_signalSig2(int32 Step, const FString& Step2);
  static void trace_signalSig3(float Step);
  static void trace_callOp1();
  static void trace_callOp2(int32 Step);
  static void trace_callOp3();
};

class OrgObjectapiTestbedInterface2Tracer
{
public:
  OrgObjectapiTestbedInterface2Tracer();
  static void capture_state(IOrgObjectapiTestbedInterface2Interface* obj);
  static void trace_callSetProp200(int32 InProp200);
  static void trace_callSetProp201(int32 InProp201);
  static void trace_callSetProp202(int32 InProp202);
  static void trace_callSetProp203(float InProp203);
  static void trace_callSetProp204(float InProp204);
  static void trace_callSetProp205(const FString& InProp205);
};
