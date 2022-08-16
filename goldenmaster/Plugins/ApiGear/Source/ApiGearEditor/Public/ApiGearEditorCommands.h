// Copyright Epic Games, Inc. All Rights Reserved.

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