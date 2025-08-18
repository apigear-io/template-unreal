<?xml version="1.0" encoding="utf-8"?>

<root xmlns:android="http://schemas.android.com/apk/res/android">
	<trace enable="true"/>
	<init>
		<log text="android {{.Module.Name}} init"/>
	</init>

	<androidManifestUpdates>
		<addPermission android:name="android.permission.READ_EXTERNAL_STORAGE"/>
		<addPermission android:name="android.permission.MANAGE_EXTERNAL_STORAGE"/>

		<!-- TODO add queries for client side to query each interface -->
	
		<addElements tag="application">
		<!-- TODO add services that should be exposed, for each interface -->
	</addElements>

	</androidManifestUpdates>

	<resourceCopies>
	{{- range .Module.Interfaces -}}
		<copyDir src="$S(PluginDir)/buildsystem" dst="$S(BuildDir)/gradle/buildsystem" />
		<!-- TODO copy all java necessary modules -->
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
	<!-- TODO inlude java modules dependencies -->
	
	</settingsGradleAdditions>

	<buildGradleAdditions>
	<!-- TODO add java modules dependencies -->
	<!-- TODO configure assembleDebug and assembleRelease tasks -->
	</buildGradleAdditions>


	<proguardAdditions>
	<!-- TODO add java classes -->
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