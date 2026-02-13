{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
{{- $ModuleNameRaw := .Module.Name}}
{{- $IfaceName := Camel .Interface.Name }}
{{- $Category := printf "ApiGear|%s|%s" $ModuleName $IfaceName }}
{{- $DisplayName := printf "%s%s" $ModuleName $IfaceName }}
{{- $Class := printf "U%sJniAdapter" $DisplayName}}
{{- $Iface := printf "%s%s" $ModuleName $IfaceName }}
{{- $jniservice_name:= printf "%sjniservice" ( camel $ModuleNameRaw) }}
{{- $javaClassPath := ( join "/" (strSlice ( camel $ModuleNameRaw) $jniservice_name) ) }}
{{- $javaClassName := printf "%sJniService" $IfaceName }}
{{- $jniFullFuncPrefix := ( join "_" (strSlice "Java" ( camel $ModuleNameRaw) $jniservice_name $javaClassName ) ) }}
{{- $api_module_name:= printf "%s_api" ( camel $ModuleNameRaw) }}
{{- $javaIfClassName := printf "I%s" $IfaceName }}
{{- $javaIfClassFull := ( join "/" (strSlice (camel $ModuleNameRaw) $api_module_name $javaIfClassName ) ) }}
{{- $localClassConverter := printf "%sDataJavaConverter" (Camel .Module.Name) }}


{{- define "convert_to_java_type"}}
		{{- $localName := printf "jlocal_%s" (Camel .Name) }}
		{{- $cppropName := ueVar "" .}}
		{{- $javaClassConverter := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
		{{- $localClassConverter := printf "%sDataJavaConverter" (Camel .Schema.Module.Name) }}
		{{- if (eq $javaClassConverter "DataJavaConverter" )}}{{- $javaClassConverter = $localClassConverter }}{{ end }}
	{{- if .IsArray }}
		{{- if (eq .KindType "string")}}
		TArray<FStringView> {{$cppropName}}StringViews;
		{{$cppropName}}StringViews.Reserve({{$cppropName}}.Num());
		for (const FString& Str : {{$cppropName}})
		{
			{{$cppropName}}StringViews.Add(FStringView(Str));
		}
		auto {{$localName}}Wrapped = FJavaHelper::ToJavaStringArray(Env, {{$cppropName}}StringViews);
		static const TCHAR* errorMsg{{$localName}} = TEXT("failed to convert {{$cppropName}} to jstring array");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		jobjectArray {{$localName}} = static_cast<jobjectArray>(Env->NewLocalRef(*{{$localName}}Wrapped));
		{{- else if (eq .KindType "bool")}}
		auto len{{snake .Name}} = {{$cppropName}}.Num();
		{{jniToReturnType .}} {{$localName}} = Env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
		static const TCHAR* errorMsgAlloc{{$localName}} = TEXT("failed allocate jarray for {{$localName}}");
		if (!{{$localClassConverter}}::checkJniErrorOccured(errorMsgAlloc{{$localName}}))
		{
			TArray<jboolean> Temp{{$localName}};
			Temp{{$localName}}.SetNumUninitialized(len{{snake .Name}});
			for (int i = 0; i < len{{snake .Name}}; i++)
			{
				Temp{{$localName}}[i] = {{$cppropName}}[i] ? JNI_TRUE : JNI_FALSE;
			}
			Env->SetBooleanArrayRegion({{$localName}}, 0, len{{snake .Name}}, Temp{{$localName}}.GetData());
			static const TCHAR* errorMsg{{$localName}} = TEXT("failed set array region for {{$localName}}");
			{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		}
		{{- else if and (.IsPrimitive ) (not (eq .KindType "enum")) }}
		auto len{{snake .Name}} = {{$cppropName}}.Num();
		{{jniToReturnType .}} {{$localName}} = Env->New{{jniToEnvNameType .}}Array(len{{snake .Name}});
		static const TCHAR* errorMsgAlloc{{$localName}} = TEXT("failed allocate jarray for {{$localName}}");
		if (!{{$localClassConverter}}::checkJniErrorOccured(errorMsgAlloc{{$localName}}))
		{
			Env->Set{{jniToEnvNameType .}}ArrayRegion({{$localName}}, 0, len{{snake .Name}}, {{ if (eq .KindType "int64") -}}
		reinterpret_cast<const jlong*>({{$cppropName}}.GetData()));
		{{- else -}}
		{{$cppropName}}.GetData());
		{{- end }}
			static const TCHAR* errorMsg{{$localName}} = TEXT("failed set array region for {{$localName}}");
			{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		};
		{{- else }}
		{{- if eq .KindType "interface" }}
		// interfaces are currently not supported. {{$javaClassConverter}} returns an array with no elements. 
		{{- end }}
		{{jniToReturnType .}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Type }}Array(Env, {{$cppropName}});
		{{- end }}
	{{- else if (eq .KindType "string")}}
		auto {{$localName}}Wrapped = FJavaHelper::ToJavaString(Env, {{$cppropName}});
		static const TCHAR* errorMsg{{$localName}} = TEXT("failed converting to jstring {{$localName}}");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		jstring {{$localName}} = static_cast<jstring>(Env->NewLocalRef(*{{$localName}}Wrapped));
	{{- else if ( or (not .IsPrimitive ) (eq .KindType "enum" ) ) }}
		{{- if eq .KindType "interface" }}
		// interfaces are currently not supported. {{$javaClassConverter}} returns nullptr. 
		{{- end }}
		{{jniToReturnType .}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Type }}(Env, {{$cppropName}});
	{{- end }}
{{- end}}

{{- define "convert_to_local_cpp_value_java_param"}}
{{- $javaPropName := .Name}}
{{- $javaClassConverter := printf "%sDataJavaConverter" ( Camel .Schema.Import ) }}
{{- $local_value := printf "local_%s" (snake .Name) }}
{{- $localClassConverter := printf "%sDataJavaConverter" (Camel .Schema.Module.Name) }}
{{- if (eq $javaClassConverter "DataJavaConverter" )}}{{- $javaClassConverter = $localClassConverter }}{{ end }}
{{- if .IsArray }}
	{{ueReturn "" .}} {{$local_value}} = {{ ueDefault "" . }};
	{{- if (eq .KindType "string")}}
	{{$local_value}} = FJavaHelper::ObjectArrayToFStringTArray(Env, {{$javaPropName}});
	static const TCHAR* errorMsg{{$local_value}} = TEXT("failed to convert {{$javaPropName}} from jstring array");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$local_value}});
	{{- else if (eq .KindType "bool")}}
	jbooleanArray l_java{{Camel .Name}}Array = (jbooleanArray){{$javaPropName}};
	jsize len{{snake .Name}} = Env->GetArrayLength(l_java{{Camel .Name}}Array);
	static const TCHAR* errorMsgLen{{$local_value}} = TEXT("failed to get an array length l_java{{Camel .Name}}Array");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgLen{{$local_value}});
	{{$local_value}}.Reserve(len{{snake .Name}});
	TArray<jboolean> Temp{{Camel .Name}};
	Temp{{Camel .Name}}.SetNumUninitialized(len{{snake .Name}});
	Env->GetBooleanArrayRegion(l_java{{Camel .Name}}Array, 0, len{{snake .Name}}, Temp{{Camel .Name}}.GetData());
	static const TCHAR* errorMsg{{$local_value}} = TEXT("failed to get an array region l_java{{Camel .Name}}Array");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$local_value}});
	for (int i = 0; i < len{{snake .Name}}; i++)
	{
		{{$local_value}}.Add(Temp{{Camel .Name}}[i] == JNI_TRUE);
	}
	Env->DeleteLocalRef(l_java{{Camel .Name}}Array);
	{{- else if .IsPrimitive }}
	{{ jniToReturnType . }} l_java{{Camel .Name}}Array = ({{ jniToReturnType . }}){{$javaPropName}};
	jsize len{{snake .Name}} = Env->GetArrayLength(l_java{{Camel .Name}}Array);
	static const TCHAR* errorMsgLen{{$local_value}} = TEXT("failed to get an array length l_java{{Camel .Name}}Array");
	if (!{{$localClassConverter}}::checkJniErrorOccured(errorMsgLen{{$local_value}}))
	{
		{{$local_value}}.AddUninitialized(len{{snake .Name}});
		Env->Get{{jniToEnvNameType .}}ArrayRegion({{$javaPropName}}, 0, len{{snake .Name}}, {{ if (eq .KindType "int64") -}}
			reinterpret_cast<jlong*>({{$local_value}}.GetData()));
			{{- else -}}
			{{$local_value}}.GetData());
			{{- end }}
		static const TCHAR* errorMsg{{$local_value}} = TEXT("failed to get an array region{{$javaPropName}}");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$local_value}});
		Env->DeleteLocalRef(l_java{{Camel .Name}}Array);
	}
	{{- else}}
	{{- if eq .KindType "interface" }}
	// interfaces are currently not supported. {{$javaClassConverter}} does not fill the array. 
	{{- end }}
	{{$javaClassConverter}}::fill{{Camel .Type }}Array(Env, {{$javaPropName}}, {{$local_value}});
	{{- end }}
{{- else if eq .KindType "enum" }}
	{{ueReturn "" .}} {{$local_value}} = {{$javaClassConverter}}::get{{Camel .Type }}Value(Env, {{$javaPropName}});
{{- else if (eq .KindType "string")}}
	FString {{$local_value}} = FJavaHelper::FStringFromParam(Env, {{$javaPropName}});
{{- else if not (ueIsStdSimpleType . )}}
	{{- if eq .KindType "interface" }}
	// interfaces are currently not supported. {{$javaClassConverter}} does not fill element. 
	{{- end }}
	{{ueReturn "" .}} {{$local_value}} = {{ ueDefault "" . }};
	{{$javaClassConverter}}::fill{{Camel .Type }}(Env, {{$javaPropName}}, {{$local_value}});
{{- end }}
{{- end }}

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "{{$ModuleName}}/Generated/Jni/{{$Iface}}JniAdapter.h"
#include "{{$ModuleName}}/Generated/Jni/{{$ModuleName}}DataJavaConverter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "Engine/Engine.h"
#include "Misc/DateTime.h"
#include "HAL/Platform.h"

