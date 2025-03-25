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

#include "TbIfaceimportEditor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "TbIfaceimportSettings.h"
#include "TbIfaceimportConnectionSettings.h"

#define LOCTEXT_NAMESPACE "TbIfaceimportEditor"

void FTbIfaceimportEditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear TbIfaceimport", LOCTEXT("TbIfaceimportSettingsName", "ApiGear TbIfaceimport"), LOCTEXT("TbIfaceimportSettingsDescription", "Project settings for ApiGear TbIfaceimport plugin"), GetMutableDefault<UTbIfaceimportSettings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("TbIfaceimportSettings", FOnGetDetailCustomizationInstance::CreateStatic(&FTbIfaceimportConnectionSettingsDetails::MakeInstance));
}

void FTbIfaceimportEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear TbIfaceimport");
	}
}

IMPLEMENT_MODULE(FTbIfaceimportEditorModule, TbIfaceimportEditor)

#undef LOCTEXT_NAMESPACE
