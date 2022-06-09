#  iex ((New-Object System.Net.WebClient).DownloadString('https://raw.githubusercontent.com/mod-cpp/pacman/main/dev/windows.ps1'))

# Install Visual Studio Community 2022
winget install -e --id Microsoft.VisualStudio.2022.Community

# Install or update Scoop
$ScoopMissing = $false
try {scoop --version} catch {$ScoopMissing = $true}
if ($ScoopMissing) {
    Invoke-Expression (New-Object System.Net.WebClient).DownloadString('https://get.scoop.sh')
} else {
    scoop update
}

# Add Scoop buckets
scoop bucket add extras

# Install PacMan dependencies
scoop install vscode git ninja cmake
