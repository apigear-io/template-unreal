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

#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "Testbed1StructArrayInterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITestbed1StructArrayInterfaceInterface
 * and holds the corresponding Testbed1StructArrayInterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TESTBED1OLINK_API UTestbed1StructArrayInterfaceOLinkAdapter : public UGameInstanceSubsystem, public ITestbed1StructArrayInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceOLinkAdapter();
	virtual ~UTestbed1StructArrayInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnSigBoolSignal(const TArray<FTestbed1StructBool>& ParamBool);

	void OnSigIntSignal(const TArray<FTestbed1StructInt>& ParamInt);

	void OnSigFloatSignal(const TArray<FTestbed1StructFloat>& ParamFloat);

	void OnSigStringSignal(const TArray<FTestbed1StructString>& ParamString);

	void OnSigEnumSignal(const TArray<ETestbed1Enum0>& ParamEnum);

	void OnPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool);

	void OnPropIntChanged(const TArray<FTestbed1StructInt>& PropInt);

	void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat);

	void OnPropStringChanged(const TArray<FTestbed1StructString>& PropString);

	void OnPropEnumChanged(const TArray<ETestbed1Enum0>& PropEnum);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|Testbed1|StructArrayInterface")
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class Testbed1StructArrayInterfaceOLinkSource> Source;
};
