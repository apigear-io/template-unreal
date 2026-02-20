
{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}

{{- $IfaceName := Camel .Interface.Name }}
{{- $API_MACRO := printf "%sJNI_API" (CAMEL .Module.Name) }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sJniAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
#pragma once

#include "{{$ModuleName}}/Generated/api/{{$Iface}}Interface.h"
#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}JniConnectionStatus.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include <memory>

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "HAL/CriticalSection.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

#include "{{$Iface}}JniAdapter.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Log{{$Iface}}_JNI, Log, All);

// Helper interface to expose necessary functions for native Jni function implementations.
// Main purpose is to allow it in a thread safe way, the native JNI calls are always from JNI thread.
class I{{$DisplayName}}JniAdapterAccessor
{
public:
	virtual ~I{{$DisplayName}}JniAdapterAccessor() = default;
	virtual TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> getBackendServiceForJNI() const = 0;
	virtual void jniServiceStatusChanged(bool) = 0;
};

/** @brief handles the adaption between the service implementation and the java android Service Backend
 * takes an object of the type I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface
 */
UCLASS(BlueprintType)
class {{ $API_MACRO }} {{$Class}} : public UGameInstanceSubsystem, public I{{$Iface}}SubscriberInterface, public I{{$DisplayName}}JniAdapterAccessor
{
public:
	GENERATED_BODY()

	explicit {{$Class}}();
	virtual ~{{$Class}}() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{Camel .Interface.Name}}")
	void setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> InService);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|{{Camel .Module.Name}}|{{Camel .Interface.Name}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> getBackendService();

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{Camel .Module.Name}}|{{$IfaceName}}|Jni|Remote", DisplayName = "Jni Service Started")
	F{{$ModuleName}}JniServiceStartedDelegateBP _JniServiceStartedBP;
	F{{$ModuleName}}JniServiceStartedDelegate _JniServiceStarted;
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|{{Camel .Module.Name}}|{{$IfaceName}}|Jni|Remote", DisplayName = "Jni Service Died")
	F{{$ModuleName}}JniServiceDiedDelegateBP _JniServiceDiedBP;
	F{{$ModuleName}}JniServiceDiedDelegate _JniServiceDied;

private:
	// Helper function, wraps calling java service side.
	void callJniServiceReady(bool isServiceReady);

#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	// Java instance object reference. The object is created on java service start.
	jobject m_javaJniServiceInstance = nullptr;
#endif
#endif

	{{- range $i, $e := .Interface.Signals }}
	{{- if $i }}{{nl}}{{ end }}
	void On{{Camel .Name}}Signal({{ueParams "" .Params}}) override;
	{{- end }}

{{- if len .Interface.Properties }}{{ nl }}{{ end }}
{{- range $i, $e := .Interface.Properties }}
	void On{{Camel .Name}}Changed({{ueParam "" .}}) override;
{{- end }}
	// Returns a copy of current backend. Backend may get changed from main thread.
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> getBackendServiceForJNI() const override;
	void jniServiceStatusChanged(bool isConnected) override;

	mutable FCriticalSection BackendServiceCS;

	/** Holds the service backend, can be exchanged with different implementation during runtime */
	UPROPERTY(VisibleAnywhere, Category = "{{$Category}}")
	TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> BackendService;
};
