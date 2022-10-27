{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
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

#include "{{$ModuleName}}_data.h"
{{- range .Module.Enums }}
{{- $class := printf "E%s%s" $ModuleName .Name }}
/**
 * Enumeration {{$class}}
 */
bool toUE4Type({{$class}}& value, uint8 v)
{
	bool bSuccessful = false;
	switch (v)
	{
{{- range .Members }}
	case {{.Value}}:
		value = {{$class}}::{{CAMEL .Name}};
		bSuccessful = true;
		break;
{{- end }}
	default:
		value = {{$class}}::{{CAMEL .Default.Name}};
	}
	return bSuccessful;
}
{{- end }}
{{- range .Module.Structs}}
{{- $class := printf "F%s%s" $ModuleName .Name}}
bool {{$class}}::operator==(const {{$class}}& rhs) const
{
	return
{{- range $idx, $elem := .Fields}}
	{{- if $idx }}{{" &&"}}{{ end }} ({{.Name}} == rhs.{{.Name}})
{{- end }};
}

bool {{$class}}::operator!=(const {{$class}}& rhs) const
{
	return !operator==(rhs);
}
{{- end }}
