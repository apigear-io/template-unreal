
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

# Check for existing ApiGear plugin
ApiGearPluginTarget_path=$UEplugins_path/Marketplace/ApiGear
RestoreApiGearPlugin=0
if [ -d "$ApiGearPluginTarget_path" ]
then
	echo "Existing ApiGear plugin found at $ApiGearPluginTarget_path"
	mv $ApiGearPluginTarget_path "$UEplugins_path/../ApiGearBackUp" 1>&-
	if [ $? -ne 0 ]; then exit 1; fi;
	RestoreApiGearPlugin=1
fi

#
# function implementations
#

# build UE plugin
buildUEplugin()
{
	"$RunUAT_path" BuildPlugin -verbose -Rocket -Plugin=$1 -TargetPlatforms=Linux -StrictIncludes -Package=$2
	buildresult=$?
}

# Clean up ApiGear plugin installation
cleanup()
{
	if [ "$RestoreApiGearPlugin" == 1 ]
	then
		echo "Restoring old ApiGear plugin in UE installation"
		rm -rf "$ApiGearPluginTarget_path"
		mv "$UEplugins_path/../ApiGearBackUp" "$ApiGearPluginTarget_path" >nul
	else
		echo "Deleting temporary ApiGear plugin installation from UE"
		rm -rf "$ApiGearPluginTarget_path"
	fi
}


#
# main
#

# Build ApiGear plugin
buildUEplugin "$script_path/Plugins/ApiGear/apigear.uplugin" "$script_path/build/Plugins/ApiGear"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# copy ApiGear plugin to UE installation for use by other plugins
mkdir -p "$ApiGearPluginTarget_path" && cp -rf "$script_path/build/Plugins/ApiGear" "$ApiGearPluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing Testbed2 module
buildUEplugin "$script_path/Plugins/Testbed2/Testbed2.uplugin" "$script_path/build/Plugins/Testbed2"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbEnum module
buildUEplugin "$script_path/Plugins/TbEnum/TbEnum.uplugin" "$script_path/build/Plugins/TbEnum"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbSame1 module
buildUEplugin "$script_path/Plugins/TbSame1/TbSame1.uplugin" "$script_path/build/Plugins/TbSame1"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbSame2 module
buildUEplugin "$script_path/Plugins/TbSame2/TbSame2.uplugin" "$script_path/build/Plugins/TbSame2"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbSimple module
buildUEplugin "$script_path/Plugins/TbSimple/TbSimple.uplugin" "$script_path/build/Plugins/TbSimple"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing Testbed1 module
buildUEplugin "$script_path/Plugins/Testbed1/Testbed1.uplugin" "$script_path/build/Plugins/Testbed1"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;


cleanup
