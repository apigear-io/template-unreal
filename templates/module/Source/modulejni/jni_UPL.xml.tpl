<?xml version="1.0" encoding="utf-8"?>

<root xmlns:android="http://schemas.android.com/apk/res/android">
	<trace enable="true"/>
	<init>
		<log text="android {{.Module.Name}} init"/>
	</init>

	<androidManifestUpdates>
		<addPermission android:name="android.permission.READ_EXTERNAL_STORAGE"/>
		<addPermission android:name="android.permission.MANAGE_EXTERNAL_STORAGE"/>

		{{- $moduleName := .Module.Name }}
		{{- $service_package_name := printf "%s_android_service" (camel $moduleName) }} 
		<addPermission android:name="{{$moduleName}}.{{$service_package_name}}.PERMISSION_BIND"/>
		<addElements tag="queries">
				<package android:name="{{$moduleName}}.{{$service_package_name}}" />
		</addElements>

		<addElements tag="application">
		
		{{- range .Module.Interfaces -}}
		<service
			{{- $service_package_name := printf "%s_android_service" (camel $moduleName) }} 
			android:name="{{$moduleName}}.{{$service_package_name}}.{{Camel .Name}}ServiceAdapter"
			android:enabled="true"
			android:exported="true">
		</service>
		{{- end }}

	</addElements>

	</androidManifestUpdates>

	<resourceCopies>
		<copyDir src="$S(PluginDir)/buildsystem" dst="$S(BuildDir)/gradle/buildsystem" />
		{{- $service_package_name := printf "%s_android_service" (camel $moduleName) }}
		{{- $impl_package_name := printf "%s_impl" (camel $moduleName) }}
		{{- $messenger_package_name := printf "%s_android_messenger" (camel $moduleName) }}
		{{- $api_package_name := printf "%s_api" (camel $moduleName) }}
		<copyDir src="$S(PluginDir)/android/{{camel $moduleName}}/{{$service_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$service_package_name}}" />
		<copyDir src="$S(PluginDir)/android/{{camel $moduleName}}/{{$api_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$api_package_name}}" />
		<copyDir src="$S(PluginDir)/android/{{camel $moduleName}}/{{$messenger_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$messenger_package_name}}" />
		<copyDir src="$S(PluginDir)/android/{{camel $moduleName}}/{{$impl_package_name}}" dst="$S(BuildDir)/JavaLibs/{{$impl_package_name}}" />
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
		task.dependsOn ':{{camel $moduleName}}_android_messenger:assembleDebug'
	}
	if (task.name == 'assembleRelease') {
		task.dependsOn ':{{camel $moduleName}}_api:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_impl:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_android_service:assembleRelease'
		task.dependsOn ':{{camel $moduleName}}_android_messenger:assembleRelease'
	}
}

]]>
		</insert>
	</buildGradleAdditions>


	<proguardAdditions>
		<insert>
		</insert>
	</proguardAdditions>



	<!-- optional additions to the GameActivity class in GameActivity.java -->
	<gameActivityClassAdditions>
	</gameActivityClassAdditions>


	<!-- optional additions to GameActivity onCreate in GameActivity.java -->
	<gameActivityOnCreateAdditions>
		<insert>
			<![CDATA[
		]]>
		</insert>
	</gameActivityOnCreateAdditions>


</root>