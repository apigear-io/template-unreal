{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name -}}
/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
{{- with .Interface }}
{{- $Class := printf "%s%s" $ModuleName (Camel .Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName (Camel .Name) }}
{{- $class := printf "U%sInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$ModuleName}}/Generated/api/Abstract{{$Class}}.h"
#include "{{$Class}}LatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
{{- $abstractclass := printf "UAbstract%s" $Class }}

{{$abstractclass}}::{{$abstractclass}}()
{
{{- if or (len .Properties) (len .Signals) }}
	{{$Iface}}Publisher = NewObject<U{{$Class}}Publisher>();
{{- end }}
}

{{- nl }}
U{{$Class}}Publisher* {{$abstractclass}}::_GetPublisher()
{
	if (!{{$Iface}}Publisher)
	{
		{{$Iface}}Publisher = NewObject<U{{$Class}}Publisher>();
	}
	return {{$Class}}Publisher;
}
{{- nl }}

{{- range $i, $e := .Properties }}
{{ueReturn "" .}} {{$abstractclass}}::Get{{Camel .Name}}_Private() const
{
	return Get{{Camel .Name}}();
};

{{- if not .IsReadOnly }}{{nl}}
void {{$abstractclass}}::Set{{Camel .Name}}_Private({{ueParam "In" .}})
{
	Set{{Camel .Name}}({{ueVar "In" .}});
};
{{- end }}
{{- nl }}
{{- end }}

{{- if len .Operations }}
{{- range $i, $e := .Operations }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{- if not .Return.IsVoid }}
void {{$abstractclass}}::{{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{ if len .Params }}, {{end}}{{ueParams "" .Params}})
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>* oldRequest = LatentActionManager.FindExistingAction<F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		TFuture<{{ueReturn "" .Return}}> Future = {{Camel .Name}}Async({{ueVars "" .Params}});
		F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>* CompletionAction = new F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<{{ueReturn "" .Return}}> {{$abstractclass}}::{{Camel .Name}}Async({{ueParams "" .Params}})
{
	TWeakObjectPtr<{{$abstractclass}}> WeakThis(this);
	return Async(EAsyncExecution::ThreadPool,
		[{{range .Params}}{{ueVar "" .}}, {{ end }}WeakThis]()
		{
		if (auto StrongThis = WeakThis.Get())
		{
			return StrongThis->{{Camel .Name}}({{ueVars "" .Params}});
		}
		return {{ueDefault "" .Return}};
	});
}
{{- nl }}
{{- end }}
{{- end }}
{{- end }}
void {{$abstractclass}}::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void {{$abstractclass}}::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

{{- if or (len .Properties) (len .Signals) }}{{nl}}
	if ({{$Iface}}Publisher)
	{
{{- range $i, $e := .Signals }}
		{{$Iface}}Publisher->On{{Camel .Name}}Signal.RemoveAll({{$Iface}}Publisher);
		{{$Iface}}Publisher->On{{Camel .Name}}SignalBP.RemoveAll({{$Iface}}Publisher);
{{- end }}
{{- if and (len .Properties) (len .Signals) }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
		{{$Iface}}Publisher->On{{Camel .Name}}Changed.RemoveAll({{$Iface}}Publisher);
		{{$Iface}}Publisher->On{{Camel .Name}}ChangedBP.RemoveAll({{$Iface}}Publisher);
{{- end }}
	}
{{- end }}

	Super::Deinitialize();
}

bool {{$abstractclass}}::IsInitialized() const
{
	return bInitialized;
}
{{- end }}
