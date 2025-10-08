# taken from https://github.com/lukegackle/PowerShell-Self-Elevate-Keeping-Current-Directory/blob/master/Self%20Elevate%20Keeping%20Directory.ps1

Param(
    [string]$Loc
)

if (!([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole(
        [Security.Principal.WindowsBuiltInRole] 'Administrator')
)
{
    Write-Host "Not elevated, restarting..."
    $Loc = (Get-Location)

    $Arguments =  @(
        '-NoProfile',
        '-ExecutionPolicy Bypass',
        '-File',
        "`"$($MyInvocation.MyCommand.Path)`"",
        "\`"$Loc\`""
    )
    Start-Process -FilePath PowerShell.exe -Verb RunAs -ArgumentList $Arguments
    Break
}
else
{
    Write-Host "Already elevated..."
}
if($Loc.Length -gt 1){
#Set-Location $($Loc.Substring(1,$Loc.Length-2)).Trim()
$Loc = $Loc.Trim('"')
Set-Location $Loc
}

#Your Script Here...
'updating environment variables'
Write-Output $Loc
setx KENSHILIB_DIR $(Join-Path -Path $Loc -ChildPath "kenshilib").Trim() #| Out-Null
Write-Output "KENSHILIB_DIR $([Environment]::GetEnvironmentVariable("KENSHILIB_DIR", "User"))"

setx KENSHILIB_DEPS_DIR $Loc #| Out-Null
Write-Output "KENSHILIB_DEPS_DIR $([Environment]::GetEnvironmentVariable("KENSHILIB_DEPS_DIR", "User"))"

setx BOOST_INCLUDE_PATH $(Join-Path -Path $Loc -ChildPath "boost_1_60_0") #| Out-Null
Write-Output "BOOST_INCLUDE_PATH $([Environment]::GetEnvironmentVariable("BOOST_INCLUDE_PATH", "User"))"
'press any key to exit'
[Console]::ReadKey() | Out-Null
exit