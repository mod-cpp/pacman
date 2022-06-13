#  iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/windows_winget.ps1'))

winget install -e --id Git.Git
winget install Microsoft.VisualStudio.2022.Community --silent --override "--wait --quiet --add ProductLang En-us --add Microsoft.VisualStudio.Workload.NativeDesktop --includeRecommended"
winget install -e --id Kitware.CMake
winget install -e --id Microsoft.VisualStudioCode

Write-Host -Foreground yellow "Winget does not have ninja at this time"
