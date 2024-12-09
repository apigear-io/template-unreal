
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%s_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMsgBusClient" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "Generated/api/Abstract{{$Iface}}.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "IMessageContext.h"
#include "{{$Iface}}MsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct F{{$DisplayName}}InitMessage;
struct F{{$DisplayName}}ServiceDisconnectMessage;
{{- range $i, $e := .Interface.Signals }}
struct F{{$DisplayName}}{{Camel .Name}}SignalMessage;
{{- end }}
{{- range $i, $e := .Interface.Properties }}
struct F{{$DisplayName}}{{Camel .Name}}ChangedMessage;
{{- end }}
{{- range $i, $e := .Interface.Operations }}
{{- if not .Return.IsVoid }}
struct F{{$DisplayName}}{{Camel .Name}}ReplyMessage;
{{- end }}
{{- end }}

{{- if len .Interface.Properties }}

struct {{$Iface}}PropertiesMsgBusData;
{{- end}}
DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}MsgBusClient, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$Iface}}ConnectionStatusChangedDelegate, bool, IsConnected);

UCLASS(NotBlueprintable, BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public {{$abstractclass}}
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// connection handling
	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	void Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	void Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	bool IsConnected() const;

	/**
	 * Used when the interface client changes connection status:
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Connection Status Changed")
	F{{$Iface}}ConnectionStatusChangedDelegate _ConnectionStatusChanged;

	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}_Implementation() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}_Implementation({{ueParam "" .}}) override;
{{- end }}
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
	{{ueReturn "" .Return}} {{Camel .Name}}_Implementation({{ueParams "" .Params}}) override;
{{- end }}

private:
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> {{$Iface}}MsgBusEndpoint;

	void DiscoverService();
	FMessageAddress ServiceAddress;

	// connection handling
	void OnConnectionInit(const F{{$DisplayName}}InitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const F{{$DisplayName}}ServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- range $i, $e := .Interface.Signals }}
	void On{{Camel .Name}}(const F{{$DisplayName}}{{Camel .Name}}SignalMessage& In{{Camel .Name}}Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- range $i, $e := .Interface.Properties }}
	void On{{Camel .Name}}Changed(const F{{$DisplayName}}{{Camel .Name}}ChangedMessage& {{ueVar "In" .}}Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- range $i, $e := .Interface.Operations }}
{{- if not .Return.IsVoid }}
	void On{{Camel .Name}}Reply(const F{{$DisplayName}}{{Camel .Name}}ReplyMessage& In{{Camel .Name}}Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- end }}

{{- if len .Interface.Properties }}

	// member variable to store the last sent data
	TPimplPtr<{{$Iface}}PropertiesMsgBusData> _SentData;
{{- end}}

{{- if len .Interface.Operations }}

	TMap<FGuid, void*> ReplyPromisesMap;
	FCriticalSection ReplyPromisesMapCS;

	template <typename ResultType>
	bool StorePromise(const FGuid& Id, TPromise<ResultType>& Promise);

	template <typename ResultType>
	bool FulfillPromise(const FGuid& Id, const ResultType& Value);
{{- end }}
};
