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

#include "TbSame2/Generated/api/TbSame2SameStruct1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbSame2SameStruct1InterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbSame2SameStruct1InterfaceInterface
 * and holds the corresponding TbSame2SameStruct1InterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBSAME2OLINK_API UTbSame2SameStruct1InterfaceOLinkAdapter : public UGameInstanceSubsystem, public ITbSame2SameStruct1InterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct1InterfaceOLinkAdapter();
	virtual ~UTbSame2SameStruct1InterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface")
	void setBackendService(TScriptInterface<ITbSame2SameStruct1InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct1Interface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnSig1Signal(const FTbSame2Struct1& Param1);

	void OnProp1Changed(const FTbSame2Struct1& Prop1);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame2|SameStruct1Interface")
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSame2SameStruct1InterfaceOLinkSource> Source;
};
