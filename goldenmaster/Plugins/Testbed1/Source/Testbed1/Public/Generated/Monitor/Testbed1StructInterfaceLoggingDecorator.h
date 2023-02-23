
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
#include "Testbed1StructInterfaceInterface.h"
#include "Testbed1StructInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1_API UTestbed1StructInterfaceLoggingDecorator : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed1StructInterfaceLoggingDecorator();
	virtual ~UTestbed1StructInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void setBackendService(TScriptInterface<ITestbed1StructInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed1StructBool GetPropBool_Implementation() const override;

	void SetPropBool_Implementation(const FTestbed1StructBool& InPropBool) override;

	FTestbed1StructInt GetPropInt_Implementation() const override;

	void SetPropInt_Implementation(const FTestbed1StructInt& InPropInt) override;

	FTestbed1StructFloat GetPropFloat_Implementation() const override;

	void SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat) override;

	FTestbed1StructString GetPropString_Implementation() const override;

	void SetPropString_Implementation(const FTestbed1StructString& InPropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructBool& ParamBool) override;
	FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const FTestbed1StructInt& ParamInt) override;
	FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructFloat& Result, const FTestbed1StructFloat& ParamFloat) override;
	FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructString& Result, const FTestbed1StructString& ParamString) override;
	FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override;

	bool IsInitialized() const
	{
		return bInitialized;
	}

private:
	bool bInitialized = false;
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructInterface")
	TScriptInterface<ITestbed1StructInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigBool(const FTestbed1StructBool& ParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigInt(const FTestbed1StructInt& ParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigFloat(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnSigString(const FTestbed1StructString& ParamString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const FTestbed1StructBool& InPropBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const FTestbed1StructInt& InPropInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const FTestbed1StructFloat& InPropFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructInterface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FTestbed1StructString& InPropString);
};
