
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
ApiGearTarget_path=$UEplugins_path/Marketplace/ApiGear
RestoreApiGearPlugins=0
if [ -d "$ApiGearTarget_path" ]
then
	echo "Existing ApiGear plugins found at $ApiGearTarget_path"
	mv $ApiGearTarget_path "$UEplugins_path/../ApiGearBackUp" 1>&-
	if [ $? -ne 0 ]; then exit 1; fi;
	RestoreApiGearPlugins=1
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

# Clean up ApiGear plugins installation
cleanup()
{
	if [ "$RestoreApiGearPlugins" == 1 ]
	then
		echo "Restoring old ApiGear plugins in UE installation"
		rm -rf "$ApiGearTarget_path"
		mv "$UEplugins_path/../ApiGearBackUp" "$ApiGearTarget_path" >/dev/null
	else
		echo "Deleting temporary ApiGear plugin installation from UE"
		rm -rf "$ApiGearTarget_path"
	fi

	# remove CustomTypes plugin from UE installation
	CustomTypesPluginTarget_path=$ApiGearTarget_path/CustomTypes
	rm -rf "$CustomTypesPluginTarget_path" 1>&-
	if [ $? -ne 0 ]; then exit 1; fi;

	# remove ExternTypes plugin from UE installation
	ExternTypesPluginTarget_path=$ApiGearTarget_path/ExternTypes
	rm -rf "$ExternTypesPluginTarget_path" 1>&-
	if [ $? -ne 0 ]; then exit 1; fi;

	# remove TbIfaceimport plugin from UE installation
	TbIfaceimportPluginTarget_path=$ApiGearTarget_path/TbIfaceimport
	rm -rf "$TbIfaceimportPluginTarget_path" 1>&-
	if [ $? -ne 0 ]; then exit 1; fi;
}


#
# main
#

# Build ApiGear plugin
buildUEplugin "$script_path/ApiGear/apigear.uplugin" "$script_path/build/ApiGear"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# copy ApiGear plugin to UE installation for use by other plugins
ApiGearPluginTarget_path=$ApiGearTarget_path/ApiGear
mkdir -p "$ApiGearPluginTarget_path" && cp -rf "$script_path/build/ApiGear" "$ApiGearPluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing Testbed2 module
buildUEplugin "$script_path/Testbed2/Testbed2.uplugin" "$script_path/build/Testbed2"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbEnum module
buildUEplugin "$script_path/TbEnum/TbEnum.uplugin" "$script_path/build/TbEnum"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbSame1 module
buildUEplugin "$script_path/TbSame1/TbSame1.uplugin" "$script_path/build/TbSame1"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbSame2 module
buildUEplugin "$script_path/TbSame2/TbSame2.uplugin" "$script_path/build/TbSame2"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbSimple module
buildUEplugin "$script_path/TbSimple/TbSimple.uplugin" "$script_path/build/TbSimple"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing Testbed1 module
buildUEplugin "$script_path/Testbed1/Testbed1.uplugin" "$script_path/build/Testbed1"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbNames module
buildUEplugin "$script_path/TbNames/TbNames.uplugin" "$script_path/build/TbNames"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing CustomTypes module
buildUEplugin "$script_path/CustomTypes/CustomTypes.uplugin" "$script_path/build/CustomTypes"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# copy CustomTypes plugin to UE installation for use by other plugins
CustomTypesPluginTarget_path=$ApiGearTarget_path/CustomTypes
mkdir -p "$CustomTypesPluginTarget_path" && cp -rf "$script_path/build/CustomTypes" "$CustomTypesPluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing ExternTypes module
buildUEplugin "$script_path/ExternTypes/ExternTypes.uplugin" "$script_path/build/ExternTypes"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# copy ExternTypes plugin to UE installation for use by other plugins
ExternTypesPluginTarget_path=$ApiGearTarget_path/ExternTypes
mkdir -p "$ExternTypesPluginTarget_path" && cp -rf "$script_path/build/ExternTypes" "$ExternTypesPluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing Counter module
buildUEplugin "$script_path/Counter/Counter.uplugin" "$script_path/build/Counter"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbIfaceimport module
buildUEplugin "$script_path/TbIfaceimport/TbIfaceimport.uplugin" "$script_path/build/TbIfaceimport"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;

# copy TbIfaceimport plugin to UE installation for use by other plugins
TbIfaceimportPluginTarget_path=$ApiGearTarget_path/TbIfaceimport
mkdir -p "$TbIfaceimportPluginTarget_path" && cp -rf "$script_path/build/TbIfaceimport" "$TbIfaceimportPluginTarget_path" 1>&-
if [ $? -ne 0 ]; then cleanup && exit 1; fi;

# Building and testing TbRefIfaces module
buildUEplugin "$script_path/TbRefIfaces/TbRefIfaces.uplugin" "$script_path/build/TbRefIfaces"
if [ $buildresult -ne 0 ]; then cleanup && exit 1; fi;


cleanup
