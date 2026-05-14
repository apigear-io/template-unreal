<?xml version="1.0" encoding="utf-8"?>

<root xmlns:android="http://schemas.android.com/apk/res/android">
	<trace enable="true"/>
	<init>
		<log text="android {{.Module.Name}} init"/>
	</init>

	<androidManifestUpdates>
		{{- $moduleName := .Module.Name }}
		{{- $service_package_name := printf "%s_android_service" (camel $moduleName) }} 
		<addPermission android:name="{{camel $moduleName}}.{{$service_package_name}}.PERMISSION_BIND"/>
		<addElements tag="queries">
				<package android:name="{{camel $moduleName}}.{{$service_package_name}}" />
		</addElements>

		<addElements tag="application">
		
		{{- range .Module.Interfaces -}}
		<service
			{{- $service_package_name := printf "%s_android_service" (camel $moduleName) }} 
			android:name="{{camel $moduleName}}.{{$service_package_name}}.{{Camel .Name}}ServiceAdapter"
			android:enabled="true"
			android:exported="true">
		</service>
		{{- end }}
		</addElements>

	</androidManifestUpdates>

	<resourceCopies>
		<copyDir src="$S(PluginDir)/buildsystem" dst="$S(BuildDir)/gradle/buildsystem" />
		{{- $service_package_name := printf "%s_android_service" (camel $moduleName) }}
		{{- $client_package_name := printf "%s_android_client" (camel $moduleName) }}
		{{- $impl_package_name := printf "%s_impl" (camel $moduleName) }}
		{{- $messenger_package_name := printf "%s_android_messenger" (camel $moduleName) }}
		{{- $api_package_name := printf "%s_api" (camel $moduleName) }}
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$service_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$service_package_name}}" />
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$client_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$client_package_name}}" />
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$api_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$api_package_name}}" />
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$messenger_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$messenger_package_name}}" />
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$impl_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$impl_package_name}}" />
		{{- $jniservice_name:= printf "%sjniservice" (camel $moduleName ) }}
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$jniservice_name}}" dst="$S(BuildDir)/src/{{$jniservice_name}}" />
		{{- $jniclient_name:= printf "%sjniclient" (camel $moduleName ) }}
		<copyDir src="$S(PluginDir)/../../../../android/{{camel $moduleName}}/{{$jniclient_name}}" dst="$S(BuildDir)/src/{{$jniclient_name}}" />
	</resourceCopies>

	<baseBuildGradleAdditions>
		<addElements tag="buildscript">
			<insertValue value="apply from: 'buildsystem/config.gradle'"/>
			<insertValue value="apply from: 'buildsystem/dependencies.gradle'"/>
			<insertNewline/>
		</addElements>
	</baseBuildGradleAdditions>

	<settingsGradleAdditions>
		<insert>
			<![CDATA[
      include ':{{camel $moduleName}}_api'
      include ':{{camel $moduleName}}_impl'
      include ':{{camel $moduleName}}_android_service'
      include ':{{camel $moduleName}}_android_client'
      include ':{{camel $moduleName}}_android_messenger'
    ]]>
		</insert>
	
	</settingsGradleAdditions>

	<buildGradleAdditions>
		<insert>
            <![CDATA[
                dependencies {
                implementation project(':{{camel $moduleName}}_api')
                implementation project(':{{camel $moduleName}}_impl')
                implementation project(':{{camel $moduleName}}_android_service')
                implementation project(':{{camel $moduleName}}_android_client')
                implementation project(':{{camel $moduleName}}_android_messenger')
                }
            ]]>
        </insert>
		<insert>
			<![CDATA[
tasks.configureEach { task ->
	if (task.name == 'assembleDebug') {
		task.dependsOn ':{{camel $moduleName}}_api:assembleDebug'
		task.dependsOn ':{{camel $moduleName}}_impl:assembleDebug'
		task.dependsOn ':{{camel $moduleName}}_android_service:assembleDebug'
		task.dependsOn ':{{camel $moduleName}}_android_client:assembleDebug'
		task.dependsOn ':{{camel $moduleName}}_android_messenger:assembleDebug'
	}
	if (task.name == 'assembleRelease') {
		task.dependsOn ':{{camel $moduleName}}_api:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_impl:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_android_service:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_android_client:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_android_messenger:assembleRelease'
	}
}

]]>
		</insert>
	</buildGradleAdditions>


	<proguardAdditions>
		<insert>
		{{- range .Module.Interfaces -}}
			{{- $jniservice_name:= printf "%sjniservice" (camel $moduleName) }}
			-keep class {{camel $moduleName}}.{{$jniservice_name}}.{{Camel .Name}}JniService {
			public *;
			}
			-keep class {{camel $moduleName}}.{{$jniservice_name}}.{{Camel .Name}}JniServiceStarter {
			public *;
			}
			{{- $jniclient_name:= printf "%sjniclient"  (camel $moduleName) }}
			-keep class {{camel $moduleName}}.{{$jniclient_name}}.{{Camel .Name}}JniClient {
			public *;
			}
		{{- end }}
		</insert>
	</proguardAdditions>



	<!-- optional additions to the GameActivity class in GameActivity.java -->
	<gameActivityClassAdditions>
{{- if .Features.asis }}
		<insert>
			<![CDATA[
			// {{Camel .Module.Name}}: bridge the ApiGear BindingLifecycleRegistry SPI
			// to ASIS's pre-destroy callback registry. Runs once when GameActivity
			// class is loaded, before any JNI subsystem binds, installing a
			// coordinator that forwards register/unregister calls into
			// UnrealSharedInstanceService. This is the only place the generated
			// code is coupled to ASIS; the SPI in apigear.android.lifecycle stays
			// host-agnostic and the bridge is emitted only when this consumer
			// opts in via the asis feature.
			static
			{
				apigear.android.lifecycle.BindingLifecycleRegistry.setCoordinator(
					new apigear.android.lifecycle.IBindingLifecycleCoordinator()
					{
						@Override
						public void registerCleanup(Runnable cleanup)
						{
							com.epicgames.asis.UnrealSharedInstanceService.addPreDestroyCallback(cleanup);
						}

						@Override
						public void unregisterCleanup(Runnable cleanup)
						{
							com.epicgames.asis.UnrealSharedInstanceService.removePreDestroyCallback(cleanup);
						}
					});
			}
			]]>
		</insert>
{{- end }}
	</gameActivityClassAdditions>


	<!-- optional additions to GameActivity onCreate in GameActivity.java -->
	<gameActivityOnCreateAdditions>
		<insert>
			<![CDATA[
		]]>
		</insert>
	</gameActivityOnCreateAdditions>


</root>