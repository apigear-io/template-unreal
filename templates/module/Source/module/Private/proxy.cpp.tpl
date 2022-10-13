
{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sProxy" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
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
#include "{{$Iface}}Proxy.h"
#include "{{$IfaceName}}/{{$Iface}}Local.h"
#include "apig/{{$ModuleName}}.trace.h"
#include "{{$ModuleName}}Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

class F{{$Iface}}LatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	F{{$Iface}}LatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

	void Cancel()
	{
		bInProgress = false;
	}

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (bInProgress == false)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	virtual void NotifyObjectDestroyed()
	{
		Cancel();
	}

	virtual void NotifyActionAborted()
	{
		Cancel();
	}
};

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: I{{$Iface}}Interface()
{{- range .Interface.Properties }}
	, {{ueVar "" .}}({{ueDefault "" .}})
{{- end }}
{
{{- $Service := printf "I%sInterface" $Iface }}
	service = {{$FactoryName}}::create{{$Service}}();
{{- range .Interface.Properties }}
	service->Get{{Camel .Name}}ChangedDelegate().AddDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	service->Get{{Camel .Name}}SignalDelegate().AddDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
}

{{$Class}}::~{{$Class}}()
{
{{- range .Interface.Properties }}
	service->Get{{Camel .Name}}ChangedDelegate().RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	service->Get{{Camel .Name}}SignalDelegate().RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
}

{{- range .Interface.Signals }}
void {{$Class}}::On{{Camel .Name}}({{ueParams "" .Params}})
{
	{{$Iface}}Tracer::trace_signal{{Camel .Name}}({{ueVars "" .Params}});
	{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params }});
}

F{{$Iface}}{{Camel .Name}}Delegate& {{$Class}}::Get{{Camel .Name}}SignalDelegate()
{
	return {{Camel .Name}}Signal;
}
{{ end }}

{{- range .Interface.Properties }}
void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	{{$Iface}}Tracer::capture_state(this);
	{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}() const
{
	return service->Get{{Camel .Name}}();
}

void {{$Class}}::Set{{Camel .Name}}({{ueParam "In" .}})
{
	{{$Iface}}Tracer::trace_callSet{{Camel .Name}}({{ueVar "In" .}});
	service->Set{{Camel .Name}}({{ueVar "In" .}});
}

F{{$Iface}}{{Camel .Name}}ChangedDelegate& {{$Class}}::Get{{Camel .Name}}ChangedDelegate()
{
	return {{Camel .Name}}Changed;
}
{{ end }}

{{- range .Interface.Operations }}

{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{- if not .Return.IsVoid }}
void {{$Class}}::{{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{ if len .Params }}, {{end}}{{ueParams "" .Params}})
{
	{{$Iface}}Tracer::trace_call{{Camel .Name}}({{ueVars "" .Params}});

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		F{{$Iface}}LatentAction* oldRequest = LatentActionManager.FindExistingAction<F{{$Iface}}LatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			// cancel old request
			oldRequest->Cancel();
			LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
		}

		F{{$Iface}}LatentAction* CompletionAction = new F{{$Iface}}LatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
		Async(EAsyncExecution::Thread,
			[{{range .Params}}{{ueVar "" .}}, {{ end }}this, &Result, CompletionAction]()
			{
				Result = service->{{Camel .Name}}({{ueVars "" .Params}});
				CompletionAction->Cancel();
			});
	}
}
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	{{ $Iface}}Tracer::trace_call{{Camel .Name}}({{ueVars "" .Params }});
	{{- if not .Return.IsVoid }}
	return service->{{Camel .Name}}({{ ueVars "" .Params }});
	{{- else }}
	service->{{Camel .Name}}({{ ueVars "" .Params}});
	{{- end }}
}
{{- end }}
