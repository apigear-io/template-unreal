{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}

#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}.json.adapter.h"
{{- range .Module.Externs }}
{{- $class := ueExtern . }}
{{- if $class.Include }}
#include "{{$class.Include}}"
{{- end }}
{{- end }}

{{- if len .Module.Externs }}

// do the specialization of the adl_serializer for the in the nlohmann namespace
// we do not want to modify the external namespace
namespace nlohmann
{
{{- end }}
{{- range $.Module.Externs }}
{{- $system:= $.System }}
{{- $module:= $.Module }}
{{- $ext := (ueExtern .) }}
{{- $class:= $ext.Name }}

{{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}} adl_serializer<{{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}}>::from_json(const json& j)
{
	(void)j;
	// Do deserialization here, e.g.
	// return { j.at("xyz").get<Int>() };
	return {};
}

void adl_serializer<{{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}}>::to_json(json& j, {{if $ext.NameSpace }}{{ $ext.NameSpace }}::{{end}}{{$class}} t)
{
	(void)j;
	(void)t;
	// Do serialization here, e.g.
	// j = t.xyz;
}
{{- nl}}
{{- end }}
{{- if len .Module.Externs }}
} // namespace nlohmann
{{- end }}
