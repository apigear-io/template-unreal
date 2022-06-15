// Copyright Epic Games, Inc. All Rights Reserved.

#include "ApiGearEditorCommands.h"

#define LOCTEXT_NAMESPACE "FApiGearEditorModule"

void FApiGearEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "ApiGear", "ApiGear Connection details", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