{{- $includes := getEmptyStringList}}
{{- range .Module.Externs }}
{{- $class := ueExtern . }}
{{- if $class.Include }}
{{- $includeName := printf "\"%s\"" $class.Include }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- end }}
{{- range .Module.Imports }}
{{- $importModuleName := Camel .Name }}
{{- $includeName := printf "\"%s/Generated/Jni/%sDataJavaConverter.h\"" $importModuleName $importModuleName }}
{{- $includes = (appendList $includes $includeName) }}
{{- end }}
{{- $includes = unique $includes }}
{{- if len $includes}}{{- nl}}{{end}}
{{- range $includes }}
#include {{ .}}
{{- end }}
{{- if or (len .Module.Enums) (len .Module.Structs) }}
#include "{{$ModuleName}}/Generated/api/{{ $ModuleName }}_data.h"
{{- end }}

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

DEFINE_LOG_CATEGORY(Log{{$Iface}}_JNI);

namespace
{
std::atomic<I{{$DisplayName}}JniAdapterAccessor*> g{{$Class}}Handle{nullptr};
}

#if PLATFORM_ANDROID && USE_ANDROID_JNI
{{- $cachedClass:= printf "javaClass%s" (Camel .Interface.Name) }}
{{- $serviceClass:= printf "javaService" }}

