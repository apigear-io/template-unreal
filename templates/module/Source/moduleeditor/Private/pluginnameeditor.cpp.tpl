{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear %s" $ModuleName -}}
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

{{- $mclass := printf "F%sEditorModule" $ModuleName }}

#include "{{$ModuleName}}Editor.h"
#include "ISettingsModule.h"
#include "PropertyEditorModule.h"
#include "{{$ModuleName}}Settings.h"
#include "{{$ModuleName}}ConnectionSettings.h"

#define LOCTEXT_NAMESPACE "{{$ModuleName}}Editor"

void {{$mclass}}::StartupModule()
{
	// register settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "{{$Category}}", LOCTEXT("{{$ModuleName}}SettingsName", "{{$Category}}"), LOCTEXT("{{$ModuleName}}SettingsDescription", "Project settings for {{$Category}} plugin"), GetMutableDefault<U{{$ModuleName}}Settings>());
	}

	// register details customization
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyModule.RegisterCustomClassLayout("{{$ModuleName}}Settings", FOnGetDetailCustomizationInstance::CreateStatic(&F{{$ModuleName}}ConnectionSettingsDetails::MakeInstance));
}

void {{$mclass}}::ShutdownModule()
{
	// unregister settings
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "{{$Category}}");
	}
}

IMPLEMENT_MODULE({{$mclass}}, {{$ModuleName}}Editor)

#undef LOCTEXT_NAMESPACE
