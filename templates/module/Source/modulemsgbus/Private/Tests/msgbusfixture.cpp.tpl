{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $DisplayName := printf "%s%s" $ModuleName (Camel .Interface.Name) }}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Class := printf "U%s" $DisplayName}}
#include "{{$DisplayName}}MsgBusFixture.h"
#include "{{$DisplayName}}MsgBus.spec.h"
#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusClient.h"
#include "{{$ModuleName}}/Generated/MsgBus/{{$DisplayName}}MsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

{{$Class}}MsgBusHelper::~{{$Class}}MsgBusHelper()
{
	Spec = nullptr;
}

void {{$Class}}MsgBusHelper::SetSpec({{$Class}}MsgBusSpec* InSpec)
{
	Spec = InSpec;
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}MsgBusHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	if (Spec)
	{
		Spec->{{ Camel .Name }}PropertyCb({{ueVar "" .}});
	}
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}MsgBusHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	if (Spec)
	{
		Spec->{{ Camel .Name }}SignalCb({{ueVars "" .Params}});
	}
}
{{- end }}

void {{$Class}}MsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

F{{ $DisplayName }}MsgBusFixture::F{{ $DisplayName }}MsgBusFixture()
{
	Helper = NewObject<{{$Class}}MsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<{{ $Class }}MsgBusClient>();
}

F{{ $DisplayName }}MsgBusFixture::~F{{ $DisplayName }}MsgBusFixture()
{
	CleanUp();
}

TScriptInterface<I{{$DisplayName}}Interface> F{{ $DisplayName }}MsgBusFixture::GetImplementation()
{
	return testImplementation;
}

U{{ $DisplayName }}MsgBusAdapter* F{{ $DisplayName }}MsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<U{{ $DisplayName }}MsgBusAdapter>();
}

TSoftObjectPtr<{{$Class}}MsgBusHelper> F{{ $DisplayName }}MsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* F{{ $DisplayName }}MsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void F{{ $DisplayName }}MsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
// create empty implementation in case we do not want to do automated testing
{{$Class}}MsgBusHelper::~{{$Class}}MsgBusHelper()
{
}

void {{$Class}}MsgBusHelper::SetSpec({{$Class}}MsgBusSpec* /* InSpec */)
{
}

{{- range .Interface.Properties }}
{{- if and (not .IsReadOnly) (not (eq .KindType "extern")) }}

void {{$Class}}MsgBusHelper::{{ Camel .Name }}PropertyCb({{ueParam "" .}})
{
	(void){{ueVar "" .}};
}
{{- end }}
{{- end }}

{{- range .Interface.Signals }}

void {{$Class}}MsgBusHelper::{{ Camel .Name }}SignalCb({{ueParams "" .Params}})
{
	{{- range $i, $e := .Params }}
	(void){{ueVar "" .}};
	{{- end }}
}
{{- end }}

void {{$Class}}MsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
