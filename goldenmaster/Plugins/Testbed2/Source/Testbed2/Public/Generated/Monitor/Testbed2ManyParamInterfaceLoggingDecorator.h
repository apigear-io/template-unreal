
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
#include "Testbed2/Generated/api/AbstractTestbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterfaceLoggingDecorator.generated.h"

// General Log
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterfaceLoggingDecorator, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceLoggingDecorator : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()

public:
	explicit UTestbed2ManyParamInterfaceLoggingDecorator();
	virtual ~UTestbed2ManyParamInterfaceLoggingDecorator();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService);

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	int32 GetProp1_Implementation() const override;

	void SetProp1_Implementation(int32 InProp1) override;

	int32 GetProp2_Implementation() const override;

	void SetProp2_Implementation(int32 InProp2) override;

	int32 GetProp3_Implementation() const override;

	void SetProp3_Implementation(int32 InProp3) override;

	int32 GetProp4_Implementation() const override;

	void SetProp4_Implementation(int32 InProp4) override;

	// operations
	int32 Func1_Implementation(int32 Param1) override;

	int32 Func2_Implementation(int32 Param1, int32 Param2) override;

	int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

private:
	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> BackendService;

	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig1(int32 InParam1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig2(int32 InParam1, int32 InParam2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig3(int32 InParam1, int32 InParam2, int32 InParam3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig4(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(int32 InProp1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(int32 InProp2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(int32 InProp3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp4Changed(int32 InProp4);
};
