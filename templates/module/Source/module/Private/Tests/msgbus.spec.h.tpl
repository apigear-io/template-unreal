{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "Generated/MsgBus/{{$Iface}}MsgBusClient.h"
#include "{{$ModuleName}}TestsCommon.h"
#include "{{$DisplayName}}MsgBusFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC({{$Class}}MsgBusSpec, "{{$ModuleName}}.{{$IfaceName}}.MsgBus", {{$ModuleName}}TestFilterMask);

TUniquePtr<F{{$DisplayName}}MsgBusFixture> ImplFixture;

// signal callbacks for testing
{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}
void {{ Camel .Name }}PropertyCb({{ueParam "" .}});
{{- end }}
{{- end }}
{{- range .Interface.Signals }}
void {{ Camel .Name }}SignalCb({{ueParams "" .Params}});
{{- end }}
void _ConnectionStatusChangedCb(bool bConnected);
FDoneDelegate testDoneDelegate;

friend class {{$Class}}MsgBusHelper;
END_DEFINE_SPEC({{$Class}}MsgBusSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
