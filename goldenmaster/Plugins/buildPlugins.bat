
@Echo off
SET script_path=%~dp0
echo Script is in %script_path:~0,-1%

@REM Check for UAT
setlocal enableDelayedExpansion
for %%i in (RunUAT.bat) do (
    set "RunUAT_path=%%~$PATH:i" 
)
if not defined RunUAT_path (
	echo RunUAT.bat needs to be in the PATH environment variable
	exit /b 1
)
echo RunUAT.bat found at %RunUAT_path:~0,-11%

@REM Retrive UE path and test for plugins folder
set UE_path=%RunUAT_path:~0,-28%
if exist "%UE_path%\" (
	echo UE installation found at %UE_path%
) else (
	echo Was not able to find UE installation at %UE_path%
	exit /b 1
)
set UEplugins_path=%UE_path%\Plugins
if exist "%UEplugins_path%\" (
	echo UE plugins found at %UEplugins_path%
) else (
	echo Was not able to find UE plugins at %UEplugins_path%
	exit /b 1
)

@REM Check for existing ApiGear plugins
set ApiGearTarget_path=%UEplugins_path%\Marketplace\ApiGear
set RestoreApiGearPlugins=0
if exist "%ApiGearTarget_path%\" (
	echo Existing ApiGear plugins found at %ApiGearTarget_path%
	move "%ApiGearTarget_path%" "%UEplugins_path%\..\ApiGearBackUp" >nul
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
	set "RestoreApiGearPlugins=1"
)

@REM Build ApiGear plugin
call :buildUEplugin "%script_path%\ApiGear\ApiGear.uplugin" , "%script_path%build\ApiGear"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM copy ApiGear plugin to UE installation for use by other plugins
set ApiGearPluginTarget_path=%ApiGearTarget_path%\ApiGear
xcopy /E /Y "%script_path%build\ApiGear" "%ApiGearPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Building and testing Testbed2 module
call :buildUEplugin "%script_path%\Testbed2\Testbed2.uplugin" , "%script_path%build\Testbed2"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbEnum module
call :buildUEplugin "%script_path%\TbEnum\TbEnum.uplugin" , "%script_path%build\TbEnum"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbSame1 module
call :buildUEplugin "%script_path%\TbSame1\TbSame1.uplugin" , "%script_path%build\TbSame1"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbSame2 module
call :buildUEplugin "%script_path%\TbSame2\TbSame2.uplugin" , "%script_path%build\TbSame2"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbSimple module
call :buildUEplugin "%script_path%\TbSimple\TbSimple.uplugin" , "%script_path%build\TbSimple"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing Testbed1 module
call :buildUEplugin "%script_path%\Testbed1\Testbed1.uplugin" , "%script_path%build\Testbed1"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbNames module
call :buildUEplugin "%script_path%\TbNames\TbNames.uplugin" , "%script_path%build\TbNames"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing CustomTypes module
call :buildUEplugin "%script_path%\CustomTypes\CustomTypes.uplugin" , "%script_path%build\CustomTypes"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM copy CustomTypes plugin to UE installation for use by other plugins
set CustomTypesPluginTarget_path=%ApiGearTarget_path%\CustomTypes
xcopy /E /Y "%script_path%build\CustomTypes" "%CustomTypesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Building and testing ExternTypes module
call :buildUEplugin "%script_path%\ExternTypes\ExternTypes.uplugin" , "%script_path%build\ExternTypes"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM copy ExternTypes plugin to UE installation for use by other plugins
set ExternTypesPluginTarget_path=%ApiGearTarget_path%\ExternTypes
xcopy /E /Y "%script_path%build\ExternTypes" "%ExternTypesPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Building and testing Counter module
call :buildUEplugin "%script_path%\Counter\Counter.uplugin" , "%script_path%build\Counter"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM Building and testing TbIfaceimport module
call :buildUEplugin "%script_path%\TbIfaceimport\TbIfaceimport.uplugin" , "%script_path%build\TbIfaceimport"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!

@REM copy TbIfaceimport plugin to UE installation for use by other plugins
set TbIfaceimportPluginTarget_path=%ApiGearTarget_path%\TbIfaceimport
xcopy /E /Y "%script_path%build\TbIfaceimport" "%TbIfaceimportPluginTarget_path%\"  >nul
if %ERRORLEVEL% GEQ 1 call :cleanup %ERRORLEVEL%
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM Building and testing TbRefIfaces module
call :buildUEplugin "%script_path%\TbRefIfaces\TbRefIfaces.uplugin" , "%script_path%build\TbRefIfaces"
if !buildresult! GEQ 1 call :cleanup !buildresult!
if !buildresult! GEQ 1 exit /b !buildresult!


call :cleanup 0
exit /b 0

@REM function implementations

@REM build UE plugin
:buildUEplugin
(
	"%RunUAT_path%" BuildPlugin -verbose -Rocket -Plugin=%1 -TargetPlatforms=Win64 -StrictIncludes -Package=%2
	set buildresult=!ERRORLEVEL!
)
exit /b %ERRORLEVEL%

@REM Clean up ApiGear plugin installation
:cleanup
if %RestoreApiGearPlugins% equ 1 (
	echo Restoring old ApiGear plugins in UE installation
	@RD /S /Q "%ApiGearTarget_path%"
	move "%UEplugins_path%\..\ApiGearBackUp" "%ApiGearTarget_path%" >nul
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
) else (
	echo Deleting temporary ApiGear plugin installation from UE
	@RD /S /Q "%ApiGearTarget_path%"
	if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
)

@REM remove CustomTypes plugin from UE installation
set CustomTypesPluginTarget_path=%ApiGearTarget_path%\CustomTypes
@RD /S /Q "%CustomTypesPluginTarget_path%\"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM remove ExternTypes plugin from UE installation
set ExternTypesPluginTarget_path=%ApiGearTarget_path%\ExternTypes
@RD /S /Q "%ExternTypesPluginTarget_path%\"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%

@REM remove TbIfaceimport plugin from UE installation
set TbIfaceimportPluginTarget_path=%ApiGearTarget_path%\TbIfaceimport
@RD /S /Q "%TbIfaceimportPluginTarget_path%\"
if %ERRORLEVEL% GEQ 1 exit /b %ERRORLEVEL%
exit /b %~1
