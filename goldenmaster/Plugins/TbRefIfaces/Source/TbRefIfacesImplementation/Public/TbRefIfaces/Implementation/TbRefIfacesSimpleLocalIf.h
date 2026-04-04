// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbRefIfaces/Generated/api/AbstractTbRefIfacesSimpleLocalIf.h"
#include "TbRefIfacesSimpleLocalIf.generated.h"

UCLASS(BlueprintType)
class TBREFIFACESIMPLEMENTATION_API UTbRefIfacesSimpleLocalIfImplementation : public UAbstractTbRefIfacesSimpleLocalIf
{
	GENERATED_BODY()
public:
	virtual ~UTbRefIfacesSimpleLocalIfImplementation();

	// properties
	int32 GetIntProperty() const override;
	void SetIntProperty(int32 IntProperty) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbRefIfaces|SimpleLocalIf|Properties")
	void _ResetProperties();

	// operations
	int32 IntMethod(int32 Param) override;
};
