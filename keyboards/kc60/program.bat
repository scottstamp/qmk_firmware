@ECHO OFF
ping -n 5 127.0.0.1 > NUL 2>&1
dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash kc60_scott.hex
dfu-programmer atmega32u4 reset