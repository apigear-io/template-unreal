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

#include "TbNamesNamEsInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OLinkHost.h"
#include "TbNamesNamEsOLinkAdapter.generated.h"

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbNamesNamEsInterface
/// and holds the corresponding TbNamesNamEsOLinkSource OLink source object
UCLASS(BlueprintType)
class TBNAMES_API UTbNamesNamEsOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsOLinkAdapter();
	virtual ~UTbNamesNamEsOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void setBackendService(TScriptInterface<ITbNamesNamEsInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomeSignal(bool bSomeParam);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomeSignal2(bool bSomeParam);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSwitchChanged(bool bSwitch);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomePropertyChanged(int32 SomeProperty);

	UFUNCTION(Category = "ApiGear|TbNames|NamEs", BlueprintInternalUseOnly)
	void OnSomePoperty2Changed(int32 SomePoperty2);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbNames|NamEs")
	TScriptInterface<ITbNamesNamEsInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbNamesNamEsOLinkSource> Source;
};
