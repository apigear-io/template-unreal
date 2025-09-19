{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $API_MACRO := printf "%sAPI_API" (CAMEL .Module.Name) }}
{{- $ModuleName := Camel .Module.Name -}}

{{- $Class := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Interface.Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- template "get_referenced_interfaces_includes" . }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}Interface.h"

{{- with .Interface }}
{{- if or (len .Properties) (len .Signals) }}

{{- range $i, $e := .Signals }}
	{{- if $i }}{{nl}}{{ end }}
void U{{$Class}}Publisher::Broadcast{{Camel .Name}}Signal({{ueParams "" .Params}})
{
	On{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params}});
	On{{Camel .Name}}SignalBP.Broadcast({{ueVars "" .Params}});

	TArray<TScriptInterface<I{{$Class}}BPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Signal(Obj{{- if (len .Params) }}, {{ end }}{{ueVars "" .Params}});
		}
	}
}
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
void U{{$Class}}Publisher::Broadcast{{Camel .Name}}Changed(UPARAM(DisplayName = "{{ueVar "" .}}") {{ueParam "In" .}})
{
	On{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
	On{{Camel .Name}}ChangedBP.Broadcast({{ueVar "In" .}});

	TArray<TScriptInterface<I{{$Class}}BPSubscriberInterface>> SubscribersCopy = Subscribers;
	for (const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber : SubscribersCopy)
	{
		if (UObject* Obj = Subscriber.GetObject())
		{
			I{{$Class}}BPSubscriberInterface::Execute_On{{Camel .Name}}Changed(Obj, {{ueVar "In" .}});
		}
	}
}
{{- end }}

void U{{$Class}}Publisher::Subscribe(const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber)
{
	if (!Subscriber.GetObject())
	{
		return;
	}

	Subscribers.Remove(Subscriber);
	Subscribers.Add(Subscriber);
}

void U{{$Class}}Publisher::Unsubscribe(const TScriptInterface<I{{$Class}}BPSubscriberInterface>& Subscriber)
{
	Subscribers.Remove(Subscriber);
}
{{- end }}
{{- end }}
