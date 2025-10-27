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
{{- $cppinterface := printf "U%sInterface" $Class }}
{{- $bpinterface := printf "I%sBPInterface" $Class }}
{{- $Iface := printf "%s%s" $ModuleName (Camel .Name) }}
#include "{{$ModuleName}}/Generated/api/{{$Class}}BPAdapter.h"
#include "{{$Class}}LatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
{{- $adapter := printf "U%sBPAdapter" $Class }}

void {{$adapter}}::Initialize(TScriptInterface<{{ $bpinterface }}> InTarget)
{
	Target = InTarget;
}

{{- nl }}
U{{$Class}}Publisher* {{$adapter}}::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return {{$bpinterface}}::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

{{- if len .Operations}}{{ nl }}{{ end }}
{{- range $i, $e := .Operations }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Return.IsVoid }}
{{ueReturn "" .Return}} {{$adapter}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return {{$bpinterface}}::Execute_{{Camel .Name}}(Obj{{if len .Params}}, {{end}}{{ueVars "" .Params}});
	}
}
{{- else }}
void {{$adapter}}::{{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}},{{end}} {{ueParams "" .Params}})
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

TFuture<{{ueReturn "" .Return}}> {{$adapter}}::{{Camel .Name}}Async({{ueParams "" .Params}})
{
	return Async(EAsyncExecution::ThreadPool,
		[{{range .Params}}{{ueVar "" .}}, {{ end }}this]()
		{
		return {{Camel .Name}}({{ueVars "" .Params}});
	});
}

{{ueReturn "" .Return}} {{$adapter}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return {{$bpinterface}}::Execute_{{Camel .Name}}(Obj{{if len .Params}}, {{end}}{{ueVars "" .Params}});
	}
	return {{ueDefault "" .Return}};
}
{{- end }}
{{- end }}

{{- if len .Properties}}{{ nl }}{{ end }}

{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
{{ueReturn "" .}} {{$adapter}}::Get{{Camel .Name}}() const
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return {{$bpinterface}}::Execute_Get{{Camel .Name}}(Obj);
	}
	return {{ueDefault "" .}};
}
{{- if not .IsReadOnly }}
void {{$adapter}}::Set{{Camel .Name}}({{ueParam "In" .}})
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		{{$bpinterface}}::Execute_Set{{Camel .Name}}(Obj, {{ueVar "In" .}});
	}
}
{{- end }}
{{- end }}
{{- end }}
