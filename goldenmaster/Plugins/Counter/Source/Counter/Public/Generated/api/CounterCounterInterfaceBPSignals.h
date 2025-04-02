/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "UObject/Interface.h"
#include "Generated/api/Counter_data.h"
#include "Generated/api/CustomTypes_data.h"
#include "Generated/api/ExternTypes_data.h"
#include "CounterCounterInterfaceBPSignals.generated.h"

/**
 * Helper interface for CounterCounter events.
 * Intended for Blueprint-only use. Functions are dispatched via message calls.
 * Does contain signal events, property-changed events and void-function events only.
 */
UINTERFACE(BlueprintType)
class UCounterCounterBPSignalsInterface : public UInterface
{
	GENERATED_BODY()
};

class COUNTER_API ICounterCounterBPSignalsInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Counter|Counter|Signals", DisplayName = "On ValueChanged Signal")
	void OnValueChangedSignal(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Counter|Counter|Signals", DisplayName = "On Property Vector Changed")
	void OnVectorChanged(UPARAM(DisplayName = "Vector") const FCustomTypesVector3D& InVector);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Counter|Counter|Signals", DisplayName = "On Property ExternVector Changed")
	void OnExternVectorChanged(UPARAM(DisplayName = "ExternVector") const FVector& InExternVector);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Counter|Counter|Signals", DisplayName = "On Property VectorArray Changed")
	void OnVectorArrayChanged(UPARAM(DisplayName = "VectorArray") const TArray<FCustomTypesVector3D>& InVectorArray);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "ApiGear Helper|Counter|Counter|Signals", DisplayName = "On Property ExternVectorArray Changed")
	void OnExternVectorArrayChanged(UPARAM(DisplayName = "ExternVectorArray") const TArray<FVector>& InExternVectorArray);
};
