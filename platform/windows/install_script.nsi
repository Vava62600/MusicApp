OutFile "MusicAppInstaller.exe"
InstallDir "$PROGRAMFILES\MusicApp"
RequestExecutionLevel admin

Section "Install"
  SetOutPath $INSTDIR
  File "build\MusicApp.exe"
  File "resources\icons\musicapp.ico"
  Exec '"$INSTDIR\pulseaudio.exe" -D --exit-idle-time=-1' ; Start PulseAudio as a daemon
  CreateShortcut "$DESKTOP\MusicApp.lnk" "$INSTDIR\MusicApp.exe"
SectionEnd

Section "Uninstall"
  Delete "$INSTDIR\MusicApp.exe"
  Delete "$INSTDIR\pulseaudio.exe"
  RMDir "$INSTDIR"
  Delete "$DESKTOP\MusicApp.lnk"
SectionEnd
