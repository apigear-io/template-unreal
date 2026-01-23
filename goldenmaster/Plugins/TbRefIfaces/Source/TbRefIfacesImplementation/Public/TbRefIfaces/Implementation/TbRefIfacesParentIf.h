
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

#include "CoreMinimal.h"
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesParentIf.h"
#include "TbRefIfacesParentIf.generated.h"

UCLASS(BlueprintType)
class TBREFIFACESIMPLEMENTATION_API UTbRefIfacesParentIfImplementation : public UAbstractTbRefIfacesParentIf
{
	GENERATED_BODY()
public:
	virtual ~UTbRefIfacesParentIfImplementation();

	// properties
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalIf() const override;
	void SetLocalIf(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> GetLocalIfList() const override;
	void SetLocalIfList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& LocalIfList) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImportedIf() const override;
	void SetImportedIf(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> GetImportedIfList() const override;
	void SetImportedIfList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& ImportedIfList) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|ParentIf|Properties")
	void _ResetProperties();

	// operations
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> LocalIfMethod(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param) override;

	TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> LocalIfMethodList(const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Param) override;

	TScriptInterface<ITbIfaceimportEmptyIfInterface> ImportedIfMethod(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param) override;

	TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ImportedIfMethodList(const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Param) override;

protected:
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	mutable FRWLock LocalIfRWLock;
	mutable FRWLock LocalIfListRWLock;
	mutable FRWLock ImportedIfRWLock;
	mutable FRWLock ImportedIfListRWLock;
#endif
};
