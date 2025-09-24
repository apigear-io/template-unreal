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

#include "TbSimple/Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbSimpleSimpleArrayInterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbSimpleSimpleArrayInterfaceInterface
 * and holds the corresponding TbSimpleSimpleArrayInterfaceOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBSIMPLEOLINK_API UTbSimpleSimpleArrayInterfaceOLinkAdapter : public UGameInstanceSubsystem, public ITbSimpleSimpleArrayInterfaceSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceOLinkAdapter();
	virtual ~UTbSimpleSimpleArrayInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnSigBoolSignal(const TArray<bool>& ParamBool);

	void OnSigIntSignal(const TArray<int32>& ParamInt);

	void OnSigInt32Signal(const TArray<int32>& ParamInt32);

	void OnSigInt64Signal(const TArray<int64>& ParamInt64);

	void OnSigFloatSignal(const TArray<float>& ParamFloat);

	void OnSigFloat32Signal(const TArray<float>& ParamFloa32);

	void OnSigFloat64Signal(const TArray<double>& ParamFloat64);

	void OnSigStringSignal(const TArray<FString>& ParamString);

	void OnPropBoolChanged(const TArray<bool>& PropBool);

	void OnPropIntChanged(const TArray<int32>& PropInt);

	void OnPropInt32Changed(const TArray<int32>& PropInt32);

	void OnPropInt64Changed(const TArray<int64>& PropInt64);

	void OnPropFloatChanged(const TArray<float>& PropFloat);

	void OnPropFloat32Changed(const TArray<float>& PropFloat32);

	void OnPropFloat64Changed(const TArray<double>& PropFloat64);

	void OnPropStringChanged(const TArray<FString>& PropString);

	void OnPropReadOnlyStringChanged(const FString& PropReadOnlyString);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbSimpleSimpleArrayInterfaceOLinkSource> Source;
};
