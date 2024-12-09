
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

ProjectTarget_path=$script_path/TP_Blank
UEtemplate_path=${UE_path:0:-7}/Templates/TP_Blank
if [ -d "$UEtemplate_path" ]
then
	echo UE blank project template found at $UEtemplate_path
else
	echo Was not able to find UE blank project template $UEtemplate_path
	exit 1
fi

mkdir -p $ProjectTarget_path
if [ $? -ne 0 ]; then exit 1; fi;

echo Copy blank project from $UEtemplate_path to $script_path
cp -rf "$UEtemplate_path" "$script_path/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;
#
# function implementations
#

# build and test plugins
buildTestPlugins()
{
	# do not use -unattended as this seems to cause some issue when exiting the editor after test run
	"$RunUAT_path" BuildCookRun -installed -project="$1" -run -RunAutomationTest="$3" -nullrhi -NoP4 -build -verbose -nodebuginfo -log="$2/RunTests.log" -addcmdline="-ReportExportPath=$2 " -Configuration=Test -notools -utf8output
	buildresult=$?
}

#
# main
#

{{ if .Features.apigear -}}
# copy ApiGear plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/ApiGear" &&  cp -rf "$script_path/Plugins/ApiGear" "$ProjectTarget_path/Plugins/ApiGear" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;
{{- end }}
{{ range .System.Modules }}

# copy {{ Camel .Name}} plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/{{Camel .Name}}" && cp -rf "$script_path/Plugins/{{Camel .Name}}" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;
{{ end }}

buildTestPlugins "$ProjectTarget_path/TP_Blank.uproject" "$script_path" ".Impl.{{ if .Features.olink -}}+.OLink.{{ end }}{{ if .Features.msgbus_tests -}}+.MsgBus.{{ end }}"
if [ $buildresult -ne 0 ]; then exit 1; fi;
