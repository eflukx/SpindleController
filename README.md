# CNC Spindle Controller

Hardware and firmware for (PID) controlling universal AC motors (e.g. CNC spindles)

Device to precicely control the spindle speed of a CNC machine. I'm using a  Kress 530FM 530Watt spindle, but Anything upto 1000 Watt should probably be no problem. The design is based on https://sites.google.com/site/klaasdc/cnc-router/spindle-controller (thanks for finding a spot to mount the optical pickup Klaas!).

I've added a nice -mostly single sided- PCB and bases the design on the ubiquitous ATMega328p AVR platform. The PCB is designed to be easily built, using a mostly single sided design and through hole parts. Please be aware that the board carries lethal 230VAC mains supply. Proceed at your own risk! DisclaimerL: I take no liability whatsoever, you're on your own. Damage to spindle, fried PC, cats on fire, all your problem.!

The spindle speed is controlled by means of an optical pickup (rotational pulse) and a PID loop. A break-off mini-board with the TCRT5000 optical pickup to fit inside the Kress 530FM spindle is included in the PCB design.


## Power supply
The board includes a 6 volt mains transformer which supplies the logic power. The power supply may be omitted when the circuit is powered from the headers. Probably using the 5V out of a USB Serial (TTL!) cable will suffice to power the circuit. 

To minimize dissipation, I've chosen a 6V transformer in conjunction with a low drop linear (LDO) regulator. Alternatively you can use a standard 7805, but a slightly higher input voltage is needed. A 8-9 volt transformer will do, the heat dissipation from the 7805 will be a bit higher. Probably you'll still be ok with the ground plane as heatsink, otherwise place a small heatsink.

## Planned for 1st release
- PID controlled speed via RPM pulse.
- Manual speed control via knob (rotary encoder)
- Old school LED display
- Computer control via I2C
- Computer control via Async Serial (UART)
- Simple power control without RPM pulse (without optical pickup)


## Not in the package, for a next version maybe?
- Different display (128x64 graphic?)
- (over) Current monitoring
- Fuse 
- Coffee maker
- Dancing partygirl


This was created using KiCAD nightly (april 2017), possibly you cannot load the files in the stable version
