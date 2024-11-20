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

#include "Generated/api/TbEnumEnumInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbEnumEnumInterfaceOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/// @brief handles the adaption between the service implementation and the OLink protocol
/// takes an object of the type ITbEnumEnumInterfaceInterface
/// and holds the corresponding TbEnumEnumInterfaceOLinkSource OLink source object
UCLASS(BlueprintType)
class TBENUM_API UTbEnumEnumInterfaceOLinkAdapter : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceOLinkAdapter();
	virtual ~UTbEnumEnumInterfaceOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig0(ETbEnumEnum0 Param0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig1(ETbEnumEnum1 Param1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig2(ETbEnumEnum2 Param2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnSig3(ETbEnumEnum3 Param3);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp0Changed(ETbEnumEnum0 Prop0);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp1Changed(ETbEnumEnum1 Prop1);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp2Changed(ETbEnumEnum2 Prop2);

	UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface", BlueprintInternalUseOnly)
	void OnProp3Changed(ETbEnumEnum3 Prop3);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbEnum|EnumInterface")
	TScriptInterface<ITbEnumEnumInterfaceInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbEnumEnumInterfaceOLinkSource> Source;
};
