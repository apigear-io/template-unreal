#pragma once

#include "TbStructArray/Generated/api/TbStructArray_apig.h"

class TbStructArrayStructArrayFieldInterfaceTracer
{
public:
	TbStructArrayStructArrayFieldInterfaceTracer();
	static void capture_state(UObject* Object, ITbStructArrayStructArrayFieldInterfaceInterface* obj);
	static void trace_callSetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray);
	static void trace_callSetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray);
	static void trace_callSetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray);
	static void trace_callSetPropMixed(const FTbStructArrayMixedStruct& InPropMixed);
	static void trace_signalSigMixed(const FTbStructArrayMixedStruct& ParamMixed);
	static void trace_signalSigStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints);
	static void trace_callFuncMixed(const FTbStructArrayMixedStruct& ParamMixed);
	static void trace_callFuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints);
};
