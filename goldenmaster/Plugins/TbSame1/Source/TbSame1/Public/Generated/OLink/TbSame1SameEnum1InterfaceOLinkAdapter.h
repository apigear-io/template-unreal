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

#include "TbSame1SameEnum1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UnrealOLinkHost.h"
#include "TbSame1SameEnum1InterfaceOLinkAdapter.generated.h"

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSame1SameEnum1InterfaceInterface
/// and holds the corresponding TbSame1SameEnum1InterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameEnum1InterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum1InterfaceOLinkAdapter();
	virtual ~UTbSame1SameEnum1InterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void setBackendService(TScriptInterface<ITbSame1SameEnum1InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnSig1(ETbSame1Enum1 Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbSame1Enum1 Prop1);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameEnum1Interface")
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSame1SameEnum1InterfaceOLinkSource> Source;
};
