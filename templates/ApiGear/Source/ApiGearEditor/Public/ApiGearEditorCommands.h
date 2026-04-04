// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ApiGearEditorStyle.h"

class FApiGearEditorCommands : public TCommands<FApiGearEditorCommands>
{
public:
	FApiGearEditorCommands()
		: TCommands<FApiGearEditorCommands>(TEXT("ApiGear"), NSLOCTEXT("Contexts", "ApiGear", "ApiGear Plugin"), NAME_None, FApiGearEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenPluginWindow;
};