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

#include "Generated/api/{{$ModuleName}}_data.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"
{{- nl }}

{{- range .Module.Enums }}
{{- $moduleEnumName := printf "%s%s" $ModuleName .Name }}
{{- $class := printf "E%s%s" $ModuleName .Name }}
/**
 * Enumeration {{$class}}
 */
bool U{{ $ModuleName }}Library::to{{$moduleEnumName}}({{$class}}& ConvertedEnum, uint8 InValue)
{
	bool bSuccessful = false;
	switch (InValue)
	{
{{- range .Members }}
	case {{.Value}}:
		ConvertedEnum = {{$class}}::{{ abbreviate $moduleEnumName }}_{{Camel .Name}};
		bSuccessful = true;
		break;
{{- end }}
	default:
		ConvertedEnum = {{$class}}::{{ abbreviate $moduleEnumName }}_{{Camel .Default.Name}};
	}
	return bSuccessful;
}
{{- end }}
{{- if .Module.Enums }}{{nl}}{{ end -}}
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

{{$class}}::operator FString() const
{
	return ToString();
}

FString {{$class}}::ToString() const
{
	return ToJSON(true);
}

FString {{$class}}::ToJSON(bool bPrettyPrint) const
{
	FString JSONString;
	FJsonObjectConverter::UStructToJsonObjectString(*this, JSONString, 0, 0, 0, nullptr, bPrettyPrint);
	return JSONString;
}
{{- nl }}
{{- end }}
{{- range $idx, $elem := .Module.Structs }}
	{{- if $idx}}{{nl}}{{end}}
{{- $class := printf "F%s%s" $ModuleName .Name }}
{{- $shortname := printf "%s%s" $ModuleName .Name }}
/* Returns true if {{ $shortname }} A is equal to {{ $shortname }} B (A == B) */
bool U{{ $ModuleName }}Library::EqualEqual_{{ $shortname }}{{ $shortname }}({{ $class }} A, {{ $class }} B)
{
	return A == B;
}

/* Returns true if {{ $shortname }} A is not equal to {{ $shortname }} B (A != B) */
bool U{{ $ModuleName }}Library::NotEqual_{{ $shortname }}{{ $shortname }}({{ $class }} A, {{ $class }} B)
{
	return A != B;
}

FString U{{ $ModuleName }}Library::Conv_{{ $shortname }}ToString(const {{ $class }}& In{{ $shortname }})
{
	return In{{ $shortname }}.ToString();
}

FString U{{ $ModuleName }}Library::Conv_{{ $shortname }}ToJSON(const {{ $class }}& In{{ $shortname }})
{
	return In{{ $shortname }}.ToJSON();
}
{{- end }}
{{- if .Module.Structs }}{{nl}}{{ end -}}
