{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sOLinkClient" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $ifaceId := printf "%s.%s" .Module.Name .Interface.Name}}

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "{{$Iface}}OLinkClient.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Generated/api/{{$ModuleName}}.json.adapter.h"
#include "unrealolink.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"

using namespace ApiGear::ObjectLink;

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: I{{$ModuleName}}{{$IfaceName}}Interface()
	, m_node(nullptr)
	, m_isReady(false)
{
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->Connect();
		AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
	}
	m_node = ClientRegistry::get().addObjectSink(this);
}

void {{$Class}}::Deinitialize()
{
	Super::Deinitialize();
	ClientRegistry::get().removeObjectSink(this);
	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetOLinkConnection()->unlinkObjectSource(olinkObjectName());
	}
	m_isReady = false;
	m_node = nullptr;
}
{{ range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
void {{$Class}}::Broadcast{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{Camel .Name}}Signal.Broadcast({{ueVars "" .Params }});
}

F{{$Iface}}{{Camel .Name}}Delegate& {{$Class}}::Get{{Camel .Name}}SignalDelegate()
{
	return {{Camel .Name}}Signal;
}
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
void {{$Class}}::Broadcast{{Camel .Name}}Changed_Implementation({{ueParam "In" .}})
{
	{{ueVar "" .}} = {{ueVar "In" .}};
	{{Camel .Name}}Changed.Broadcast({{ueVar "In" .}});
}

{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}_Implementation() const
{
	return {{ueVar "" .}};
}

void {{$Class}}::Set{{Camel .Name}}_Implementation({{ueParam "In" .}})
{
	if (!m_node)
	{
		return;
	}
	m_node->setRemoteProperty("{{$ifaceId}}/{{.Name}}", {{ueVar "In" .}});
}

F{{$Iface}}{{Camel .Name}}ChangedDelegate& {{$Class}}::Get{{Camel .Name}}ChangedDelegate()
{
	return {{Camel .Name}}Changed;
}
{{- end }}
{{- if len .Interface.Operations }}{{ nl }}{{ end }}
{{- range .Interface.Operations }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{- $returnVal := (ueReturn "" .Return)}}
{{$returnVal}} {{$Class}}::{{Camel .Name}}_Implementation({{ueParams "" .Params}})
{
	{{- if .Return.IsVoid }}
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return;
	}
	InvokeReplyFunc Get{{$IfaceName}}StateFunc = [this](InvokeReplyArg arg) {};
	m_node->invokeRemote("{{$ifaceId}}/{{.Name}}", { {{- ueVars "" .Params -}} }, Get{{$IfaceName}}StateFunc);
	{{- else }}
	if (!m_node)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
		return {{ ueDefault "" .Return }};
	}
	TPromise<{{$returnVal}}> Promise;
	Async(EAsyncExecution::Thread,
		[{{ueVars "" .Params }}{{if len .Params}}, {{ end }}&Promise, this]()
		{
			InvokeReplyFunc Get{{$IfaceName}}StateFunc = [&Promise](InvokeReplyArg arg)
			{ Promise.SetValue(arg.value.get<{{$returnVal}}>()); };
			m_node->invokeRemote("{{$ifaceId}}/{{.Name}}", { {{- ueVars "" .Params -}} }, Get{{$IfaceName}}StateFunc);
		});

	return Promise.GetFuture().Get();
	{{- end }}
}
{{ end }}
void {{$Class}}::applyState(const nlohmann::json& fields)
{
{{- range .Interface.Properties }}
	if (fields.contains("{{.Name}}"))
	{
		if ({{ueVar "" .}} != fields["{{.Name}}"].get<{{ueReturn "" .}}>())
		{
			{{ueVar "" .}} = fields["{{.Name}}"].get<{{ueReturn "" .}}>();
			Execute_Broadcast{{Camel .Name}}Changed(this, {{ueVar "" .}});
		}
	}
{{- end }}
}

std::string {{$Class}}::olinkObjectName()
{
	return "{{$ifaceId}}";
}

void {{$Class}}::olinkOnSignal(std::string name, nlohmann::json args)
{
	std::string path = Name::pathFromName(name);
{{- range .Interface.Signals }}
	if (path == "{{.Name}}")
	{
		Execute_Broadcast{{Camel .Name}}(this
		{{- range $idx, $elem := .Params -}}
			, args[{{$idx}}].get<{{ueReturn "" .}}>()
		{{- end }});
		return;
	}
{{- end }}
}

void {{$Class}}::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
	std::string path = Name::pathFromName(name);
	applyState({{ "{{path, value" }}}});
}

void {{$Class}}::olinkOnInit(std::string name, nlohmann::json props, IClientNode* node)
{
	m_isReady = true;
	m_node = node;
	applyState(props);
	// call isReady();
}

void {{$Class}}::olinkOnRelease()
{
	m_isReady = false;
	m_node = nullptr;
}