struct F{{$Class}}CacheData
{
	jclass {{$serviceClass}} = nullptr;
	jmethodID ReadyMethodID = nullptr;
{{- range .Interface.Properties }}
	jmethodID {{ Camel .Name}}ChangedMethodID = nullptr;
{{- end }}
{{- range .Interface.Signals }}
	jmethodID {{ Camel .Name}}SignalMethodID = nullptr;
{{- end }}

	~F{{$Class}}CacheData()
	{
		if ({{$serviceClass}})
		{
			JNIEnv* Env = FAndroidApplication::GetJavaEnv();
			if (Env)
			{
				Env->DeleteGlobalRef({{$serviceClass}});
			}
		}
	}
};

class {{$Class}}Cache
{
public:
	static TSharedPtr<F{{$Class}}CacheData, ESPMode::ThreadSafe> Get()
	{
		FScopeLock Lock(&CacheLock);
		return CacheData;
	}

	static void init();
	static void clear();

private:
	static FCriticalSection CacheLock;
	static TSharedPtr<F{{$Class}}CacheData, ESPMode::ThreadSafe> CacheData;
};

FCriticalSection {{$Class}}Cache::CacheLock;
TSharedPtr<F{{$Class}}CacheData, ESPMode::ThreadSafe> {{$Class}}Cache::CacheData;

