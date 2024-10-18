{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}OLinkFixture.h"
#include "{{$DisplayName}}OLink.spec.h"
#include "{{$ModuleName}}/Generated/OLink/{{$DisplayName}}OLinkClient.h"
#include "{{$ModuleName}}/Generated/OLink/{{$DisplayName}}OLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "OLinkHost.h"

void {{$Class}}OLinkHelper::SetSpec({{$Class}}OLinkSpec* InSpec)
{
	Spec = InSpec;
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	Spec->{{ Camel .Name }}PropertyCb({{ueVar "" .}});
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	Spec->{{ Camel .Name }}SignalCb({{ueVars "" .Params}});
}
{{- end }}

void {{$Class}}OLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

F{{ $DisplayName }}OLinkFixture::F{{ $DisplayName }}OLinkFixture()
{
	Helper = NewObject<{{$Class}}OLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}OLinkClient>();
}

F{{ $DisplayName }}OLinkFixture::~F{{ $DisplayName }}OLinkFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}OLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* F{{ $DisplayName }}OLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

U{{ $DisplayName }}OLinkAdapter* F{{ $DisplayName }}OLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}OLinkAdapter>();
}

TSoftObjectPtr<{{$Class}}OLinkHelper> F{{ $DisplayName }}OLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* F{{ $DisplayName }}OLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}OLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
void {{$Class}}OLinkHelper::SetSpec({{$Class}}OLinkSpec* /* InSpec */)
{
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	(void){{ueVar "" .}};
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}OLinkHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	{{- range $i, $e := .Params }}
	(void){{ueVar "" .}};
	{{- end }}
}
{{- end }}

void {{$Class}}OLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
