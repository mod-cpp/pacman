#  iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/windows.ps1'))

# Install or update Choco
$ChocoMissing = $false
try { choco --version } catch { $ChocoMissing = $true }
if ($ChocoMissing) {
    Set-ExecutionPolicy Bypass -Scope Process -Force;
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072;
    iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
}

choco install -y git

$env:ChocolateyInstall = Convert-Path "$((Get-Command choco).Path)\..\.."
Import-Module "$env:ChocolateyInstall\helpers\chocolateyProfile.psm1"

choco install -y visualstudio2022community
Update-SessionEnvironment
choco install -y visualstudio2022-workload-nativedesktop

choco install -y cmake.install --installargs 'ADD_CMAKE_TO_PATH=System'
choco install -y ninja
choco install -y vscode
