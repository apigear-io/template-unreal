{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sMQTT_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMQTTClient" $DisplayName}}
{{- $abstractclass := printf "UAbstract%s%s" (Camel .Module.Name) (Camel .Interface.Name) }}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/api/Abstract{{$Iface}}.h"
#include "Containers/Map.h"
#include "HAL/CriticalSection.h"
#include "Async/Future.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "ApiGearMQTTTypes.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Misc/Guid.h"
#include "{{$Iface}}MQTTClient.generated.h"

{{- if len .Interface.Properties }}

class {{$Iface}}PropertiesData;
{{- end}}
DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}MQTTClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public {{$abstractclass}}
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();

	// only needed in 4.25 to use TUniquePtr<{{$Iface}}PropertiesData>
	{{$Class}}(FVTableHelper& Helper);
	virtual ~{{$Class}}();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
{{- range .Interface.Properties }}
	{{ueReturn "" .}} Get{{Camel .Name}}() const override;
{{- if not .IsReadOnly }}
	void Set{{Camel .Name}}({{ueParam "" .}}) override;
{{- end }}
{{ end }}
	// operations
{{- range $i, $e := .Interface.Operations }}
{{- if $i }}{{nl}}{{ end }}
	{{ueReturn "" .Return}} {{Camel .Name}}({{ueParams "" .Params}}) override;
{{- if not .Return.IsVoid }}
	TFuture<{{ueReturn "" .Return}}> {{Camel .Name}}Async({{ueParams "" .Params}}) override;
{{- end }}
{{- end }}

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{$ModuleName}}|{{$IfaceName}}|Remote")
	bool _IsSubscribed() const;

private:
	void onConnectionStatusChanged(bool bIsConnected);

	/// @brief factory to create the topic map which is used for bindings
	/// @return map with all topics and corresponding function callbacks
	TMap<FString, ApiGear::MQTT::FCallbackFunction> createTopicMap(const FString& ClientId);

{{- range .Interface.Properties}}

	/// @brief sets the value for the property {{Camel .Name}} coming from the service
	/// @param InMsg contains the param of the type {{ueReturn "" .}}
	void set{{Camel .Name}}Local(const IApiGearMqttClient::FReceivedMessage& InMsg);
{{- end }}

{{- range .Interface.Signals}}

	/// @brief publishes the value for the signal {{Camel .Name}} coming from the service
	/// @param InMsg contains the param(s) of the type(s){{if .Params}} {{ueParams "" .Params}}{{end}}
	void on{{Camel .Name}}(const IApiGearMqttClient::FReceivedMessage& InMsg);
{{- end }}

	/// @brief callback for invoke replies with return value
	/// @param InMsg contains the result payload and MQTT 5 CorrelationData identifying the call
	void onInvokeReply(const IApiGearMqttClient::FReceivedMessage& InMsg);

{{- if len .Interface.Properties }}

	// member variable to store the last sent data
	TPimplPtr<{{$Iface}}PropertiesData> _SentData;
{{- end}}
	TScriptInterface<class IApiGearConnection> Connection;
	TMap<FString, ApiGear::MQTT::FCallbackFunction> Topics;

	// subscription readiness tracking
	bool bIsSubscribed = false;
	bool bAnySubscribeFailed = false;
	int32 PendingSubscriptions = 0;
	void DecrementPendingSubscription(bool bSuccess);

	// response handler map for RPC replies with return values
	TMap<FGuid, ApiGear::MQTT::InvokeReplyFunc> ResponseHandlerMap;
	FCriticalSection ResponseHandlerMutex;
	FGuid RegisterResponseHandler(ApiGear::MQTT::InvokeReplyFunc&& Handler);
};
