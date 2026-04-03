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

#include "TbStructArrayEditor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "TbStructArraySettings.h"
#include "TbStructArrayConnectionSettings.h"

#define LOCTEXT_NAMESPACE "TbStructArrayEditor"

void FTbStructArrayEditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear TbStructArray", LOCTEXT("TbStructArraySettingsName", "ApiGear TbStructArray"), LOCTEXT("TbStructArraySettingsDescription", "Project settings for ApiGear TbStructArray plugin"), GetMutableDefault<UTbStructArraySettings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("TbStructArraySettings", FOnGetDetailCustomizationInstance::CreateStatic(&FTbStructArrayConnectionSettingsDetails::MakeInstance));
}

void FTbStructArrayEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear TbStructArray");
	}
}

IMPLEMENT_MODULE(FTbStructArrayEditorModule, TbStructArrayEditor)

#undef LOCTEXT_NAMESPACE
