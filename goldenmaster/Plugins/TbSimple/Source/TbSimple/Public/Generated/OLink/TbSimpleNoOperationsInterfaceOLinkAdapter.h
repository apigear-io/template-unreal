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

#include "TbSimpleNoOperationsInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OLinkHost.h"
#include "TbSimpleNoOperationsInterfaceOLinkAdapter.generated.h"

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbSimpleNoOperationsInterfaceInterface
/// and holds the corresponding TbSimpleNoOperationsInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoOperationsInterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoOperationsInterfaceOLinkAdapter();
	virtual ~UTbSimpleNoOperationsInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoOperationsInterface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropBoolChanged(bool bPropBool);

	UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface", BlueprintInternalUseOnly)
	void OnPropIntChanged(int32 PropInt);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoOperationsInterface")
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSimpleNoOperationsInterfaceOLinkSource> Source;
};
