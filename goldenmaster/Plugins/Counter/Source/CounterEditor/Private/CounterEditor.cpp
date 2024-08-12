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

#include "CounterEditor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "CounterSettings.h"
#include "CounterConnectionSettings.h"

#define LOCTEXT_NAMESPACE "CounterEditor"

void FCounterEditorModule::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ApiGear Counter", LOCTEXT("CounterSettingsName", "ApiGear Counter"), LOCTEXT("CounterSettingsDescription", "Project settings for ApiGear Counter plugin"), GetMutableDefault<UCounterSettings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("CounterSettings", FOnGetDetailCustomizationInstance::CreateStatic(&FCounterConnectionSettingsDetails::MakeInstance));
}

void FCounterEditorModule::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ApiGear Counter");
	}
}

IMPLEMENT_MODULE(FCounterEditorModule, CounterEditor)

#undef LOCTEXT_NAMESPACE
