# brightness-fix
Restores brightness value at login for Xubuntu 20.04.4 LTS

[ acpi_backlight=video ] need to be added to the kernel options in GRUB on some machines.
Edit [ /etc/systemd/system/brightness-fix.service ] and run [ $sudo systemctl daemon-reload ] to change paths and ratio if necessary.

Brightness_fix.pro and main.cpp is a simple console C++ Qt project.
brightness-fix.dbp is Debreate project configured for the current machine (see https://antumdeluge.github.io/debreate-web).
