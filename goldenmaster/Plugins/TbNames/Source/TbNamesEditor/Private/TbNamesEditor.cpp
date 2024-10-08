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

#include "TbNamesEditor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "TbNamesSettings.h"
#include "TbNamesConnectionSettings.h"

#define LOCTEXT_NAMESPACE "TbNamesEditor"

void FTbNamesEditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear TbNames", LOCTEXT("TbNamesSettingsName", "ApiGear TbNames"), LOCTEXT("TbNamesSettingsDescription", "Project settings for ApiGear TbNames plugin"), GetMutableDefault<UTbNamesSettings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("TbNamesSettings", FOnGetDetailCustomizationInstance::CreateStatic(&FTbNamesConnectionSettingsDetails::MakeInstance));
}

void FTbNamesEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear TbNames");
	}
}

IMPLEMENT_MODULE(FTbNamesEditorModule, TbNamesEditor)

#undef LOCTEXT_NAMESPACE
