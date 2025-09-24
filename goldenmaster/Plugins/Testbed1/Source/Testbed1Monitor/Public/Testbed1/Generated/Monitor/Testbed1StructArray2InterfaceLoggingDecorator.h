
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

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed1/Generated/api/AbstractTestbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArray2InterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1MONITOR_API UTestbed1StructArray2InterfaceLoggingDecorator : public UAbstractTestbed1StructArray2Interface, public ITestbed1StructArray2InterfaceSubscriberInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed1StructArray2InterfaceLoggingDecorator();
	virtual ~UTestbed1StructArray2InterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed1StructBoolWithArray GetPropBool() const override;

	void SetPropBool(const FTestbed1StructBoolWithArray& InPropBool) override;

	FTestbed1StructIntWithArray GetPropInt() const override;

	void SetPropInt(const FTestbed1StructIntWithArray& InPropInt) override;

	FTestbed1StructFloatWithArray GetPropFloat() const override;

	void SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat) override;

	FTestbed1StructStringWithArray GetPropString() const override;

	void SetPropString(const FTestbed1StructStringWithArray& InPropString) override;

	FTestbed1StructEnumWithArray GetPropEnum() const override;

	void SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool(const FTestbed1StructBoolWithArray& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt(const FTestbed1StructIntWithArray& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString(const FTestbed1StructStringWithArray& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArray2Interface")
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> BackendService;

	// signals
	void OnSigBoolSignal(const FTestbed1StructBoolWithArray& InParamBool);

	void OnSigIntSignal(const FTestbed1StructIntWithArray& InParamInt);

	void OnSigFloatSignal(const FTestbed1StructFloatWithArray& InParamFloat);

	void OnSigStringSignal(const FTestbed1StructStringWithArray& InParamString);

	void OnPropBoolChanged(const FTestbed1StructBoolWithArray& InPropBool);

	void OnPropIntChanged(const FTestbed1StructIntWithArray& InPropInt);

	void OnPropFloatChanged(const FTestbed1StructFloatWithArray& InPropFloat);

	void OnPropStringChanged(const FTestbed1StructStringWithArray& InPropString);

	void OnPropEnumChanged(const FTestbed1StructEnumWithArray& InPropEnum);
};
