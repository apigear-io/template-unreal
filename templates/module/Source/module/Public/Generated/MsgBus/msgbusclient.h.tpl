
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
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION < 5)
#include "Engine/EngineTypes.h"
#else
#include "Engine/TimerHandle.h"
#endif
#include "Templates/PimplPtr.h"
#include "IMessageContext.h"
#include "{{$Iface}}MsgBusClient.generated.h"

class FMessageEndpoint;
// messages
struct F{{$DisplayName}}InitMessage;
struct F{{$Iface}}PongMessage;
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

USTRUCT(BlueprintType)
struct F{{$DisplayName}}Stats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Current round trip time in MS")
	float CurrentRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Average round trip time in MS")
	float AverageRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Maximum round trip time in MS")
	float MaxRTT_MS = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Minimum round trip time in MS")
	float MinRTT_MS = 10000.0f;
};
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(F{{$Iface}}StatsUpdatedDelegate, F{{$DisplayName}}Stats, Stats);

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
	void _Connect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	void _Disconnect();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	bool _IsConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	const F{{$DisplayName}}Stats& _GetStats() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Statistics Updated")
	F{{$Iface}}StatsUpdatedDelegate _StatsUpdated;

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

	void _DiscoverService();
	FMessageAddress ServiceAddress;

	// connection health
	double _LastHbTimestamp = 0.0;
	double _LastConnectionWarningTimestamp = 0.0;
	TArray<float> PingRTTBuffer;
	static const size_t PING_RTT_BUFFER_SIZE = 60;
	size_t CurrentPingCounter = 0;
	float _CalculateAverageRTT() const;
	F{{$DisplayName}}Stats Stats;
	FTimerHandle _HeartbeatTimerHandle;
	void _OnHeartbeat();
	uint32 _HeartbeatIntervalMS = 100;

	// connection handling
	void OnConnectionInit(const F{{$DisplayName}}InitMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnPong(const F{{$DisplayName}}PongMessage& IntMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
	void OnServiceClosedConnection(const F{{$DisplayName}}ServiceDisconnectMessage& InInitMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- range $i, $e := .Interface.Signals }}
	void On{{Camel .Name}}(const F{{$DisplayName}}{{Camel .Name}}SignalMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- range $i, $e := .Interface.Properties }}
	void On{{Camel .Name}}Changed(const F{{$DisplayName}}{{Camel .Name}}ChangedMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
{{- end }}
{{- range $i, $e := .Interface.Operations }}
{{- if not .Return.IsVoid }}
	void On{{Camel .Name}}Reply(const F{{$DisplayName}}{{Camel .Name}}ReplyMessage& InMessage, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);
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
