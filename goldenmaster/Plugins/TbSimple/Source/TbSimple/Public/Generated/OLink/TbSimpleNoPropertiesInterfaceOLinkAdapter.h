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

#include "TbSimpleNoPropertiesInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UnrealOLinkHost.h"
#include "TbSimpleNoPropertiesInterfaceOLinkAdapter.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoPropertiesInterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoPropertiesInterfaceOLinkAdapter();
	virtual ~UTbSimpleNoPropertiesInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	void setBackendService(TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	void setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface", BlueprintInternalUseOnly)
	void OnSigVoid();

	UFUNCTION(Category = "ApiGear|TbSimple|NoPropertiesInterface", BlueprintInternalUseOnly)
	void OnSigBool(bool bParamBool);

	/** The connection to the service backend. */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|NoPropertiesInterface")
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> BackendService;

	/**
	shared pointer to the source implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSimpleNoPropertiesInterfaceOLinkSource> Source;
};
