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

#include "TbSame2Editor.h"
#include "ISettingsModule.h"
#include "TbSame2Settings.h"

#define LOCTEXT_NAMESPACE "TbSame2Editor"

void FTbSame2EditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear TbSame2", LOCTEXT("TbSame2SettingsName", "ApiGear TbSame2"), LOCTEXT("TbSame2SettingsDescription", "Project settings for ApiGear TbSame2 plugin"), GetMutableDefault<UTbSame2Settings>());
	}
}

void FTbSame2EditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear TbSame2");
	}
}

IMPLEMENT_MODULE(FTbSame2EditorModule, TbSame2Editor)

#undef LOCTEXT_NAMESPACE
