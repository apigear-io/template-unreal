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

#include "Testbed2ManyParamInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UnrealOLinkHost.h"
#include "Testbed2ManyParamInterfaceOLinkAdapter.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceOLinkAdapter();
	virtual ~UTestbed2ManyParamInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig1(int32 Param1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig2(int32 Param1, int32 Param2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig3(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(int32 Prop1);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(int32 Prop2);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(int32 Prop3);

	UFUNCTION(Category = "ApiGear|Testbed2|ManyParamInterface", BlueprintInternalUseOnly)
	void OnProp4Changed(int32 Prop4);

	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|ManyParamInterface")
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> BackendService;

	/**
	shared pointer to the source implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class Testbed2ManyParamInterfaceOLinkSource> Source;
};