void {{$Class}}Cache::init()
{
	auto NewData = MakeShared<F{{$Class}}CacheData, ESPMode::ThreadSafe>();
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
{{- $javaServiceTypeName := printf "%sJniService" (Camel .Interface.Name) }}
{{- $jniservice_name:= printf "%sjniservice" ( camel $ModuleName) }}
{{- $javaServicePath := ( join "/" (strSlice ( camel $ModuleName) $jniservice_name) ) }}

	NewData->{{$serviceClass}} = FAndroidApplication::FindJavaClassGlobalRef("{{$javaServicePath}}/{{$javaServiceTypeName}}");
	static const TCHAR* errorMsgCls = TEXT("failed to get java {{$javaServicePath}}/{{$javaServiceTypeName}}");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgCls);
	NewData->ReadyMethodID = env->GetMethodID(NewData->{{$serviceClass}}, "nativeServiceReady", "(Z)V");
	static const TCHAR* errorMsgReadyMethod = TEXT("failed to get java nativeServiceReady, (Z)V for {{$javaServicePath}}/{{$javaServiceTypeName}}");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgReadyMethod);
{{- range .Interface.Properties }}
	{{- $signatureParam := jniJavaSignatureParam . }}
	NewData->{{ Camel .Name}}ChangedMethodID = env->GetMethodID(NewData->{{$serviceClass}}, "on{{Camel .Name}}Changed", "({{$signatureParam}})V");
	static const TCHAR* errorMsg{{Camel .Name}}Changed = TEXT("failed to get java on{{Camel .Name}}Changed, ({{$signatureParam}})V for {{$javaServicePath}}/{{$javaServiceTypeName}}");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{Camel .Name}}Changed);
{{- end }}
{{- range .Interface.Signals }}
	{{- $signatureParams := jniJavaSignatureParams .Params }}
	NewData->{{ Camel .Name}}SignalMethodID = env->GetMethodID(NewData->{{$serviceClass}}, "on{{Camel .Name}}", "({{$signatureParams}})V");
	static const TCHAR* errorMsg{{Camel .Name}}Signal = TEXT("failed to get java on{{Camel .Name}}, ({{$signatureParams}})V for {{$javaServicePath}}/{{$javaServiceTypeName}}");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{Camel .Name}}Signal);
{{- end }}

	{
		FScopeLock Lock(&CacheLock);
		CacheData = NewData;
	}
}

void {{$Class}}Cache::clear()
{
	FScopeLock Lock(&CacheLock);
	CacheData.Reset();
}

#endif

{{- if .Interface.Description }}
/**
	\brief {{.Interface.Description}}
*/
{{- end }}
{{$Class}}::{{$Class}}()
{
}

void {{$Class}}::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	g{{$Class}}Handle.store(this, std::memory_order_release);
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	{{$Class}}Cache::init();
	auto Env = FAndroidApplication::GetJavaEnv();
	jclass BridgeClass = FAndroidApplication::FindJavaClassGlobalRef("{{$javaClassPath}}/{{$javaClassName}}Starter");
	static const TCHAR* errorMsgCls = TEXT("{{Camel .Module.Name}}JavaServiceStarter; class not found");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgCls);
	if (BridgeClass == nullptr)
	{
		return;
	}
	auto functionSignature = "(Landroid/content/Context;)L{{$javaIfClassFull}};";
	jmethodID StartMethod = Env->GetStaticMethodID(BridgeClass, "start", functionSignature);
	static const TCHAR* errorMsgMethodId = TEXT("{{Camel .Module.Name}}JavaServiceStarter::start; method not found");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgMethodId);
	if (StartMethod == nullptr)
	{
		return;
	}
	jobject Activity = FJavaWrapper::GameActivityThis;
	jobject localRef = FJavaWrapper::CallStaticObjectMethod(Env, BridgeClass, StartMethod, Activity);
	static const TCHAR* errorMsgCall = TEXT("{{Camel .Module.Name}}JavaServiceStarter failed to call start method");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgCall);
	m_javaJniServiceInstance = Env->NewGlobalRef(localRef);
	Env->DeleteLocalRef(localRef);
	Env->DeleteGlobalRef(BridgeClass);
#endif
#endif
}

void {{$Class}}::Deinitialize()
{
	callJniServiceReady(false);
	g{{$Class}}Handle.store(nullptr, std::memory_order_release);
#if PLATFORM_ANDROID
#if USE_ANDROID_JNI
	if (m_javaJniServiceInstance)
	{
		FAndroidApplication::GetJavaEnv()->DeleteGlobalRef(m_javaJniServiceInstance);
		m_javaJniServiceInstance = nullptr;
	}
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	jclass BridgeClass = FAndroidApplication::FindJavaClassGlobalRef("{{$javaClassPath}}/{{$javaClassName}}Starter");
	static const TCHAR* errorMsgCls = TEXT("{{Camel .Module.Name}}JavaServiceStarter; class not found");
	{{$localClassConverter}}::checkJniErrorOccured(errorMsgCls);
	if (BridgeClass != nullptr)
	{
		jmethodID StopMethod = Env->GetStaticMethodID(BridgeClass, "stop", "(Landroid/content/Context;)V");
		static const TCHAR* errorMsgMethodId = TEXT("{{Camel .Module.Name}}JavaServiceStarter::stop; method not found");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsgMethodId);
		if (StopMethod != nullptr)
		{
			jobject Activity = FJavaWrapper::GameActivityThis; // Unreal's activity
			FJavaWrapper::CallStaticVoidMethod(Env, BridgeClass, StopMethod, Activity);
			static const TCHAR* errorMsgCall = TEXT("{{Camel .Module.Name}}JavaServiceStarter failed to call stop");
			{{$localClassConverter}}::checkJniErrorOccured(errorMsgCall);
		}
		Env->DeleteGlobalRef(BridgeClass);
	}
	{{$Class}}Cache::clear();
