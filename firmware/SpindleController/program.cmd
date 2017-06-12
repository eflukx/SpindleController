@echo off
setlocal
pushd .
%~d0 && cd %~dp0 

set hex_image=Debug\SpindleController.hex

:: internal RC-osc
:: set lfuse=0xe2

:: Full swing ext XTAL OSC
set lfuse=0xc6
   
:: Save EEPROM
set hfuse=0xd1

set device=m328p 

set avrdude="c:\Program Files (x86)\AVRDude\avrdude.exe"
set params=-c usbasp -p %device%
set fuse_params= -U lfuse:w:%lfuse%:m -U hfuse:w:%hfuse%:m
set avrdude_cmd=%avrdude% %params%

if "%1"=="fuses" (
	%avrdude_cmd% -B 3 %fuse_params%
	goto exit
)

if "%1"=="initial" (
  %avrdude_cmd% -B 3 %fuse_params%
  %avrdude_cmd% -U flash:w:%hex_image%
	goto exit
)

%avrdude_cmd% -V -U flash:w:%hex_image%

:exit
popd