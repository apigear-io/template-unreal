
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

ProjectTarget_path=$script_path/build/TP_Blank
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
cp -rf "$UEtemplate_path" "$script_path/build" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;
#
# function implementations
#

# Run tests with optional sanitizer
# Args: project tests sanitizer log_file report_path
buildTestPlugins()
{
	local project=$1
	local tests=$2
	local sanitizer=$3
	local log_file=$4
	local report_path=$5

	local SANITIZER_FLAGS=""

	echo "=== Running Tests ==="
	case "$sanitizer" in
		asan)
			echo "Enabled: ASan + UBSan"
			SANITIZER_FLAGS="-EnableASan -EnableUndefinedBehaviorSanitizer"
			;;
		tsan)
			echo "Enabled: TSan"
			SANITIZER_FLAGS="-EnableThreadSanitizer"
			;;
	esac

	# do not use -unattended as this seems to cause some issue when exiting the editor after test run
	"$RunUAT_path" BuildCookRun -installed $SANITIZER_FLAGS -project="$project" -run -RunAutomationTest="$tests" -nullrhi -NoP4 -build -verbose -WarningsAsErrors -nodebuginfo -NoEditorTelemetry -log="$log_file" -addcmdline="-ReportExportPath=$report_path" -Configuration=Test -notools -utf8output
	return $?
}

#
# main
#

# copy ApiGear plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/ApiGear" &&  cp -rf "$script_path/ApiGear" "$ProjectTarget_path/Plugins/ApiGear" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy Testbed2 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/Testbed2" && cp -rf "$script_path/Testbed2" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbEnum plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbEnum" && cp -rf "$script_path/TbEnum" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbSame1 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbSame1" && cp -rf "$script_path/TbSame1" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbSame2 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbSame2" && cp -rf "$script_path/TbSame2" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbSimple plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbSimple" && cp -rf "$script_path/TbSimple" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy Testbed1 plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/Testbed1" && cp -rf "$script_path/Testbed1" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbNames plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbNames" && cp -rf "$script_path/TbNames" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy CustomTypes plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/CustomTypes" && cp -rf "$script_path/CustomTypes" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy ExternTypes plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/ExternTypes" && cp -rf "$script_path/ExternTypes" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy Counter plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/Counter" && cp -rf "$script_path/Counter" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbIfaceimport plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbIfaceimport" && cp -rf "$script_path/TbIfaceimport" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# copy TbRefIfaces plugin to blank project for build and functional testing
mkdir -p "$ProjectTarget_path/Plugins/TbRefIfaces" && cp -rf "$script_path/TbRefIfaces" "$ProjectTarget_path/Plugins/" 1>&-
if [ $? -ne 0 ]; then exit 1; fi;


# Run primary tests (with ASan if enabled)
SANITIZER=""
if [ ! -z "$ENABLE_ASAN" ]; then
	SANITIZER="asan"
fi

buildTestPlugins "$ProjectTarget_path/TP_Blank.uproject" \
	".Impl.+.OLink.+.MsgBus." \
	"$SANITIZER" \
	"$script_path/RunTests.log" \
	"$script_path"

if [ $? -ne 0 ]; then
	echo "ERROR: Tests failed"
	exit 1
fi

# Check test results
if [ ! -f "$script_path/index.json" ]; then
	echo "WARNING: no test results found"
else
	grep '"failed": 0' "$script_path/index.json" > /dev/null
	if [ $? -ne 0 ]; then
		echo "ERROR: Tests failed (check index.json)"
		exit 1
	fi
fi

# TSan tests (opt-in with ENABLE_TSAN=1)
# Usage: ENABLE_TSAN=1 ./buildTestPlugins.sh
if [ ! -z "$ENABLE_TSAN" ]; then
	buildTestPlugins "$ProjectTarget_path/TP_Blank.uproject" \
		".Impl.+.OLink.+.MsgBus." \
		"tsan" \
		"$script_path/RunTests-TSan.log" \
		"$script_path/tsan-results"

	if [ $? -ne 0 ]; then
		echo "ERROR: TSan tests failed (threading issues detected)"
		exit 1
	fi

	# Check TSan test results
	if [ -f "$script_path/tsan-results/index.json" ]; then
		grep '"failed": 0' "$script_path/tsan-results/index.json" > /dev/null
		if [ $? -ne 0 ]; then
			echo "ERROR: TSan tests failed (check tsan-results/index.json)"
			exit 1
		fi
	fi
fi