#endif
#endif
	Super::Deinitialize();
}

void {{$Class}}::setBackendService(TScriptInterface<I{{Camel .Module.Name}}{{$IfaceName}}Interface> InService)
{
	{
		FScopeLock Lock(&BackendServiceCS);
		// unsubscribe from old backend
		if (BackendService != nullptr)
		{
			U{{$Iface}}Publisher* BackendPublisher = BackendService->_GetPublisher();
			checkf(BackendPublisher, TEXT("Cannot unsubscribe from delegates from backend service {{$Iface}}"));
			BackendPublisher->Unsubscribe(TWeakInterfacePtr<I{{$Iface}}SubscriberInterface>(this));
		}

		// only set if interface is implemented
		checkf(InService.GetInterface() != nullptr, TEXT("Cannot set backend service - interface {{$Iface}} is not fully implemented"));

		// subscribe to new backend
	{{- $Service := printf "I%sInterface" $Iface }}
		BackendService = InService;
		U{{$Iface}}Publisher* BackendPublisher = BackendService->_GetPublisher();
		checkf(BackendPublisher, TEXT("Cannot subscribe to delegates from backend service {{$Iface}}"));
		// connect property changed signals or simple events
		BackendPublisher->Subscribe(TWeakInterfacePtr<I{{$Iface}}SubscriberInterface>(this));
	}

	callJniServiceReady(true);
}

TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> {{$Class}}::getBackendService()
{
	FScopeLock Lock(&BackendServiceCS);
	return BackendService;
}

void {{$Class}}::callJniServiceReady(bool isServiceReady)
{
	UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$Class}} call nativeServiceReady the service function "));

#if PLATFORM_ANDROID && USE_ANDROID_JNI
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto Cache = {{$Class}}Cache::Get();
		if (!m_javaJniServiceInstance || !Cache || !Cache->ReadyMethodID)
		{
			UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:nativeServiceReady(Z)V not found"));
			return;
		}

		FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, Cache->ReadyMethodID, isServiceReady);
		static const TCHAR* errorMsg = TEXT("{{$javaClassPath}}/{{$javaClassName}}:nativeServiceReady(Z)V CLASS not found");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg);
	}
#endif
}

{{- range .Interface.Signals }}

void {{$Class}}::On{{Camel .Name}}Signal({{ueParams "" .Params}})
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("Notify java jni {{$Class}}::on{{Camel .Name}} "));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		{{- $signatureParams:= jniJavaSignatureParams .Params}}
		auto Cache = {{$Class}}Cache::Get();
		if (!Cache || m_javaJniServiceInstance == nullptr)
		{
			UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:on{{Camel .Name}} ({{$signatureParams}})V CLASS not found"));
			return;
		}
		jmethodID MethodID = Cache->{{ Camel .Name}}SignalMethodID;
		if (MethodID == nullptr)
		{
			UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:on{{Camel .Name}} ({{$signatureParams}})V not found"));
			return;
		}

		{{- range .Params -}}
		{{template "convert_to_java_type" .}}
		{{- end }}

		FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID{{- if len (.Params) }}, {{ end}}
		{{- range $idx, $p := .Params -}} {{- if $idx}}, {{ end -}}
			{{- $javaPropName := Camel .Name}}
			{{- $cppropName := ueVar "" .}}
			{{- $localName := printf "jlocal_%s" $javaPropName }}
			{{- if .IsArray }}{{$localName}}
		{{- else if or ( or (eq .KindType "enum") (eq .KindType "string") ) (not .IsPrimitive ) }}{{$localName}}
		{{- else }}{{$cppropName}}
		{{- end -}}
		{{- end -}});
		static const TCHAR* errorMsg = TEXT("{{$javaClassPath}}/{{$javaClassName}} failed to call on{{Camel .Name}} ({{$signatureParams}})V");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg);

		{{- range $idx, $p := .Params -}}
			{{- $javaPropName := Camel .Name}}
			{{- $localName := printf "jlocal_%s" $javaPropName }}
		{{- if or ( or .IsArray (eq .KindType "enum" ) ) }}
		Env->DeleteLocalRef({{$localName}});
		{{- else if not ( ueIsStdSimpleType .) }}
		Env->DeleteLocalRef({{$localName}});
		{{- end }}
		{{- end }}
	}
