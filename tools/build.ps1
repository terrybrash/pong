param(
    [ValidateSet('build', 'run')]
    [string] $Mode = 'build'
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$repo_dir = Split-Path -Parent $PSScriptRoot
$source_path = Join-Path $repo_dir 'src\pong.asm'
$target_dir = Join-Path $repo_dir 'target'
$object_path = Join-Path $target_dir 'pong.obj'
$exe_path = Join-Path $target_dir 'pong.exe'
$link_libs = 'kernel32.lib', 'user32.lib', 'gdi32.lib', 'dwmapi.lib'

$vswhere_path = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (-not (Test-Path $vswhere_path)) { throw "vswhere.exe not found: install Visual Studio with the C++ build tools" }
$vs_dir = & $vswhere_path -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (-not $vs_dir) { throw "no Visual Studio with the C++ x64 build tools" }
$vc_tools_version = (Get-Content (Join-Path $vs_dir 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt')).Trim()
$vc_bin_dir = Join-Path $vs_dir "VC\Tools\MSVC\$vc_tools_version\bin\Hostx64\x64"
$ml64_path = Join-Path $vc_bin_dir 'ml64.exe'
$link_path = Join-Path $vc_bin_dir 'link.exe'

$sdk_root_dir = (Get-ItemProperty 'HKLM:\SOFTWARE\Microsoft\Windows Kits\Installed Roots').KitsRoot10
$sdk_lib_dir = Get-ChildItem (Join-Path $sdk_root_dir 'Lib') -Directory |
    Where-Object { Test-Path (Join-Path $_.FullName 'um\x64\kernel32.lib') } |
    Sort-Object { [version] $_.Name } -Descending |
    Select-Object -First 1 |
    ForEach-Object { Join-Path $_.FullName 'um\x64' }
if (-not $sdk_lib_dir) { throw "no Windows 10 SDK with x64 libs in $sdk_root_dir" }

New-Item -ItemType Directory -Force $target_dir | Out-Null

& $ml64_path /nologo /c /Zi /W3 /WX "/Fo$object_path" $source_path
if ($LASTEXITCODE -ne 0) { throw "ml64 failed with exit code $LASTEXITCODE" }

& $link_path /nologo /subsystem:windows /entry:main_entry /nodefaultlib /debug /incremental:no "/libpath:$sdk_lib_dir" "/out:$exe_path" $object_path @link_libs
if ($LASTEXITCODE -ne 0) { throw "link failed with exit code $LASTEXITCODE" }

if ($Mode -eq 'run') { & $exe_path }
