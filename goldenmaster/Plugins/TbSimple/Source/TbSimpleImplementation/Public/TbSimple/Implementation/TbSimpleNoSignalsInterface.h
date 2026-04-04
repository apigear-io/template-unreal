// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "CoreMinimal.h"
#include "TbSimple/Generated/api/AbstractTbSimpleNoSignalsInterface.h"
#include "TbSimpleNoSignalsInterface.generated.h"

UCLASS(BlueprintType)
class TBSIMPLEIMPLEMENTATION_API UTbSimpleNoSignalsInterfaceImplementation : public UAbstractTbSimpleNoSignalsInterface
{
	GENERATED_BODY()
public:
	virtual ~UTbSimpleNoSignalsInterfaceImplementation();

	// properties
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	/**
	 * Resets all properties to the default values.
	 * Broadcasts property changed delegates if property value change.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|NoSignalsInterface|Properties")
	void _ResetProperties();

	// operations
	void FuncVoid() override;

	bool FuncBool(bool bParamBool) override;
};
