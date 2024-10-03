#pragma once

#include "Counter/Generated/api/Counter_apig.h"

class CounterCounterTracer
{
public:
	CounterCounterTracer();
	static void capture_state(UObject* Object, ICounterCounterInterface* obj);
	static void trace_callSetVector(const FCustomTypesVector3D& InVector);
	static void trace_callSetExternVector(const FVector& InExternVector);
	static void trace_callSetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray);
	static void trace_callSetExternVectorArray(const TArray<FVector>& InExternVectorArray);
	static void trace_signalValueChanged(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);
	static void trace_callIncrement(const FVector& Vec);
	static void trace_callIncrementArray(const TArray<FVector>& Vec);
	static void trace_callDecrement(const FCustomTypesVector3D& Vec);
	static void trace_callDecrementArray(const TArray<FCustomTypesVector3D>& Vec);
};
