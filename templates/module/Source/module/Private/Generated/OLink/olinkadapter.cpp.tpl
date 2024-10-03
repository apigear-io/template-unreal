{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sOLinkAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $ifaceId := printf "%s.%s" .Module.Name .Interface.Name}}

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Generated/OLink/{{$Iface}}OLinkAdapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "{{$ModuleName}}/Generated/api/{{$ModuleName}}.json.adapter.h"
#include "OLinkClientConnection.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "{{$Iface}}OLinkSource.h"
#include "HAL/Platform.h"
#if !(PLATFORM_IOS || PLATFORM_ANDROID)

using namespace ApiGear::ObjectLink;

{{- if .Interface.Description }}
/**
   \brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
	: Source(std::make_shared<{{$Iface}}OLinkSource>())
{
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void {{$Class}}::Deinitialize()
{
	Super::Deinitialize();
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
{{- if or (len .Interface.Properties) (.Interface.Signals) }}
		U{{$Iface}}Signals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
		checkf(BackendSignals, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
{{- end }}
{{- range .Interface.Properties }}
		BackendSignals->On{{Camel .Name}}Changed.RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
		BackendSignals->On{{Camel .Name}}Signal.RemoveDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}
	}

	// only set if interface is implemented
	checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));

	// subscribe to new backend
{{- $Service := printf "I%sInterface" $Iface }}
	BackendService = InService;
{{- if or (len .Interface.Properties) (.Interface.Signals) }}
	U{{$Iface}}Signals* BackendSignals = BackendService->Execute__GetSignals(BackendService.GetObject());
	checkf(BackendSignals, TEXT("Cannot subscribe to delegates from backend service {{$Iface}}"));
{{- end }}
	// connect property changed signals or simple events
{{- range .Interface.Properties }}
	BackendSignals->On{{Camel .Name}}Changed.AddDynamic(this, &{{$Class}}::On{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	BackendSignals->On{{Camel .Name}}Signal.AddDynamic(this, &{{$Class}}::On{{Camel .Name}});
{{- end }}

	// update olink source with new backend
	Source->setBackendService(InService);
}
{{- range .Interface.Signals }}

void {{$Class}}::On{{Camel .Name}}({{ueParams "" .Params}})
{
	Source->On{{Camel .Name}}({{ueVars "" .Params}});
}
{{- end }}
{{- range .Interface.Properties }}

void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
	Source->On{{Camel .Name}}Changed({{ueVar "In" .}});
}
{{- end }}

void {{$Class}}::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
	check(InHost);
	Source->setOLinkHost(InHost.Get());

	if (Registry)
	{
		Registry->removeSource(Source->olinkObjectName());
	}
	Registry = InHost->GetOLinkRegistry();
	// register source to host registry
	Registry->addSource(Source);
}
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID)

{{$Class}}::{{$Class}}()
	: Source(std::make_shared<{{$Iface}}OLinkSource>())
{
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void {{$Class}}::Deinitialize()
{
	Super::Deinitialize();
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService)
{
}
{{- range .Interface.Signals }}

void {{$Class}}::On{{Camel .Name}}({{ueParams "" .Params}})
{
}
{{- end }}
{{- range .Interface.Properties }}

void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "In" .}})
{
}
{{- end }}

void {{$Class}}::setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost)
{
}
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
