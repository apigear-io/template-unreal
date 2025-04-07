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

#include "Generated/api/Testbed1StructArray2InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "Testbed1StructArray2InterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITestbed1StructArray2InterfaceInterface
 * and holds the corresponding Testbed1StructArray2InterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructArray2InterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArray2InterfaceOLinkAdapter();
	virtual ~UTestbed1StructArray2InterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void setBackendService(TScriptInterface<ITestbed1StructArray2InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnSigBool(const FTestbed1StructBoolWithArray& ParamBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnSigInt(const FTestbed1StructIntWithArray& ParamInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnSigFloat(const FTestbed1StructFloatWithArray& ParamFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnSigString(const FTestbed1StructStringWithArray& ParamString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(const FTestbed1StructBoolWithArray& PropBool);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnPropIntChanged(const FTestbed1StructIntWithArray& PropInt);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnPropFloatChanged(const FTestbed1StructFloatWithArray& PropFloat);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnPropStringChanged(const FTestbed1StructStringWithArray& PropString);

	UFUNCTION(Category = "ApiGear|Testbed1|StructArray2Interface", BlueprintInternalUseOnly)
	void OnPropEnumChanged(const FTestbed1StructEnumWithArray& PropEnum);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArray2Interface")
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class Testbed1StructArray2InterfaceOLinkSource> Source;
};
