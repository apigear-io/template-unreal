{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name }}
#pragma once

{{- $ModuleName := Camel .Module.Name}}
{{- if len .Module.Interfaces }}{{nl}}{{end}}
{{- range .Module.Interfaces }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $class := printf "%sInterface" $Class }}
#include "{{$class}}.h"
{{- end }}
