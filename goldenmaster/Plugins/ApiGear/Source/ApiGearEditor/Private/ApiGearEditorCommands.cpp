// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "ApiGearEditorCommands.h"

#define LOCTEXT_NAMESPACE "FApiGearEditorModule"

void FApiGearEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "ApiGear", "ApiGear Connection details", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
