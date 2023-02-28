{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name ) -}}
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
{{- $ModuleName := Camel .Module.Name}}
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$Class}}Interface.h"
{{- $abstractclass := printf "UAbstract%s" $Class }}
{{- if len .Signals }}{{ nl }}{{ end }}
{{- range $i, $e := .Signals }}
{{- if $i }}{{nl}}{{ end }}
UFUNCTION(Category = "{{$Category}}")
F{{$Class}}{{Camel .Name}}Delegate& {{$abstractclass}}::Get{{Camel .Name}}SignalDelegate()
{
	return {{Camel .Name}}Signal;
};
{{- end }}
{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
F{{$Class}}{{Camel .Name}}ChangedDelegate& {{$abstractclass}}::Get{{Camel .Name}}ChangedDelegate()
{
	return {{Camel .Name}}Changed;
};
{{- end }}

{{- range $i, $e := .Signals }}
{{- if $i }}{{nl}}{{ end }}
void {{$abstractclass}}::Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params }});
};
{{- end }}
{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
void {{$abstractclass}}::Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "In" .}})
{
	{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
}
{{- end }}

{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
{{ueReturn "" .}} {{$abstractclass}}::Get{{Camel .Name}}_Private() const
{
	return Execute_Get{{Camel .Name}}(this);
};

void {{$abstractclass}}::Set{{Camel .Name}}_Private({{ueParam "In" .}})
{
	Execute_Set{{Camel .Name}}(this, {{ueVar "In" .}});
};
{{- end }}
{{- end }}
