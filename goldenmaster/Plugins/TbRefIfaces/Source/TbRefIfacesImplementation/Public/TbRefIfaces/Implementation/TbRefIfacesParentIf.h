// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
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
};
