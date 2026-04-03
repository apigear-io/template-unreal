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

#include "TbStructArray/Generated/api/TbStructArrayStructArrayFieldInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbStructArrayStructArrayFieldInterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbStructArrayStructArrayFieldInterfaceInterface
 * and holds the corresponding TbStructArrayStructArrayFieldInterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBSTRUCTARRAYOLINK_API UTbStructArrayStructArrayFieldInterfaceOLinkAdapter : public UGameInstanceSubsystem, public ITbStructArrayStructArrayFieldInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbStructArrayStructArrayFieldInterfaceOLinkAdapter();
	virtual ~UTbStructArrayStructArrayFieldInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	void setBackendService(TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnSigMixedSignal(const FTbStructArrayMixedStruct& ParamMixed);

	void OnSigStructArraySignal(const FTbStructArrayStructWithArrayOfStructs& ParamPoints);

	void OnPropStructArrayChanged(const FTbStructArrayStructWithArrayOfStructs& PropStructArray);

	void OnPropEnumArrayChanged(const FTbStructArrayStructWithArrayOfEnums& PropEnumArray);

	void OnPropIntArrayChanged(const FTbStructArrayStructWithArrayOfInts& PropIntArray);

	void OnPropMixedChanged(const FTbStructArrayMixedStruct& PropMixed);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbStructArray|StructArrayFieldInterface")
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbStructArrayStructArrayFieldInterfaceOLinkSource> Source;
};
