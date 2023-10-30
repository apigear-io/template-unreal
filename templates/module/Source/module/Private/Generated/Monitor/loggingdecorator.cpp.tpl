
{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%sLoggingDecorator" $ModuleName (Camel .Interface.Name) }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $FactoryName := printf "F%sModuleFactory" $ModuleName -}}
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
#include "Generated/Monitor/{{$Iface}}LoggingDecorator.h"
#include "{{$ModuleName}}.trace.h"
#include "{{$ModuleName}}Factory.h"
#include "Runtime/Launch/Resources/Version.h"

DEFINE_LOG_CATEGORY(Log{{$DisplayName}});

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: {{$abstractclass}}()
{
}

{{$Class}}::~{{$Class}}() = default;

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

{{- $Service := printf "I%sInterface" $Iface }}
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	setBackendService({{$FactoryName}}::create{{$Service}}(GetGameInstance(), Collection));
#else
	setBackendService({{$FactoryName}}::create{{$Service}}(Collection));
#endif
}

void {{$Class}}::Deinitialize()
{
	Super::Deinitialize();
	BackendService = nullptr;
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
{{- if or (len .Interface.Properties) (.Interface.Signals) }}
		U{{$Iface}}Signals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
{{- end }}
{{- range .Interface.Properties }}
		BackendSignals->On{{Camel .Name}}Changed.RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
		BackendSignals->On{{Camel .Name}}Signal.RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));

	// subscribe to new backend
{{- $Service := printf "I%sInterface" $Iface }}
	BackendService = InService;
{{- if or (len .Interface.Properties) (.Interface.Signals) }}
	U{{$Iface}}Signals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
{{- end }}
	// connect property changed signals or simple events
{{- range .Interface.Properties }}
	BackendSignals->On{{Camel .Name}}Changed.AddDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	BackendSignals->On{{Camel .Name}}Signal.AddDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	// populate service state to proxy
{{- range .Interface.Properties }}
	{{ueVar "" .}} = BackendService->Execute_Get{{Camel .Name}}(BackendService.GetObject());
{{- end }}
}
{{- if .Interface.Signals }}{{nl}}{{ end }}
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
void {{$Class}}::On{{Camel .Name}}({{ueParams "" .Params}})
{
	{{$Iface}}Tracer::trace_signal{{Camel .Name}}({{ueVars "" .Params}});
	Execute__GetSignals(this)->On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params }});
}
{{- end }}
{{- if .Interface.Properties }}{{nl}}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	{{$Iface}}Tracer::capture_state(BackendService.GetObject(), this);
	{{ueVar "" .}} = {{ueVar "In" .}};
	Execute__GetSignals(this)->On{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Implementation() const
{
	return BackendService->Execute_Get{{Camel .Name}}(BackendService.GetObject());
}

{{- if not .IsReadOnly }}{{nl}}
void {{$Class}}::Set{{Camel .Name}}_Implementation({{ueParam "In" .}})
{
	{{$Iface}}Tracer::trace_callSet{{Camel .Name}}({{ueVar "In" .}});
	BackendService->Execute_Set{{Camel .Name}}(BackendService.GetObject(), {{ueVar "In" .}});
}
{{- end }}
{{- end }}
{{- if .Interface.Operations }}{{nl}}{{ end }}
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{ $Iface}}Tracer::trace_call{{Camel .Name}}({{ueVars "" .Params }});
	{{- if not .Return.IsVoid }}
	return BackendService->Execute_{{Camel .Name}}(BackendService.GetObject(){{if len .Params}}, {{ end }}{{ ueVars "" .Params }});
	{{- else }}
	BackendService->Execute_{{Camel .Name}}(BackendService.GetObject(){{if len .Params}}, {{ end }}{{ ueVars "" .Params}});
	{{- end }}
}
{{- end }}
