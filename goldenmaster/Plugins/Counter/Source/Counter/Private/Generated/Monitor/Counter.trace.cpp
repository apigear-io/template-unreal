#include "Generated/Monitor/Counter.trace.h"
#include "Generated/api/Counter.json.adapter.h"
#include "CustomTypes/Private/Generated/api/CustomTypes.json.adapter.h"
#include "ExternTypes/Private/Generated/api/ExternTypes.json.adapter.h"
#include "tracer.h"

CounterCounterTracer::CounterCounterTracer()
{
}

void CounterCounterTracer::capture_state(UObject* Object, ICounterCounterInterface* obj)
{
	nlohmann::json fields_;
	fields_["vector"] = obj->Execute_GetVector(Object);
	fields_["extern_vector"] = obj->Execute_GetExternVector(Object);
	fields_["vectorArray"] = obj->Execute_GetVectorArray(Object);
	fields_["extern_vectorArray"] = obj->Execute_GetExternVectorArray(Object);
	Tracer::instance()->state("counter/Counter", fields_);
}
void CounterCounterTracer::trace_callSetVector(const FCustomTypesVector3D& InVector)
{
	nlohmann::json fields_;
	fields_["vector"] = InVector;
	Tracer::instance()->call("counter/Counter#_set", fields_);
}
void CounterCounterTracer::trace_callSetExternVector(const FVector& InExternVector)
{
	nlohmann::json fields_;
	fields_["extern_vector"] = InExternVector;
	Tracer::instance()->call("counter/Counter#_set", fields_);
}
void CounterCounterTracer::trace_callSetVectorArray(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	nlohmann::json fields_;
	fields_["vectorArray"] = InVectorArray;
	Tracer::instance()->call("counter/Counter#_set", fields_);
}
void CounterCounterTracer::trace_callSetExternVectorArray(const TArray<FVector>& InExternVectorArray)
{
	nlohmann::json fields_;
	fields_["extern_vectorArray"] = InExternVectorArray;
	Tracer::instance()->call("counter/Counter#_set", fields_);
}

void CounterCounterTracer::trace_signalValueChanged(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	nlohmann::json fields_;
	fields_["vector"] = Vector;
	fields_["extern_vector"] = ExternVector;
	fields_["vectorArray"] = VectorArray;
	fields_["extern_vectorArray"] = ExternVectorArray;
	Tracer::instance()->signal("counter/Counter#valueChanged", fields_);
}

void CounterCounterTracer::trace_callIncrement(const FVector& Vec)
{
	nlohmann::json fields_;
	fields_["vec"] = Vec;
	Tracer::instance()->call("counter/Counter#increment", fields_);
}

void CounterCounterTracer::trace_callIncrementArray(const TArray<FVector>& Vec)
{
	nlohmann::json fields_;
	fields_["vec"] = Vec;
	Tracer::instance()->call("counter/Counter#incrementArray", fields_);
}

void CounterCounterTracer::trace_callDecrement(const FCustomTypesVector3D& Vec)
{
	nlohmann::json fields_;
	fields_["vec"] = Vec;
	Tracer::instance()->call("counter/Counter#decrement", fields_);
}

void CounterCounterTracer::trace_callDecrementArray(const TArray<FCustomTypesVector3D>& Vec)
{
	nlohmann::json fields_;
	fields_["vec"] = Vec;
	Tracer::instance()->call("counter/Counter#decrementArray", fields_);
}