#endif
}
{{- end }}


{{- range .Interface.Properties }}
{{- if eq .KindType "interface" }}
// Interfaces as properties are currently not supported for jni. Generated for compatibility. 
{{- end }}
void {{$Class}}::On{{Camel .Name}}Changed({{ueParam "" .}})
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("Notify java jni {{$Class}}::On{{Camel .Name}} "));
	{{- $signature := printf "(%s)V" (jniJavaSignatureParam .)}}
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		auto Cache = {{$Class}}Cache::Get();
		if (!Cache)
		{
			UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}::on{{Camel .Name}}Changed{{$signature}} CLASS not found"));
			return;
		}
		jmethodID MethodID = Cache->{{ Camel .Name}}ChangedMethodID;
		if (MethodID == nullptr)
		{
			UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$javaClassPath}}/{{$javaClassName}}:on{{Camel .Name}}Changed{{$signature}} not found"));
			return;
		}
		{{- nl}}
		{{- $cppropName := ueVar "" .}}
		{{- template "convert_to_java_type" .}}
		{{- $javaLocalName := printf "jlocal_%s" (Camel .Name) }}
		{{- if or ( or ( .IsArray ) (eq .KindType "string")) ( or (eq .KindType "enum") (not (ueIsStdSimpleType .)) ) }}
		FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID, {{$javaLocalName}});

		{{- if and .IsArray }}
		Env->DeleteLocalRef({{$javaLocalName}});
		{{- else if not (or (ueIsStdSimpleType .) (eq .KindType "enum")) }}
		Env->DeleteLocalRef({{$javaLocalName}});
		{{- end}}
		{{- else }}
		FJavaWrapper::CallVoidMethod(Env, m_javaJniServiceInstance, MethodID, {{$cppropName}});
		{{- end }}
		static const TCHAR* errorMsg = TEXT("{{$javaClassPath}}/{{$javaClassName}} failed to call on{{Camel .Name}}Changed ({{$signature}})V");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg);
	}
#endif
}
{{- end }}

TScriptInterface<I{{Camel .Module.Name}}{{Camel .Interface.Name}}Interface> {{$Class}}::getBackendServiceForJNI() const
{
	FScopeLock Lock(&BackendServiceCS);
	return BackendService;
}

void {{$Class}}::jniServiceStatusChanged(bool isConnected)
{
	TWeakObjectPtr<{{$Class}}> WeakThis(this);
	if (isConnected)
	{
		AsyncTask(ENamedThreads::GameThread, [WeakThis]()
			{
			if (WeakThis.Get() == nullptr)
			{
				UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("Attempted to notify service started on JniAdapter which is already dead. Aborting..."));
				return;
			}
			WeakThis->_JniServiceStartedBP.Broadcast();
			WeakThis->_JniServiceStarted.Broadcast();
		});
	}
	else
	{
		AsyncTask(ENamedThreads::GameThread, [WeakThis]()
			{
			if (WeakThis.Get() == nullptr)
			{
				UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("Attempted to notify service died on JniAdapter which is already dead. Aborting..."));
				return;
			}
			WeakThis->_JniServiceDiedBP.Broadcast();
			WeakThis->_JniServiceDied.Broadcast();
		});
	}
}

#if PLATFORM_ANDROID && USE_ANDROID_JNI

{{- range .Interface.Operations }}
JNI_METHOD {{ jniToReturnType .Return}} {{$jniFullFuncPrefix}}_native{{ Camel .Name }}(JNIEnv* Env, jclass Clazz{{- if len (.Params) }}, {{end}}{{jniJavaParams "" .Params }})
{
	UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$jniFullFuncPrefix}}_native{{Camel .Name}}"));

