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

#include "TbRefIfaces/Generated/api/TbRefIfacesParentIfInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>
#include "TbRefIfacesParentIfOLinkAdapter.generated.h"

class UOLinkHost;
namespace ApiGear
{
namespace ObjectLink
{
class RemoteRegistry;
}
} // namespace ApiGear

/** @brief handles the adaption between the service implementation and the OLink protocol
 * takes an object of the type ITbRefIfacesParentIfInterface
 * and holds the corresponding TbRefIfacesParentIfOLinkSource OLink source object
 */
UCLASS(BlueprintType)
class TBREFIFACESOLINK_API UTbRefIfacesParentIfOLinkAdapter : public UGameInstanceSubsystem, public ITbRefIfacesParentIfSubscriberInterface
{
	GENERATED_BODY()
public:
	explicit UTbRefIfacesParentIfOLinkAdapter();
	virtual ~UTbRefIfacesParentIfOLinkAdapter() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	void setBackendService(TScriptInterface<ITbRefIfacesParentIfInterface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf")
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

private:
	// signals
	void OnLocalIfSignalSignal(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);

	void OnLocalIfSignalListSignal(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param);

	void OnImportedIfSignalSignal(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);

	void OnImportedIfSignalListSignal(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param);

	void OnLocalIfChanged(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf);

	void OnLocalIfListChanged(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& LocalIfList);

	void OnImportedIfChanged(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf);

	void OnImportedIfListChanged(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& ImportedIfList);

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "ApiGear|TbRefIfaces|ParentIf")
	TScriptInterface<ITbRefIfacesParentIfInterface> BackendService;

	/** Holds the registry */
	TSharedPtr<ApiGear::ObjectLink::RemoteRegistry> Registry;

	/**
	holds the olink source interface implementation
	must be std::shared_ptr since it is expected by the olink protocol implementation
	*/
	std::shared_ptr<class TbRefIfacesParentIfOLinkSource> Source;
};
