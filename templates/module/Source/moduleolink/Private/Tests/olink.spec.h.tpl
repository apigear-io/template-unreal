{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/OLink/{{$Iface}}OLinkClient.h"
#include "{{$ModuleName}}/Tests/{{$ModuleName}}TestsCommon.h"
#include "{{$DisplayName}}OLinkFixture.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

BEGIN_DEFINE_SPEC({{$Class}}OLinkSpec, "{{$ModuleName}}.{{$IfaceName}}.OLink", {{$ModuleName}}TestFilterMask);

TUniquePtr<F{{$DisplayName}}OLinkFixture> ImplFixture;

// signal callbacks for testing
{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}
void {{ Camel .Name }}PropertyCb({{ueParam "" .}});
{{- end }}
{{- end }}
{{- range .Interface.Signals }}
void {{ Camel .Name }}SignalCb({{ueParams "" .Params}});
{{- end }}
void _SubscriptionStatusChangedCb(bool bSubscribed);
FDoneDelegate testDoneDelegate;

friend class {{$Class}}OLinkHelper;
END_DEFINE_SPEC({{$Class}}OLinkSpec);

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