{{- range .Params -}}
	{{- template "convert_to_local_cpp_value_java_param" . }}
{{- end }}

	auto jniAccessor = g{{$Class}}Handle.load();
	if (!jniAccessor)
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniFullFuncPrefix}}_native{{ Camel .Name }}, {{$Class}} not valid to use, probably too early or too late."));
		{{- if .Return.IsVoid }}
		return;
		{{- else}}
		return {{ jniEmptyReturn .Return }};
		{{- end}}
	}

	auto service = jniAccessor->getBackendServiceForJNI();
	if (service != nullptr)
	{
	{{- $cppropName := "result"}}
		{{ if not .Return.IsVoid }}auto {{$cppropName}} = {{ end -}}
	service->{{Camel .Name}}(
	{{- range $idx, $p := .Params -}}
		{{- if $idx}}, {{ end -}}
		{{- $local_value := printf "local_%s" (snake .Name) -}}
		{{- if or .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .)) ) }}{{$local_value -}}
		{{- else }}{{.Name}}
		{{- end -}}
	{{- end -}}
	);

	{{- if .Return.IsVoid }}
		return;
	{{- else if or .Return.IsArray ( or (eq .Return.KindType "enum") (not (ueIsStdSimpleType .Return)) ) }}
		{{- $localName := "jresult" }}
		{{- $javaClassConverter := printf "%sDataJavaConverter" ( Camel .Return.Schema.Import ) }}
		{{- if (eq $javaClassConverter "DataJavaConverter" )}}{{- $javaClassConverter = printf "%sDataJavaConverter" $ModuleName }}{{ end }}
	{{- if .Return.IsArray }}
	{{- if (eq .Return.KindType "string")}}
		TArray<FStringView> {{$cppropName}}StringViews;
		{{$cppropName}}StringViews.Reserve({{$cppropName}}.Num());
		for (const FString& Str : {{$cppropName}})
		{
			{{$cppropName}}StringViews.Add(FStringView(Str));
		}
		auto {{$localName}}Wrapped = FJavaHelper::ToJavaStringArray(Env, {{$cppropName}}StringViews);
		auto {{$localName}} = static_cast<jobjectArray>(Env->NewLocalRef(*{{$localName}}Wrapped));
		static const TCHAR* errorMsgResult = TEXT("failed to convert result to jstring array in call native{{Camel .Name}} for {{$javaClassPath}}/{{$javaClassName}}");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsgResult);
	{{- else if (eq .Return.KindType "bool")}}
		auto len = {{$cppropName}}.Num();
		{{jniToReturnType .Return}} {{$localName}} = Env->New{{jniToEnvNameType .Return}}Array(len);
		static const TCHAR* errorMsgAlloc{{$localName}} = TEXT("failed to allocate an array in call native{{Camel .Name}} for {{$javaClassPath}}/{{$javaClassName}}");
		if (!{{$localClassConverter}}::checkJniErrorOccured(errorMsgAlloc{{$localName}}))
		{
			TArray<jboolean> Temp;
			Temp.SetNumUninitialized(len);
			for (int i = 0; i < len; i++)
			{
				Temp[i] = {{$cppropName}}[i] ? JNI_TRUE : JNI_FALSE;
			}
			Env->SetBooleanArrayRegion({{$localName}}, 0, len, Temp.GetData());
			static const TCHAR* errorMsg{{$localName}} = TEXT("failed to set an array region in call native{{Camel .Name}} for {{$javaClassPath}}/{{$javaClassName}}");
			{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		}
	{{- else if and (.Return.IsPrimitive ) (not (eq .Return.KindType "enum")) }}
		auto len = {{$cppropName}}.Num();
		{{jniToReturnType .Return}} {{$localName}} = Env->New{{jniToEnvNameType .Return}}Array(len);
		static const TCHAR* errorMsgAlloc{{$localName}} = TEXT("failed to allocate an array in call native{{Camel .Name}} for {{$javaClassPath}}/{{$javaClassName}}");
		if (!{{$localClassConverter}}::checkJniErrorOccured(errorMsgAlloc{{$localName}}))
		{
			Env->Set{{jniToEnvNameType .Return}}ArrayRegion({{$localName}}, 0, len, {{ if (eq .Return.KindType "int64") -}}
		reinterpret_cast<const jlong*>({{$cppropName}}.GetData()));
		{{- else -}}
		{{$cppropName}}.GetData());
		{{- end }}
			static const TCHAR* errorMsg{{$localName}} = TEXT("failed to set an array region in call native{{Camel .Name}} for {{$javaClassPath}}/{{$javaClassName}}");
			{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		};
	{{- else }}
		{{- if eq .Return.KindType "interface" }}
		// interfaces are currently not supported. {{$javaClassConverter}} returns empty array. 
		{{- end }}
		{{jniToReturnType .Return}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Return.Type }}Array(Env, {{$cppropName}});
	{{- end }}
		{{- else if (eq .Return.KindType "string")}}
		auto {{$localName}}Wrapped = FJavaHelper::ToJavaString(Env, {{$cppropName}});
		static const TCHAR* errorMsg{{$localName}} = TEXT("failed to convert to jstring in call native{{Camel .Name}} for {{$javaClassPath}}/{{$javaClassName}}");
		{{$localClassConverter}}::checkJniErrorOccured(errorMsg{{$localName}});
		jstring {{$localName}} = static_cast<jstring>(Env->NewLocalRef(*{{$localName}}Wrapped));
		{{- else if ( or (not (ueIsStdSimpleType .Return)) (eq .Return.KindType "enum" ) ) }}
		{{- if eq .Return.KindType "interface" }}
		// interfaces are currently not supported. {{$javaClassConverter}} returns nullptr. 
		{{- end }}
		{{jniToReturnType .Return}} {{$localName}} = {{$javaClassConverter}}::makeJava{{Camel .Return.Type }}(Env, {{$cppropName}});
		{{- end }}
		return {{$localName}};
		{{- else }}
		return {{$cppropName}};
		{{- end }}
	}
	else
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("service not valid"));
		{{- if .Return.IsVoid }}
		return;
		{{- else}}
		return {{ jniEmptyReturn .Return }};
		{{- end}}
	}
}
{{- end}}

	

