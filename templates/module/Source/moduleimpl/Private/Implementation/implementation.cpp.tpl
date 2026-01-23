{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%sImplementation" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}

#include "{{$ModuleName}}/Implementation/{{$Iface}}.h"
#include "Misc/ScopeRWLock.h"

{{$Class}}::~{{$Class}}() = default;

{{- $features := .Features }}
{{- range .Interface.Properties }}
{{ueReturn "" .}} {{$Class}}::Get{{Camel .Name}}() const
{
{{- if $features.jni }}
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock({{ueVar "" .}}RWLock);
#endif
{{- end }}
	return {{ueVar "" .}};
}

{{- if not .IsReadOnly }}{{nl}}
void {{$Class}}::Set{{Camel .Name}}({{ueParam "In" .}})
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.{{$ModuleName}}.{{$IfaceName}}.Impl.Set{{Camel .Name}}");
	if ({{ueVar "" .}} != {{ueVar "In" .}})
	{
{{- if $features.jni }}
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock({{ueVar "" .}}RWLock);
			{{ueVar "" .}} = {{ueVar "In" .}};
		}
#else
		{{ueVar "" .}} = {{ueVar "In" .}};
#endif
{{- else }}
		{{ueVar "" .}} = {{ueVar "In" .}};
{{- end }}
		_GetPublisher()->Broadcast{{Camel .Name}}Changed({{ueVar "" .}});
	}
}
{{- end }}
{{- else }}
{{- end }}
{{- range .Interface.Operations }}{{ nl }}
{{- if .Description }}
/**
   \brief {{.Description}}
*/
{{- end }}
{{ueReturn "" .Return}} {{$Class}}::{{Camel .Name}}({{ueParams "" .Params}})
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.{{$ModuleName}}.{{$IfaceName}}.Impl.{{Camel .Name}}");
	{{- range .Params }}
	(void){{ueVar "" .}};
	{{- end }}
	// do business logic here
	{{- if not .Return.IsVoid }}
	return {{ueDefault "" .Return}};
	{{- end }}
}
{{- else }}
{{- end }}

{{- if len .Interface.Properties }}

void {{$Class}}::_ResetProperties()
{
	{{- range .Interface.Properties }}
	if ({{ueVar "" .}} != {{ueDefault "" .}})
	{
{{- if $features.jni }}
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock({{ueVar "" .}}RWLock);
			{{ueVar "" .}} = {{ueDefault "" .}};
		}
#else
		{{ueVar "" .}} = {{ueDefault "" .}};
#endif
{{- else }}
		{{ueVar "" .}} = {{ueDefault "" .}};
{{- end }}
		_GetPublisher()->Broadcast{{Camel .Name}}Changed({{ueVar "" .}});
	}
	{{- end }}
}
{{- end }}
