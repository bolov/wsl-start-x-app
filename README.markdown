 # WSL Start X App

Small utility to start a X app from Windows Subsystem for Linux without showing the console window

## Requirements

* WSL installed. Currently only Ubuntu is supported
* X Server up and running.  Correct `DISPLAY` variable etc. Any program you want to start with this utility must already be working.
* All the environment variable needed to run the X app must be set from `bash_profile` or must be provided in the command

## Examples

```powershell
wsl-start-x-app.exe gvim
wsl-start-x-app.exe gnome-terminal
wsl-start-x-app.exe gnome-terminal --working-directory=~
wsl-start-x-app.exe DISPLAY=:0 gnome-terminal
```

## How it works

Basically it just runs without a console or a window the following command:

```powershell
ubuntu run bash -lc \"<your_command>\"
```

where `<your_command>` is the entire argument line you provide to `wsl-start-x-app.exe`

If all goes well, the X application will start and create its own GUI window. This utility and all the intermediary processes started end.

### Limitations

Because how windows deals with console/GUI applications the program won't output anything , even if it's run from console

**Be careful** an application that doesn't create a GUI window will run silently and hidden.