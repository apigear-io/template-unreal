
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
#include "Testbed1/Generated/api/AbstractTestbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1MONITOR_API UTestbed1StructArrayInterfaceLoggingDecorator : public UAbstractTestbed1StructArrayInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed1StructArrayInterfaceLoggingDecorator();
	virtual ~UTestbed1StructArrayInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TArray<FTestbed1StructBool> GetPropBool() const override;

	void SetPropBool(const TArray<FTestbed1StructBool>& InPropBool) override;

	TArray<FTestbed1StructInt> GetPropInt() const override;

	void SetPropInt(const TArray<FTestbed1StructInt>& InPropInt) override;

	TArray<FTestbed1StructFloat> GetPropFloat() const override;

	void SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat) override;

	TArray<FTestbed1StructString> GetPropString() const override;

	void SetPropString(const TArray<FTestbed1StructString>& InPropString) override;

	TArray<ETestbed1Enum0> GetPropEnum() const override;

	void SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigBool(const TArray<FTestbed1StructBool>& InParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigInt(const TArray<FTestbed1StructInt>& InParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const TArray<FTestbed1StructFloat>& InParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigString(const TArray<FTestbed1StructString>& InParamString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnSigEnum(const TArray<ETestbed1Enum0>& InParamEnum);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const TArray<FTestbed1StructBool>& InPropBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const TArray<FTestbed1StructInt>& InPropInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& InPropFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const TArray<FTestbed1StructString>& InPropString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface", BlueprintInternalUseOnly)
	void OnPropEnumChanged(const TArray<ETestbed1Enum0>& InPropEnum);
};
