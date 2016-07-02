#!/bin/bash
sleep 5
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash kc60_scott.hex
sudo dfu-programmer atmega32u4 reset
