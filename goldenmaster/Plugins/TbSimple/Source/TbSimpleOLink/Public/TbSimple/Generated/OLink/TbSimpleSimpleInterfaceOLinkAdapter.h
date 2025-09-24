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

#include "TbSimple/Generated/api/TbSimpleSimpleInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbSimpleSimpleInterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbSimpleSimpleInterfaceInterface
 * and holds the corresponding TbSimpleSimpleInterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBSIMPLEOLINK_API UTbSimpleSimpleInterfaceOLinkAdapter : public UGameInstanceSubsystem, public ITbSimpleSimpleInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceOLinkAdapter();
	virtual ~UTbSimpleSimpleInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnSigBoolSignal(bool bParamBool);

	void OnSigIntSignal(int32 ParamInt);

	void OnSigInt32Signal(int32 ParamInt32);

	void OnSigInt64Signal(int64 ParamInt64);

	void OnSigFloatSignal(float ParamFloat);

	void OnSigFloat32Signal(float ParamFloat32);

	void OnSigFloat64Signal(double ParamFloat64);

	void OnSigStringSignal(const FString& ParamString);

	void OnPropBoolChanged(bool bPropBool);

	void OnPropIntChanged(int32 PropInt);

	void OnPropInt32Changed(int32 PropInt32);

	void OnPropInt64Changed(int64 PropInt64);

	void OnPropFloatChanged(float PropFloat);

	void OnPropFloat32Changed(float PropFloat32);

	void OnPropFloat64Changed(double PropFloat64);

	void OnPropStringChanged(const FString& PropString);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleInterface")
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSimpleSimpleInterfaceOLinkSource> Source;
};
