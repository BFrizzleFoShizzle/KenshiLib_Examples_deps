@echo off
IF NOT EXIST boost_1_60_0/boost.zip (
	echo Boost .zip is missing.
	echo Please run "git lfs pull" to download
	exit
)
IF NOT EXIST boost_1_60_0/boost (
	echo Extracting boost
	tar -xf boost_1_60_0/boost.zip --directory boost_1_60_0/
)
powershell Scripts/setup_environment_vars.ps1