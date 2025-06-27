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
		{{- range .Module.Interfaces }}
		<addElements tag="queries">
				<package android:name="{{ueJavaPckgName $moduleName "android" "service" }}" />
		</addElements>
		{{- end }}
		
		<addElements tag="application">
		
		{{- range .Module.Interfaces -}}
		<service
			android:name="{{ueJavaPckgName $moduleName "android" "service" }}.{{Camel .Name}}ServiceAdapter"
			android:enabled="true"
			android:exported="true">
		</service>
		{{- end }}

	</addElements>

	</androidManifestUpdates>

	<resourceCopies>
	{{- range .Module.Interfaces -}}
		<copyDir src="$S(PluginDir)/buildsystem" dst="$S(BuildDir)/gradle/buildsystem" />
		<copyDir src="$S(PluginDir)/{{ueJavaPath $moduleName "android" "service" }}" dst="$S(BuildDir)/JavaLibs/{{ueJavaPath $moduleName "android" "service" }}" />
		<copyDir src="$S(PluginDir)/{{ueJavaPath $moduleName "api" "" }}" dst="$S(BuildDir)/JavaLibs/{{ueJavaPath $moduleName "api" "" }}" />
		{{- $unreal_service_name:= printf "%sservice" $moduleName }}
		<copyDir src="$S(PluginDir)/{{ueJavaPath $moduleName "unreal" $unreal_service_name }}" dst="$S(BuildDir)/src/$unreal_service_name" />
	{{- end }}
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
      include ':api'
      include ':android:service'
    ]]>
		</insert>
	
	</settingsGradleAdditions>

	<buildGradleAdditions>
		<insert>
            <![CDATA[
                dependencies {
					{{- range .Module.Interfaces }}
                    implementation project(':api')
                    implementation project(':android:service')
					{{- end }}
                }
            ]]>
        </insert>
		<insert>
			<![CDATA[
tasks.configureEach { task ->
	if (task.name == 'assembleDebug') {
		{{- range .Module.Interfaces }}
		task.dependsOn ':api:assembleDebug'
		task.dependsOn ':android:service:assembleDebug'
		{{- end}}
	}
	if (task.name == 'assembleRelease') {
		{{- range .Module.Interfaces }}
		task.dependsOn ':api:assembleRelease'
		task.dependsOn ':android:service:assembleRelease'
		{{- end}}
	}
}

]]>
		</insert>
	</buildGradleAdditions>


	<proguardAdditions>
		<insert>
		{{- range .Module.Interfaces -}}
			{{- $unreal_service_name:= printf "%sservice" $moduleName }}
			-keep class {{ueJavaPckgName $moduleName "unreal" $unreal_service_name }}.Unreal{{Camel .Name}}Service {
			public *;
			}
			-keep class {{ueJavaPckgName $moduleName "unreal" $unreal_service_name}}.Unreal{{Camel .Name}}ServiceStarter {
			public *;
			}
		{{- end }}
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