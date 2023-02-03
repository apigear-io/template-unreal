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

#include "TbSame1Editor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "TbSame1Settings.h"
#include "TbSame1ConnectionSettings.h"

#define LOCTEXT_NAMESPACE "TbSame1Editor"

void FTbSame1EditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear TbSame1", LOCTEXT("TbSame1SettingsName", "ApiGear TbSame1"), LOCTEXT("TbSame1SettingsDescription", "Project settings for ApiGear TbSame1 plugin"), GetMutableDefault<UTbSame1Settings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("TbSame1Settings", FOnGetDetailCustomizationInstance::CreateStatic(&FTbSame1ConnectionSettingsDetails::MakeInstance));
}

void FTbSame1EditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear TbSame1");
	}
}

IMPLEMENT_MODULE(FTbSame1EditorModule, TbSame1Editor)

#undef LOCTEXT_NAMESPACE
