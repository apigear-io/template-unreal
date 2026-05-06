{{ template "copyright" }}
{{ template "generated_warning" }}
{{- $ModuleName := Camel .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sMQTT_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sMQTTAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$Iface}}Interface.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ApiGearMQTTTypes.h"
#include "{{$Iface}}MQTTAdapter.generated.h"

class UApiGearMQTTHost;

DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}MQTTAdapter, Log, All);

/** @brief handles the adaption between the service implementation and the MQTT protocol
 * takes an object of the type I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface
 * and publishes state changes via MQTT topics
 */
UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}SubscriberInterface
{
	GENERATED_BODY()
public:
	explicit {{$Class}}();
	virtual ~{{$Class}}() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService);

	UFUNCTION(BlueprintCallable, Category = "{{$Category}}")
	void setMQTTHost(TSoftObjectPtr<UApiGearMQTTHost> InHost);

private:
	void OnConnectionStatusChanged(bool InIsConnected);

	/// @brief factory to create the topic map which is used for bindings
	/// @return map with all topics and corresponding function callbacks
	TMap<FString, ApiGear::MQTT::FCallbackFunction> createTopicMap();

	// ISubscriberInterface
{{- range $i, $e := .Interface.Signals }}
{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Signal({{ueParams "" .Params}}) override;
{{- end }}
{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Changed({{ueParam "" .}}) override;
{{- end }}

	// incoming MQTT handlers
{{- range .Interface.Operations }}
	void OnInvoke{{Camel .Name}}(const IApiGearMqttClient::FReceivedMessage& InMsg);
{{- end }}
{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
	void OnSet{{Camel .Name}}(const IApiGearMqttClient::FReceivedMessage& InMsg);
{{- end }}
{{- end }}

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> BackendService;

	TMap<FString, ApiGear::MQTT::FCallbackFunction> Topics;
	bool bIsConnected{false};

	/** The host holding the MQTT connection */
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
