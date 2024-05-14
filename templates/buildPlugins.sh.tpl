
{{- $exports := getEmptyStringList}}
{{- range .System.Modules }}
{{- range .Imports }}
{{- $exports = appendList $exports .Name }}
{{- end }}
{{- end }}
{{- $exports = unique $exports}}
#! /bin/bash
set -x;
export script_path="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )";
echo Script is in $script_path

# Check for UAT
RunUAT_path=`type -P RunUAT.sh`
if [ -z "$RunUAT_path" ]
then
	echo RunUAT.sh needs to be in the PATH environment variable
	exit 1
else
	echo RunUAT.sh found at ${RunUAT_path:0:-10}
fi

# Retrive UE path and test for plugins folder
UE_path=${RunUAT_path:0:-27}
if [ -d "$UE_path" ]
then
	echo "UE installation found at $UE_path"
else
	echo "Was not able to find UE installation at $UE_path"
	exit 1
fi

UEplugins_path=$UE_path/Plugins
if [ -d "$UEplugins_path" ]
then
	echo "UE plugins found at $UEplugins_path"
else
	echo "Was not able to find UE plugins at $UEplugins_path"
	exit 1
fi

{{ if .Features.apigear -}}
# Check for existing ApiGear plugin
ApiGearTarget_path=$UEplugins_path/Marketplace/ApiGear
RestoreApiGearPlugins=0
if [ -d "$ApiGearTarget_path" ]
then
	echo "Existing ApiGear plugins found at $ApiGearTarget_path"
	mv $ApiGearTarget_path "$UEplugins_path/../ApiGearBackUp" 1>&-
	if [ $? -ne 0 ]; then exit 1; fi;
	RestoreApiGearPlugins=1
fi
{{- end }}

#
# function implementations
#

# build UE plugin
buildUEplugin()
{
	"$RunUAT_path" BuildPlugin -verbose -Rocket -Plugin=$1 -TargetPlatforms=Linux -StrictIncludes -Package=$2
	buildresult=$?
}

# Clean up ApiGear plugins installation
cleanup()
{
	if [ "$RestoreApiGearPlugins" == 1 ]
	then
		echo "Restoring old ApiGear plugins in UE installation"
		rm -rf "$ApiGearTarget_path"
		mv "$UEplugins_path/../ApiGearBackUp" "$ApiGearTarget_path" >nul
	else
		echo "Deleting temporary ApiGear plugin installation from UE"
		rm -rf "$ApiGearTarget_path"
	fi
}


#
# main
#

{{ if .Features.apigear -}}
# Build ApiGear plugin
buildUEplugin "$script_path/Plugins/ApiGear/apigear.uplugin" "$script_path/build/Plugins/ApiGear"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# copy ApiGear plugin to UE installation for use by other plugins
ApiGearPluginTarget_path=$ApiGearTarget_path/ApiGear
mkdir -p "$ApiGearPluginTarget_path" && cp -rf "$script_path/build/Plugins/ApiGear" "$ApiGearPluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;
{{- end }}
{{ range .System.Modules }}
# Building and testing {{Camel .Name}} module
buildUEplugin "$script_path/Plugins/{{Camel .Name}}/{{Camel .Name}}.uplugin" "$script_path/build/Plugins/{{Camel .Name}}"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

{{- if contains $exports .Name }}

# copy {{ Camel .Name}} plugin to UE installation for use by other plugins
{{Camel .Name}}PluginTarget_path=$ApiGearTarget_path/{{ Camel .Name}}
mkdir -p "${{Camel .Name}}PluginTarget_path" && cp -rf "$script_path/build/Plugins/{{ Camel .Name}}" "${{Camel .Name}}PluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;
{{- end }}
{{ end }}

cleanup
