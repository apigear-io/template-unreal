
{{/* Copyright Epic Games, Inc. All Rights Reserved */}}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" $ModuleName }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%sLoggingDecorator" $ModuleName (Camel .Interface.Name) }}
{{- $Class := printf "U%s" $DisplayName}}
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
#include "Generated/Monitor/{{$Iface}}LoggingDecorator.h"
#include "Implementation/{{$Iface}}.h"
#include "Generated/api/{{$ModuleName}}.trace.h"
#include "{{$ModuleName}}Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(Log{{$DisplayName}});

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
{
{{- $Service := printf "I%sInterface" $Iface }}
	BackendService = {{$FactoryName}}::create{{$Service}}();
{{- range .Interface.Properties }}
	BackendService->Get{{Camel .Name}}ChangedDelegate().AddDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	BackendService->Get{{Camel .Name}}SignalDelegate().AddDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
}

{{$Class}}::~{{$Class}}() = default;

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
{{- range .Interface.Properties }}
		BackendService->Get{{Camel .Name}}ChangedDelegate().RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
		BackendService->Get{{Camel .Name}}SignalDelegate().RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(Log{{$DisplayName}}, Error, TEXT("Cannot set backend service to %s - interface {{$Iface}} is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
{{- $Service := printf "I%sInterface" $Iface }}
	BackendService = InService;
	// connect property changed signals or simple events
{{- range .Interface.Properties }}
	BackendService->Get{{Camel .Name}}ChangedDelegate().AddDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	BackendService->Get{{Camel .Name}}SignalDelegate().AddDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	// populate service state to proxy
{{- range .Interface.Properties }}
	{{ueVar "" .}} = BackendService->Execute_Get{{Camel .Name}}(BackendService.GetObject());
{{- end }}
}

{{- range .Interface.Signals }}
void {{$Class}}::Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params }});
}

void {{$Class}}::On{{Camel .Name}}({{ueParams "" .Params}})
{
	{{$Iface}}Tracer::trace_signal{{Camel .Name}}({{ueVars "" .Params}});
	Execute_Broadcast{{Camel .Name}}(this{{if len .Params}}, {{ end }}{{ueVars "" .Params }});
}

F{{$Iface}}{{Camel .Name}}Delegate& {{$Class}}::Get{{Camel .Name}}SignalDelegate()
{
	return {{Camel .Name}}Signal;
}
{{ end }}

{{- range .Interface.Properties }}
void {{$Class}}::Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "In" .}})
{
	{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
}

void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	{{$Iface}}Tracer::capture_state(BackendService.GetObject(), this);
	{{ueVar "" .}} = {{ueVar "In" .}};
	Execute_Broadcast{{Camel .Name}}Changed(this, {{ueVar "In" .}});
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Implementation() const
{
	return BackendService->Execute_Get{{Camel .Name}}(BackendService.GetObject());
}

void {{$Class}}::Set{{Camel .Name}}_Implementation({{ueParam "In" .}})
{
	{{$Iface}}Tracer::trace_callSet{{Camel .Name}}({{ueVar "In" .}});
	BackendService->Execute_Set{{Camel .Name}}(BackendService.GetObject(), {{ueVar "In" .}});
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Private() const
{
	return Execute_Get{{Camel .Name}}(this);
}

void {{$Class}}::Set{{Camel .Name}}_Private({{ueParam "In" .}})
{
	Execute_Set{{Camel .Name}}(this, {{ueVar "In" .}});
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
void {{$Class}}::{{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{ if len .Params }}, {{end}}{{ueParams "" .Params}})
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
				Result = BackendService->Execute_{{Camel .Name}}(BackendService.GetObject(){{if len .Params}}, {{ end }}{{ueVars "" .Params}});
				CompletionAction->Cancel();
			});
	}
}
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
