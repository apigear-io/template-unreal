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

#include "Testbed2/Generated/api/Testbed2NestedStruct2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "Testbed2NestedStruct2InterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITestbed2NestedStruct2InterfaceInterface
 * and holds the corresponding Testbed2NestedStruct2InterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TESTBED2OLINK_API UTestbed2NestedStruct2InterfaceOLinkAdapter : public UGameInstanceSubsystem, public ITestbed2NestedStruct2InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NestedStruct2InterfaceOLinkAdapter();
	virtual ~UTestbed2NestedStruct2InterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void setBackendService(TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnSig1Signal(const FTestbed2NestedStruct1& Param1);

	void OnSig2Signal(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

	void OnProp2Changed(const FTestbed2NestedStruct2& Prop2);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed2|NestedStruct2Interface")
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class Testbed2NestedStruct2InterfaceOLinkSource> Source;
};
