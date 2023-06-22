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

#include "TbSame1SameStruct1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UnrealOLinkHost.h"
#include "TbSame1SameStruct1InterfaceOLinkAdapter.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameStruct1InterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct1InterfaceOLinkAdapter();
	virtual ~UTbSame1SameStruct1InterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	void setBackendService(TScriptInterface<ITbSame1SameStruct1InterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameStruct1Interface")
	void setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct1Interface", BlueprintInternalUseOnly)
	void OnSig1(const FTbSame1Struct1& Param1);

	UFUNCTION(Category = "ApiGear|TbSame1|SameStruct1Interface", BlueprintInternalUseOnly)
	void OnProp1Changed(const FTbSame1Struct1& Prop1);

	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSame1|SameStruct1Interface")
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> BackendService;

	/**
	shared pointer to the source implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSame1SameStruct1InterfaceOLinkSource> Source;
};
