@echo off

REM VS 2017 developer cmd
call  "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\VsDevCmd.bat"

devenv WSL_Start_X_App.sln /Build "Release|x64" /Project WSL_START_X_APP && iscc inno_installer_setup.iss
