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
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
{{- $abstractclass := printf "UAbstract%s" $Class }}

{{- if .Operations}}{{ nl }}
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
{{- end}}

{{- if len .Signals }}{{ nl }}{{ end }}
{{- range $i, $e := .Signals }}
{{- if $i }}{{nl}}{{ end }}
F{{$Class}}{{Camel .Name}}Delegate& {{$abstractclass}}::Get{{Camel .Name}}SignalDelegate()
{
	return {{Camel .Name}}Signal;
};

void {{$abstractclass}}::Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params }});
};
{{- end }}

{{- if len .Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Properties }}
{{- if $i }}{{nl}}{{ end }}
F{{$Class}}{{Camel .Name}}ChangedDelegate& {{$abstractclass}}::Get{{Camel .Name}}ChangedDelegate()
{
	return {{Camel .Name}}Changed;
};

void {{$abstractclass}}::Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "In" .}})
{
	{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
}

{{ueReturn "" .}} {{$abstractclass}}::Get{{Camel .Name}}_Private() const
{
	return Execute_Get{{Camel .Name}}(this);
};

void {{$abstractclass}}::Set{{Camel .Name}}_Private({{ueParam "In" .}})
{
	Execute_Set{{Camel .Name}}(this, {{ueVar "In" .}});
};
{{- end }}

{{- range $i, $e := .Operations }}
{{- if $i }}{{nl}}{{ end }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{- if not .Return.IsVoid }}
void {{$abstractclass}}::{{Camel .Name}}Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{ if len .Params }}, {{end}}{{ueParams "" .Params}})
{
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
				Result = Execute_{{Camel .Name}}(this{{ if len .Params }}, {{end}}{{ueVars "" .Params}});
				CompletionAction->Cancel();
			});
	}
}
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

	Super::Deinitialize();
}

bool {{$abstractclass}}::IsInitialized() const
{
	return bInitialized;
}
{{- end }}
