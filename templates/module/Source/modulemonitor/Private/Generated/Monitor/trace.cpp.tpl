{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $moduleName := .Module.Name}}
{{- $Category := printf "ApiGear%s" $ModuleName -}}
#include "{{$ModuleName}}.trace.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}.json.adapter.h"
{{- range .Module.Imports }}
#include "{{Camel .Name}}/Generated/api/{{Camel .Name}}.json.adapter.h"
{{- end }}
#include "tracer.h"

{{- range .Module.Interfaces }}
{{- $class := printf "%s%sTracer" $ModuleName (Camel .Name) }}
{{- $Name := (Camel .Name)}}
{{- $symbol := printf "%s/%s" $moduleName .Name}}

{{$class}}::{{$class}}()
{
}

void {{$class}}::capture_state(UObject* Object, I{{$ModuleName}}{{$Name}}Interface* obj)
{
	nlohmann::json fields_;
{{- range .Properties }}
	fields_["{{.Name}}"] = obj->Execute_Get{{Camel .Name}}(Object);
{{- end }}
	Tracer::instance()->state("{{$symbol}}", fields_);
}

{{- range .Properties }}
{{- if not .IsReadOnly }}
void {{$class}}::trace_callSet{{Camel .Name}}({{ueParam "In" .}})
{
	nlohmann::json fields_;
	fields_["{{.Name}}"] = {{ueVar "In" .}};
	Tracer::instance()->call("{{$symbol}}#_set", fields_);
}
{{- end }}
{{- end }}

{{- range .Signals}}

void {{$class}}::trace_signal{{Camel .Name}}({{ueParams "" .Params}})
{
	nlohmann::json fields_;

{{- range .Params}}
	fields_["{{.Name}}"] = {{ueVar "" .}};
{{- end }}
	Tracer::instance()->signal("{{$symbol}}#{{.Name}}", fields_);
}
{{- end }}

{{- range .Operations}}

void {{$class}}::trace_call{{Camel .Name}}({{ueParams "" .Params}})
{
	nlohmann::json fields_;
{{- range .Params}}
	fields_["{{.Name}}"] = {{ueVar "" .}};
{{- end }}
	Tracer::instance()->call("{{$symbol}}#{{.Name}}", fields_);
}
{{- end }}
{{- end }}
