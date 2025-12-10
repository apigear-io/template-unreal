{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%sCORE_API" (CAMEL .Module.Name) }}
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
#include "{{Camel .Module.Name}}/Generated/Core/{{Camel .Module.Name}}PropertiesData.h"

{{- range .Module.Interfaces }}
{{- $IfaceName := Camel .Name }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- range $i, $e := .Properties }}
{{- if not ( ueIsStdSimpleType . ) }}
{{- nl }}
void {{$Iface}}PropertiesData::Set{{ueVar "" .}}({{ueParam "In" .}})
{
	FScopeLock Lock(&({{ueVar "" .}}CS));
	{{ueVar "" .}} = {{ueVar "In" .}};
}

{{ueReturn "" .}} {{$Iface}}PropertiesData::Get{{ueVar "" .}}() const
{
	FScopeLock Lock(&({{ueVar "" .}}CS));
	return {{ueVar "" .}};
}
{{- end }}
{{- end }}
{{- end }}
