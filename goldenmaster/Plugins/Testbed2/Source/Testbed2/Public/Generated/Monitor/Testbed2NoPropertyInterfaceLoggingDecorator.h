
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
#include "Testbed2NoPropertyInterfaceInterface.h"
#include "Testbed2NoPropertyInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NoPropertyInterfaceLoggingDecorator, Log, All);

UCLASS(BlueprintType, Blueprintable)
class TESTBED2_API UTestbed2NoPropertyInterfaceLoggingDecorator : public UGameInstanceSubsystem, public ITestbed2NoPropertyInterfaceInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2NoPropertyInterfaceLoggingDecorator();
	virtual ~UTestbed2NoPropertyInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NoPropertyInterface")
	void setBackendService(TScriptInterface<ITestbed2NoPropertyInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed2|NoPropertyInterface", DisplayName = "Sig1 Signal")
	FTestbed2NoPropertyInterfaceSig1Delegate Sig1Signal;
	FTestbed2NoPropertyInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	// properties
	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override;
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NoPropertyInterface")
	TScriptInterface<ITestbed2NoPropertyInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|NoPropertyInterface", BlueprintInternalUseOnly)
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	// properties - local copy
};
