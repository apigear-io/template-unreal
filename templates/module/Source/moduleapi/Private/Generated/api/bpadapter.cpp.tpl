{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name }}
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
	ensureMsgf(InTarget.GetObject() == nullptr || InTarget.GetObject()->Implements<U{{$Class}}BPInterface>(),
		TEXT("{{$adapter}}::Initialize: InTarget does not implement {{$bpinterface}}. All BP calls will be silently skipped."));
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
void {{$adapter}}::{{Camel .Name}}Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, {{ueReturn "" .Return}}& Result{{if len .Params}}, {{end}}{{ueParams "" .Params}})
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>* oldRequest = LatentActionManager.FindExistingAction<F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>>(LatentInfo.CallbackTarget, LatentInfo.UUID);

		if (oldRequest != nullptr)
		{
			oldRequest->Cancel();
		}

		TFuture<{{ueReturn "" .Return}}> Future = {{Camel .Name}}Async({{ueVars "" .Params}});
		F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>* CompletionAction = new F{{$Iface}}LatentAction<{{ueReturn "" .Return}}>(LatentInfo, MoveTemp(Future), Result);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
	}
}

TFuture<{{ueReturn "" .Return}}> {{$adapter}}::{{Camel .Name}}Async({{ueParams "" .Params}})
{
	TWeakObjectPtr<{{$adapter}}> WeakThis(this);
	return Async(EAsyncExecution::TaskGraphMainThread,
		[{{range .Params}}{{ueVar "" .}}, {{ end }}WeakThis]()
		{
		if ({{$adapter}}* StrongThis = WeakThis.Get())
		{
			return StrongThis->{{Camel .Name}}({{ueVars "" .Params}});
		}
		return {{ueDefault "" .Return}};
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
