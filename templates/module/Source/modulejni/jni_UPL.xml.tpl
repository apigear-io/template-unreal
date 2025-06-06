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
				<package android:name="{{ueJavaPckgName $moduleName $moduleName "service" }}" />
		</addElements>
		{{- end }}
		
		<addElements tag="application">
		
		{{- range .Module.Interfaces -}}
		<service
			android:name="{{ueJavaPckgName $moduleName $moduleName "service" }}.{{Camel .Name}}ServiceAdapter"
			android:enabled="true"
			android:exported="true">
		</service>
		{{- end }}

	</addElements>

	</androidManifestUpdates>

	<resourceCopies>
	{{- range .Module.Interfaces -}}
		<copyDir src="$S(PluginDir)/buildsystem" dst="$S(BuildDir)/gradle/buildsystem" />
		<copyDir src="$S(PluginDir)/{{ueJavaPath $moduleName $moduleName "service" }}" dst="$S(BuildDir)/JavaLibs/{{ueGetModuleName $moduleName "service" }}" />
		<copyDir src="$S(PluginDir)/{{ueJavaPath $moduleName $moduleName "api" }}" dst="$S(BuildDir)/JavaLibs/{{ueGetModuleName $moduleName "api" }}" />
		<copyDir src="$S(PluginDir)/{{ueJavaPath $moduleName $moduleName "unrealservice" }}" dst="$S(BuildDir)/src/" />
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
      include ':service'
    ]]>
		</insert>
	
	</settingsGradleAdditions>

	<buildGradleAdditions>
		<insert>
            <![CDATA[
                dependencies {
					{{- range .Module.Interfaces -}}
                    implementation project(':{{ueGetModuleName $moduleName "api" }}')
                    implementation project(':{{ueGetModuleName $moduleName "service" }}')
					{{- end }}
                }
            ]]>
        </insert>
		<insert>
			<![CDATA[
tasks.configureEach { task ->
	if (task.name == 'assembleDebug') {
		{{- range .Module.Interfaces -}}
		task.dependsOn ':{{ueGetModuleName $moduleName "api" }}:assembleDebug'
		task.dependsOn ':{{ueGetModuleName $moduleName "service" }}:assembleDebug'
		{{- end}}
	}
	if (task.name == 'assembleRelease') {
		{{- range .Module.Interfaces -}}
		task.dependsOn ':{{ueGetModuleName $moduleName "api" }}:assembleRelease'
		task.dependsOn ':{{ueGetModuleName $moduleName "service" }}:assembleRelease'
		{{- end}}
	}
}

]]>
		</insert>
	</buildGradleAdditions>


	<proguardAdditions>
		<insert>
		{{- range .Module.Interfaces -}}
			-keep class {{ueJavaPckgName $moduleName $moduleName "unrealservice" }}.Unreal{{Camel .Name}}Service {
			public *;
			}
			-keep class {{ueJavaPckgName $moduleName $moduleName "unrealservice" }}.Unreal{{Camel .Name}}ServiceStarter {
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