{{- range .Interface.Properties }}
{{- if not .IsReadOnly }}
{{- $javaPropName := .Name}}
JNI_METHOD void {{$jniFullFuncPrefix}}_nativeSet{{ Camel .Name }}(JNIEnv* Env, jclass Clazz, {{jniJavaParam "" . }})
{
	UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$jniFullFuncPrefix}}_nativeSet{{Camel .Name}}"));
	{{- if or .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .)) ) }}
	{{- nl}}
	{{- end}}
	{{- template "convert_to_local_cpp_value_java_param" . }}
	{{- $hasLocalVar := or .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .)) ) }}
	{{- $local_value := printf "local_%s" (snake .Name) }}

	auto jniAccessor = g{{$Class}}Handle.load();
	if (!jniAccessor)
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniFullFuncPrefix}}_nativeSet{{ Camel .Name }}, {{$Class}} not valid to use, probably too early or too late."));
		return;
	}

	auto service = jniAccessor->getBackendServiceForJNI();
	if (service != nullptr)
	{
	{{- if $hasLocalVar }}
		service->Set{{Camel .Name}}({{$local_value}});
	{{- else}}
		service->Set{{Camel .Name}}({{$javaPropName}});
	{{- end}}
	}
	else
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("service not valid, cannot set value for {{.Name}}"));
	}
}
{{- end}}

JNI_METHOD {{jniToReturnType .}} {{$jniFullFuncPrefix}}_nativeGet{{ Camel .Name }}(JNIEnv* Env, jclass Clazz)
{
	UE_LOG(Log{{$Iface}}_JNI, Verbose, TEXT("{{$jniFullFuncPrefix}}_nativeGet{{Camel .Name}}"));

	auto jniAccessor = g{{$Class}}Handle.load();
	if (!jniAccessor)
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniFullFuncPrefix}}_nativeGet{{Camel .Name }}, {{$Class}} not valid to use, probably too early or too late."));
		return {{ jniEmptyReturn . }};
	}

	auto service = jniAccessor->getBackendServiceForJNI();
	if (service != nullptr)
	{
	{{- $cppropName := ueVar "" .}}
		auto {{$cppropName}} = service->Get{{Camel .Name}}();
	{{- if or .IsArray ( or (eq .KindType "enum") (not (ueIsStdSimpleType .)) ) }}
		{{- nl}}
		{{- template "convert_to_java_type" .}}
		{{- $localName := printf "jlocal_%s" (Camel .Name) }}
		return {{$localName}};
	{{- else }}
		return {{$cppropName}};
	{{- end }}
	}
	else
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("service not available, try setting a backend service "));
		return {{ jniEmptyReturn . }};
	}
}
{{- end }}

{{- $javaStarterClassName := printf "%sJniServiceStarter" $IfaceName }}
{{- $jniStarterFullFuncPrefix := ( join "_" (strSlice "Java" ( camel $ModuleNameRaw) $jniservice_name $javaStarterClassName ) ) }}

JNI_METHOD void {{$jniStarterFullFuncPrefix}}_nativeOnAndroidServiceConnectionStatusChanged(JNIEnv* Env, jclass Clazz, jboolean value)
{
	auto jniAccessor = g{{$Class}}Handle.load();
	if (!jniAccessor)
	{
		UE_LOG(Log{{$Iface}}_JNI, Warning, TEXT("{{$jniStarterFullFuncPrefix}}_nativeOnAndroidServiceConnectionStatusChanged, {{$Class}} not valid to use, probably too early or too late."));
		return;
	}

	jniAccessor->jniServiceStatusChanged(value);
}
#endif
