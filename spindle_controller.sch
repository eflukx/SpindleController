EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:iotta_wsn_rev2
LIBS:spindle_controller-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 8x7SEG DISP1
U 1 1 58F0B6BB
P 3900 6850
F 0 "DISP1" H 3925 7465 50  0000 C CNN
F 1 "8x7SEG" H 3925 7374 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x05_Pitch2.54mm" H 3750 6100 50  0001 C CNN
F 3 "" H 3750 6100 50  0001 C CNN
	1    3900 6850
	1    0    0    -1  
$EndComp
$Comp
L ATMEGA328P-PU U2
U 1 1 58F0A167
P 9300 2200
F 0 "U2" H 9350 3567 50  0000 C CNN
F 1 "ATMEGA328P-PU" H 9350 3476 50  0000 C CNN
F 2 "Housings_DIP:DIP-28_W7.62mm" H 9300 2200 50  0001 C CIN
F 3 "" H 9300 2200 50  0001 C CNN
	1    9300 2200
	-1   0    0    -1  
$EndComp
$Comp
L MOC3020M U4
U 1 1 58F0A616
P 4350 4900
F 0 "U4" H 4350 5225 50  0000 C CNN
F 1 "MOC3020M" H 4350 5134 50  0000 C CNN
F 2 "Housings_DIP:DIP-6_W7.62mm" H 4150 4700 50  0001 L CIN
F 3 "" H 4325 4900 50  0001 L CNN
	1    4350 4900
	-1   0    0    -1  
$EndComp
$Comp
L Q_TRIAC_A1A2G D7
U 1 1 58F0AE6B
P 2700 5250
F 0 "D7" H 2828 5296 50  0000 L CNN
F 1 "BT138" H 2828 5205 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" V 2775 5275 50  0001 C CNN
F 3 "" V 2700 5250 50  0001 C CNN
	1    2700 5250
	-1   0    0    -1  
$EndComp
$Comp
L PC817 U3
U 1 1 58F0AFEA
P 5350 3250
F 0 "U3" H 5350 3575 50  0000 C CNN
F 1 "PC817" H 5350 3484 50  0000 C CNN
F 2 "Housings_DIP:DIP-4_W7.62mm" H 5150 3050 50  0001 L CIN
F 3 "" H 5350 3250 50  0001 L CNN
	1    5350 3250
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 58F0B0F2
P 1750 3300
F 0 "R3" V 1543 3300 50  0000 C CNN
F 1 "120k" V 1634 3300 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1680 3300 50  0001 C CNN
F 3 "" H 1750 3300 50  0001 C CNN
	1    1750 3300
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 58F0B151
P 2250 3300
F 0 "R4" V 2043 3300 50  0000 C CNN
F 1 "220k" V 2134 3300 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2180 3300 50  0001 C CNN
F 3 "" H 2250 3300 50  0001 C CNN
	1    2250 3300
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 58F0B1BC
P 1750 3700
F 0 "R6" V 1543 3700 50  0000 C CNN
F 1 "120k" V 1634 3700 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1680 3700 50  0001 C CNN
F 3 "" H 1750 3700 50  0001 C CNN
	1    1750 3700
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58F0B1EC
P 2250 3700
F 0 "R7" V 2043 3700 50  0000 C CNN
F 1 "220k" V 2134 3700 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 2180 3700 50  0001 C CNN
F 3 "" H 2250 3700 50  0001 C CNN
	1    2250 3700
	0    1    1    0   
$EndComp
$Comp
L D D3
U 1 1 58F0B25B
P 3050 3300
F 0 "D3" H 3050 3084 50  0000 C CNN
F 1 "1N4841" H 3050 3175 50  0000 C CNN
F 2 "w_pth_diodes:diode_do35" H 3050 3300 50  0001 C CNN
F 3 "" H 3050 3300 50  0001 C CNN
	1    3050 3300
	1    0    0    -1  
$EndComp
$Comp
L D D4
U 1 1 58F0B327
P 3050 3700
F 0 "D4" H 3050 3916 50  0000 C CNN
F 1 "1N4841" H 3050 3825 50  0000 C CNN
F 2 "w_pth_diodes:diode_do35" H 3050 3700 50  0001 C CNN
F 3 "" H 3050 3700 50  0001 C CNN
	1    3050 3700
	-1   0    0    1   
$EndComp
$Comp
L D D6
U 1 1 58F0B35F
P 3050 4000
F 0 "D6" H 3050 4216 50  0000 C CNN
F 1 "1N4841" H 3050 4125 50  0000 C CNN
F 2 "w_pth_diodes:diode_do35" H 3050 4000 50  0001 C CNN
F 3 "" H 3050 4000 50  0001 C CNN
	1    3050 4000
	1    0    0    -1  
$EndComp
$Comp
L D D2
U 1 1 58F0B393
P 3050 3000
F 0 "D2" H 3050 2784 50  0000 C CNN
F 1 "1N4841" H 3050 2875 50  0000 C CNN
F 2 "w_pth_diodes:diode_do35" H 3050 3000 50  0001 C CNN
F 3 "" H 3050 3000 50  0001 C CNN
	1    3050 3000
	-1   0    0    1   
$EndComp
$Comp
L R R5
U 1 1 58F0B508
P 3850 3500
F 0 "R5" H 3780 3454 50  0000 R CNN
F 1 "33k" H 3780 3545 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3780 3500 50  0001 C CNN
F 3 "" H 3850 3500 50  0001 C CNN
	1    3850 3500
	-1   0    0    1   
$EndComp
$Comp
L C C11
U 1 1 58F0B69D
P 2650 3500
F 0 "C11" H 2765 3546 50  0000 L CNN
F 1 "1n" H 2765 3455 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 2688 3350 50  0001 C CNN
F 3 "" H 2650 3500 50  0001 C CNN
	1    2650 3500
	1    0    0    -1  
$EndComp
$Comp
L Screw_Terminal_1x02 J1
U 1 1 58F0B8AC
P 750 1500
F 0 "J1" H 830 1842 50  0000 C CNN
F 1 "VAC 230V" H 830 1751 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 750 1275 50  0001 C CNN
F 3 "" H 725 1500 50  0001 C CNN
	1    750  1500
	1    0    0    -1  
$EndComp
$Comp
L CP C10
U 1 1 58F0BEA4
P 4200 3250
F 0 "C10" H 4318 3296 50  0000 L CNN
F 1 "10u" H 4318 3205 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D5.0mm_P2.00mm" H 4238 3100 50  0001 C CNN
F 3 "" H 4200 3250 50  0001 C CNN
	1    4200 3250
	1    0    0    -1  
$EndComp
$Comp
L 2N3904 Q1
U 1 1 58F0BFA2
P 4700 3650
F 0 "Q1" V 5028 3650 50  0000 C CNN
F 1 "2N3904" V 4937 3650 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 4900 3575 50  0001 L CIN
F 3 "" H 4700 3650 50  0001 L CNN
	1    4700 3650
	0    1    -1   0   
$EndComp
$Comp
L D D5
U 1 1 58F0C123
P 4200 3800
F 0 "D5" V 4246 3721 50  0000 R CNN
F 1 "1N4841" V 4155 3721 50  0000 R CNN
F 2 "w_pth_diodes:diode_do35" H 4200 3800 50  0001 C CNN
F 3 "" H 4200 3800 50  0001 C CNN
	1    4200 3800
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 58F0C30F
P 4650 3000
F 0 "R2" V 4443 3000 50  0000 C CNN
F 1 "1k" V 4534 3000 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4580 3000 50  0001 C CNN
F 3 "" H 4650 3000 50  0001 C CNN
	1    4650 3000
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 58F0C75F
P 5900 2900
F 0 "R1" H 5830 2854 50  0000 R CNN
F 1 "10k" H 5830 2945 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5830 2900 50  0001 C CNN
F 3 "" H 5900 2900 50  0001 C CNN
	1    5900 2900
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR01
U 1 1 58F0C844
P 5900 3450
F 0 "#PWR01" H 5900 3200 50  0001 C CNN
F 1 "GND" H 5905 3277 50  0000 C CNN
F 2 "" H 5900 3450 50  0001 C CNN
F 3 "" H 5900 3450 50  0001 C CNN
	1    5900 3450
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR02
U 1 1 58F0CA70
P 5900 2650
F 0 "#PWR02" H 5900 2500 50  0001 C CNN
F 1 "VCC" H 5917 2823 50  0000 C CNN
F 2 "" H 5900 2650 50  0001 C CNN
F 3 "" H 5900 2650 50  0001 C CNN
	1    5900 2650
	1    0    0    -1  
$EndComp
Text Label 6100 3150 0    60   ~ 0
ZCROSS_PULSE
$Comp
L Screw_Terminal_1x02 J4
U 1 1 58F0D457
P 750 5400
F 0 "J4" H 830 5742 50  0000 C CNN
F 1 "Load output" H 830 5651 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 750 5175 50  0001 C CNN
F 3 "" H 725 5400 50  0001 C CNN
	1    750  5400
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 58F0D837
P 3100 4800
F 0 "R8" V 2893 4800 50  0000 C CNN
F 1 "470" V 2984 4800 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3030 4800 50  0001 C CNN
F 3 "" H 3100 4800 50  0001 C CNN
	1    3100 4800
	0    1    1    0   
$EndComp
$Comp
L R R9
U 1 1 58F0D8EA
P 3650 4800
F 0 "R9" V 3443 4800 50  0000 C CNN
F 1 "360" V 3534 4800 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3580 4800 50  0001 C CNN
F 3 "" H 3650 4800 50  0001 C CNN
	1    3650 4800
	0    1    1    0   
$EndComp
$Comp
L C C17
U 1 1 58F0D9A4
P 3400 5150
F 0 "C17" H 3515 5196 50  0000 L CNN
F 1 "1n" H 3515 5105 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D8.0mm_W5.0mm_P7.50mm" H 3438 5000 50  0001 C CNN
F 3 "" H 3400 5150 50  0001 C CNN
	1    3400 5150
	1    0    0    -1  
$EndComp
$Comp
L C C16
U 1 1 58F0DA06
P 2200 5050
F 0 "C16" H 2315 5096 50  0000 L CNN
F 1 "10n" H 2315 5005 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L16.5mm_W5.0mm_P15.00mm_MKT" H 2238 4900 50  0001 C CNN
F 3 "" H 2200 5050 50  0001 C CNN
	1    2200 5050
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 58F0DA5A
P 2200 5450
F 0 "R16" H 2130 5404 50  0000 R CNN
F 1 "47" H 2130 5495 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0414_L11.9mm_D4.5mm_P15.24mm_Horizontal" V 2130 5450 50  0001 C CNN
F 3 "" H 2200 5450 50  0001 C CNN
	1    2200 5450
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR03
U 1 1 58F0F278
P 4750 5100
F 0 "#PWR03" H 4750 4850 50  0001 C CNN
F 1 "GND" H 4755 4927 50  0000 C CNN
F 2 "" H 4750 5100 50  0001 C CNN
F 3 "" H 4750 5100 50  0001 C CNN
	1    4750 5100
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 58F0F31D
P 5000 4800
F 0 "R10" V 4793 4800 50  0000 C CNN
F 1 "1k" V 4884 4800 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4930 4800 50  0001 C CNN
F 3 "" H 5000 4800 50  0001 C CNN
	1    5000 4800
	0    1    1    0   
$EndComp
Text Label 5350 4800 0    60   ~ 0
TRIAC_DRIVE
$Comp
L CONN_02X04 J3
U 1 1 58F10E26
P 8850 4200
F 0 "J3" H 8850 4565 50  0000 C CNN
F 1 "ICP" H 8850 4474 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x04_Pitch2.54mm" H 8850 3000 50  0001 C CNN
F 3 "" H 8850 3000 50  0001 C CNN
	1    8850 4200
	1    0    0    -1  
$EndComp
Text Label 8600 4050 2    60   ~ 0
DBG
Text Label 8600 4150 2    60   ~ 0
MISO
Text Label 8600 4250 2    60   ~ 0
SCK
Text Label 8600 4350 2    60   ~ 0
RST
Text Label 9100 4350 0    60   ~ 0
GND
Text Label 9100 4050 0    60   ~ 0
GND
Text Label 9100 4250 0    60   ~ 0
MOSI
Text Label 9100 4150 0    60   ~ 0
VCC
$Comp
L C C8
U 1 1 58F118C8
P 10300 1950
F 0 "C8" H 10415 1996 50  0000 L CNN
F 1 "100n" H 10415 1905 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 10338 1800 50  0001 C CNN
F 3 "" H 10300 1950 50  0001 C CNN
	1    10300 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 58F119B3
P 10300 3600
F 0 "#PWR04" H 10300 3350 50  0001 C CNN
F 1 "GND" H 10305 3427 50  0000 C CNN
F 2 "" H 10300 3600 50  0001 C CNN
F 3 "" H 10300 3600 50  0001 C CNN
	1    10300 3600
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 58F11EE3
P 10300 950
F 0 "#PWR05" H 10300 800 50  0001 C CNN
F 1 "VCC" H 10317 1123 50  0000 C CNN
F 2 "" H 10300 950 50  0001 C CNN
F 3 "" H 10300 950 50  0001 C CNN
	1    10300 950 
	1    0    0    -1  
$EndComp
$Comp
L CP C3
U 1 1 58F130A0
P 3900 1500
F 0 "C3" H 4018 1546 50  0000 L CNN
F 1 "220u" H 4018 1455 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D8.0mm_P3.50mm" H 3938 1350 50  0001 C CNN
F 3 "" H 3900 1500 50  0001 C CNN
	1    3900 1500
	1    0    0    -1  
$EndComp
$Comp
L CP C6
U 1 1 58F1310E
P 5900 1500
F 0 "C6" H 6018 1546 50  0000 L CNN
F 1 "100u" H 6018 1455 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D5.0mm_P2.00mm" H 5938 1350 50  0001 C CNN
F 3 "" H 5900 1500 50  0001 C CNN
	1    5900 1500
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 58F1316C
P 4300 1500
F 0 "C4" H 4415 1546 50  0000 L CNN
F 1 "470n" H 4415 1455 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 4338 1350 50  0001 C CNN
F 3 "" H 4300 1500 50  0001 C CNN
	1    4300 1500
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 58F131DE
P 5450 1500
F 0 "C5" H 5565 1546 50  0000 L CNN
F 1 "100n" H 5565 1455 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 5488 1350 50  0001 C CNN
F 3 "" H 5450 1500 50  0001 C CNN
	1    5450 1500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR06
U 1 1 58F13E70
P 5900 950
F 0 "#PWR06" H 5900 800 50  0001 C CNN
F 1 "VCC" H 5917 1123 50  0000 C CNN
F 2 "" H 5900 950 50  0001 C CNN
F 3 "" H 5900 950 50  0001 C CNN
	1    5900 950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 58F13F62
P 5900 1950
F 0 "#PWR07" H 5900 1700 50  0001 C CNN
F 1 "GND" H 5905 1777 50  0000 C CNN
F 2 "" H 5900 1950 50  0001 C CNN
F 3 "" H 5900 1950 50  0001 C CNN
	1    5900 1950
	1    0    0    -1  
$EndComp
$Comp
L Rotary_Encoder_Switch SW1
U 1 1 58F17210
P 9600 5600
F 0 "SW1" H 9600 5325 50  0000 C CNN
F 1 "Rotary_Encoder_Switch" H 9600 5324 50  0001 C CNN
F 2 "w_misc_comp:encoder_alps-ec12d" H 9500 5760 50  0001 C CNN
F 3 "" H 9600 5860 50  0001 C CNN
	1    9600 5600
	-1   0    0    1   
$EndComp
$Comp
L TCRT5000 U5
U 1 1 58F1825E
P 6500 5500
F 0 "U5" H 6928 5553 60  0000 L CNN
F 1 "TCRT5000" H 6928 5447 60  0000 L CNN
F 2 "iotta_footprints:TCRT5000" V 6600 5500 60  0001 C CNN
F 3 "" V 6600 5500 60  0000 C CNN
	1    6500 5500
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 58F18A24
P 7800 5650
F 0 "#PWR08" H 7800 5400 50  0001 C CNN
F 1 "GND" H 7805 5477 50  0000 C CNN
F 2 "" H 7800 5650 50  0001 C CNN
F 3 "" H 7800 5650 50  0001 C CNN
	1    7800 5650
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 58F18D70
P 7800 5100
F 0 "R11" H 7869 5146 50  0000 L CNN
F 1 "220" H 7869 5055 50  0000 L CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7730 5100 50  0001 C CNN
F 3 "" H 7800 5100 50  0001 C CNN
	1    7800 5100
	-1   0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 58F19125
P 8000 5100
F 0 "R12" H 7930 5054 50  0000 R CNN
F 1 "10k" H 7930 5145 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7930 5100 50  0001 C CNN
F 3 "" H 8000 5100 50  0001 C CNN
	1    8000 5100
	-1   0    0    1   
$EndComp
Text Label 8250 5350 0    60   ~ 0
ROT_PULSE
$Comp
L VCC #PWR09
U 1 1 58F19F6D
P 7800 4750
F 0 "#PWR09" H 7800 4600 50  0001 C CNN
F 1 "VCC" H 7817 4923 50  0000 C CNN
F 2 "" H 7800 4750 50  0001 C CNN
F 3 "" H 7800 4750 50  0001 C CNN
	1    7800 4750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 58F1A44D
P 10050 5950
F 0 "#PWR010" H 10050 5700 50  0001 C CNN
F 1 "GND" H 10055 5777 50  0000 C CNN
F 2 "" H 10050 5950 50  0001 C CNN
F 3 "" H 10050 5950 50  0001 C CNN
	1    10050 5950
	1    0    0    -1  
$EndComp
Text Label 10500 5700 0    60   ~ 0
RENC_A
Text Label 10500 5500 0    60   ~ 0
RENC_B
Text Label 8900 5500 2    60   ~ 0
SW1
$Comp
L R R13
U 1 1 58F1AE5F
P 9200 5100
F 0 "R13" H 9130 5054 50  0000 R CNN
F 1 "10k" H 9130 5145 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 9130 5100 50  0001 C CNN
F 3 "" H 9200 5100 50  0001 C CNN
	1    9200 5100
	-1   0    0    1   
$EndComp
$Comp
L R R14
U 1 1 58F1AECF
P 10050 5100
F 0 "R14" H 9980 5054 50  0000 R CNN
F 1 "10k" H 9980 5145 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 9980 5100 50  0001 C CNN
F 3 "" H 10050 5100 50  0001 C CNN
	1    10050 5100
	-1   0    0    1   
$EndComp
$Comp
L R R15
U 1 1 58F1AF4F
P 10300 5100
F 0 "R15" H 10230 5054 50  0000 R CNN
F 1 "10k" H 10230 5145 50  0000 R CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 10230 5100 50  0001 C CNN
F 3 "" H 10300 5100 50  0001 C CNN
	1    10300 5100
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR011
U 1 1 58F1BEE5
P 10050 4700
F 0 "#PWR011" H 10050 4550 50  0001 C CNN
F 1 "VCC" H 10067 4873 50  0000 C CNN
F 2 "" H 10050 4700 50  0001 C CNN
F 3 "" H 10050 4700 50  0001 C CNN
	1    10050 4700
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 58F1C311
P 10600 4850
F 0 "C15" V 10348 4850 50  0000 C CNN
F 1 "100n" V 10439 4850 50  0000 C CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 10638 4700 50  0001 C CNN
F 3 "" H 10600 4850 50  0001 C CNN
	1    10600 4850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR012
U 1 1 58F1C6A9
P 10850 5000
F 0 "#PWR012" H 10850 4750 50  0001 C CNN
F 1 "GND" H 10855 4827 50  0000 C CNN
F 2 "" H 10850 5000 50  0001 C CNN
F 3 "" H 10850 5000 50  0001 C CNN
	1    10850 5000
	1    0    0    -1  
$EndComp
$Comp
L C C14
U 1 1 58F1C80E
P 7500 4850
F 0 "C14" V 7248 4850 50  0000 C CNN
F 1 "100n" V 7339 4850 50  0000 C CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 7538 4700 50  0001 C CNN
F 3 "" H 7500 4850 50  0001 C CNN
	1    7500 4850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR013
U 1 1 58F1C89A
P 7300 4950
F 0 "#PWR013" H 7300 4700 50  0001 C CNN
F 1 "GND" H 7305 4777 50  0000 C CNN
F 2 "" H 7300 4950 50  0001 C CNN
F 3 "" H 7300 4950 50  0001 C CNN
	1    7300 4950
	1    0    0    -1  
$EndComp
Text Label 1300 6750 2    60   ~ 0
MOSI
Text Label 1300 6850 2    60   ~ 0
SEG_CS
Text Label 1300 6950 2    60   ~ 0
SCK
$Comp
L GND #PWR014
U 1 1 58F1DDC1
P 1150 7150
F 0 "#PWR014" H 1150 6900 50  0001 C CNN
F 1 "GND" H 1155 6977 50  0000 C CNN
F 2 "" H 1150 7150 50  0001 C CNN
F 3 "" H 1150 7150 50  0001 C CNN
	1    1150 7150
	1    0    0    -1  
$EndComp
NoConn ~ 6550 7050
NoConn ~ 6550 6950
NoConn ~ 6550 6850
NoConn ~ 6550 6750
NoConn ~ 6550 6650
$Comp
L CONN_01X03 J5
U 1 1 58F2063E
P 7350 5500
F 0 "J5" H 7428 5495 50  0000 L CNN
F 1 "CONN_01X03" H 7428 5450 50  0001 L CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x03_Pitch2.54mm" H 7350 5500 50  0001 C CNN
F 3 "" H 7350 5500 50  0001 C CNN
	1    7350 5500
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J6
U 1 1 58F20706
P 7500 5500
F 0 "J6" H 7578 5495 50  0000 L CNN
F 1 "CONN_01X03" H 7419 5266 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x03_Pitch2.54mm" H 7500 5500 50  0001 C CNN
F 3 "" H 7500 5500 50  0001 C CNN
	1    7500 5500
	-1   0    0    -1  
$EndComp
Text Notes 6100 6200 0    60   ~ 0
Optical detector placed on separate PCB
$Comp
L CONN_02X05 J2
U 1 1 58F251A0
P 7450 4200
F 0 "J2" H 7450 4615 50  0000 C CNN
F 1 "AUX/CONTROL" H 7450 4524 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_2x05_Pitch2.54mm" H 7450 3000 50  0001 C CNN
F 3 "" H 7450 3000 50  0001 C CNN
	1    7450 4200
	1    0    0    -1  
$EndComp
Text Label 7700 4000 0    60   ~ 0
GND
Text Label 7700 4100 0    60   ~ 0
VCC
Text Label 7200 4000 2    60   ~ 0
SCL
Text Label 7200 4100 2    60   ~ 0
SDA
Text Label 7200 4200 2    60   ~ 0
RX
Text Label 7200 4300 2    60   ~ 0
TX
Text Label 7700 4300 0    60   ~ 0
GND
Text Label 7700 4200 0    60   ~ 0
PC3
$Comp
L C C2
U 1 1 58F26278
P 10850 1450
F 0 "C2" H 10735 1404 50  0000 R CNN
F 1 "100n" H 10735 1495 50  0000 R CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 10888 1300 50  0001 C CNN
F 3 "" H 10850 1450 50  0001 C CNN
	1    10850 1450
	-1   0    0    1   
$EndComp
$Comp
L C C1
U 1 1 58F269AF
P 10550 1450
F 0 "C1" H 10665 1496 50  0000 L CNN
F 1 "100n" H 10665 1405 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7.0mm_W2.5mm_P5.00mm" H 10588 1300 50  0001 C CNN
F 3 "" H 10550 1450 50  0001 C CNN
	1    10550 1450
	-1   0    0    -1  
$EndComp
Text Label 8300 3000 2    60   ~ 0
ZCROSS_PULSE
Text Label 8300 2150 2    60   ~ 0
SW1
Text Label 8300 1300 2    60   ~ 0
SEG_CS
Text Label 8300 1200 2    60   ~ 0
TRIAC_DRIVE
Text Label 8300 2900 2    60   ~ 0
ROT_PULSE
Text Label 8300 3300 2    60   ~ 0
RENC_B
Text Label 8300 3400 2    60   ~ 0
RENC_A
Text Label 8300 1400 2    60   ~ 0
MOSI
Text Label 8300 1500 2    60   ~ 0
MISO
Text Label 8300 1600 2    60   ~ 0
SCK
$Comp
L Crystal Y1
U 1 1 58F2C410
P 7350 1950
F 0 "Y1" V 7304 2081 50  0000 L CNN
F 1 "16MHz" V 7395 2081 50  0000 L CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 7350 1950 50  0001 C CNN
F 3 "" H 7350 1950 50  0001 C CNN
	1    7350 1950
	0    1    1    0   
$EndComp
$Comp
L C C7
U 1 1 58F2C4B6
P 7100 1700
F 0 "C7" V 6848 1700 50  0000 C CNN
F 1 "27p" V 6939 1700 50  0000 C CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4.6mm_W2.0mm_P2.50mm_MKS02_FKP02" H 7138 1550 50  0001 C CNN
F 3 "" H 7100 1700 50  0001 C CNN
	1    7100 1700
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 58F2C556
P 7100 2200
F 0 "C9" V 6848 2200 50  0000 C CNN
F 1 "27p" V 6939 2200 50  0000 C CNN
F 2 "Capacitors_ThroughHole:C_Rect_L4.6mm_W2.0mm_P2.50mm_MKS02_FKP02" H 7138 2050 50  0001 C CNN
F 3 "" H 7100 2200 50  0001 C CNN
	1    7100 2200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR015
U 1 1 58F2C665
P 6850 2350
F 0 "#PWR015" H 6850 2100 50  0001 C CNN
F 1 "GND" H 6855 2177 50  0000 C CNN
F 2 "" H 6850 2350 50  0001 C CNN
F 3 "" H 6850 2350 50  0001 C CNN
	1    6850 2350
	1    0    0    -1  
$EndComp
Text Label 8300 2550 2    60   ~ 0
RST
Text Label 8300 2450 2    60   ~ 0
SCL
Text Label 8300 2350 2    60   ~ 0
SDA
Text Label 8300 2250 2    60   ~ 0
PC3
Text Label 8300 2700 2    60   ~ 0
RX
Text Label 8300 2800 2    60   ~ 0
TX
Text Label 7700 4400 0    60   ~ 0
PD7
Text Label 7200 4400 2    60   ~ 0
PD6
Text Label 8300 2050 2    60   ~ 0
PD7
Text Label 8300 1950 2    60   ~ 0
PD6
NoConn ~ 8300 1100
$Comp
L Transformer_spitznagel_SPK01406 T1
U 1 1 58F121ED
P 1900 1400
F 0 "T1" H 2000 1050 50  0000 C CNN
F 1 "230 - 6VAC (Spitznagel SPK 01406)" H 2000 650 50  0000 C CNN
F 2 "Transformers_CHK:Trafo_CHK-EI30-2VA_1xSec" H 1900 1400 50  0001 C CNN
F 3 "" H 1900 1400 50  0001 C CNN
	1    1900 1400
	1    0    0    1   
$EndComp
Wire Wire Line
	1250 3300 1600 3300
Wire Wire Line
	1450 1600 1450 4800
Wire Wire Line
	1900 3700 2100 3700
Wire Wire Line
	1900 3300 2100 3300
Wire Wire Line
	2400 3300 2900 3300
Wire Wire Line
	2650 3000 2650 3350
Wire Wire Line
	2650 3000 2900 3000
Connection ~ 2650 3300
Wire Wire Line
	2400 3700 2900 3700
Wire Wire Line
	2650 3650 2650 4000
Wire Wire Line
	2650 4000 2900 4000
Connection ~ 2650 3700
Wire Wire Line
	3200 3000 4500 3000
Wire Wire Line
	3200 3300 3550 3300
Wire Wire Line
	3200 4000 4700 4000
Wire Wire Line
	4700 4000 4700 3850
Wire Wire Line
	4200 3950 4200 4000
Connection ~ 4200 4000
Wire Wire Line
	4200 3400 4200 3650
Wire Wire Line
	4500 3550 4200 3550
Connection ~ 4200 3550
Wire Wire Line
	4200 3000 4200 3100
Connection ~ 4200 3000
Wire Wire Line
	4800 3000 4950 3000
Wire Wire Line
	4950 3000 4950 3150
Wire Wire Line
	4950 3150 5050 3150
Wire Wire Line
	5050 3350 4950 3350
Wire Wire Line
	4950 3350 4950 3550
Wire Wire Line
	4950 3550 4900 3550
Wire Wire Line
	5650 3350 5900 3350
Wire Wire Line
	5900 3350 5900 3450
Wire Wire Line
	5650 3150 6100 3150
Wire Wire Line
	5900 3050 5900 3150
Connection ~ 5900 3150
Wire Wire Line
	5900 2650 5900 2750
Wire Wire Line
	1250 1200 1250 5300
Wire Wire Line
	1250 5300 950  5300
Wire Wire Line
	1450 4800 2950 4800
Wire Wire Line
	2700 4800 2700 5100
Wire Wire Line
	2200 4900 2200 4800
Connection ~ 2200 4800
Wire Wire Line
	3250 4800 3500 4800
Wire Wire Line
	3400 4800 3400 5000
Connection ~ 3400 4800
Wire Wire Line
	4050 4800 3800 4800
Connection ~ 2700 4800
Wire Wire Line
	950  5500 1250 5500
Wire Wire Line
	1250 5500 1250 5700
Wire Wire Line
	1250 5700 3400 5700
Wire Wire Line
	3400 5700 3400 5300
Wire Wire Line
	2700 5400 2700 5700
Connection ~ 2700 5700
Wire Wire Line
	2200 5600 2200 5700
Connection ~ 2200 5700
Wire Wire Line
	2200 5300 2200 5200
Wire Wire Line
	2850 5350 3950 5350
Wire Wire Line
	3950 5350 3950 5000
Wire Wire Line
	3950 5000 4050 5000
Wire Wire Line
	4650 5000 4750 5000
Wire Wire Line
	4750 5000 4750 5100
Wire Wire Line
	4650 4800 4850 4800
Wire Wire Line
	5150 4800 5350 4800
Wire Wire Line
	10300 2100 10300 3600
Wire Wire Line
	10200 1700 10300 1700
Wire Wire Line
	10300 1700 10300 1800
Wire Wire Line
	10200 3400 10300 3400
Connection ~ 10300 3400
Wire Wire Line
	10850 3300 10200 3300
Connection ~ 10300 3300
Wire Wire Line
	10200 1100 10850 1100
Wire Wire Line
	10300 950  10300 1400
Wire Wire Line
	10300 1400 10200 1400
Connection ~ 10300 1100
Wire Wire Line
	2300 1200 2450 1200
Wire Wire Line
	2450 1200 2450 1050
Wire Wire Line
	2450 1050 3150 1050
Wire Wire Line
	3150 1050 3150 1100
Wire Wire Line
	2300 1600 2450 1600
Wire Wire Line
	2450 1600 2450 1750
Wire Wire Line
	2450 1750 3150 1750
Wire Wire Line
	3150 1750 3150 1700
Wire Wire Line
	3450 1400 3600 1400
Wire Wire Line
	3600 1400 3600 1050
Wire Wire Line
	3600 1050 4400 1050
Wire Wire Line
	2850 1400 2750 1400
Wire Wire Line
	2750 1400 2750 1900
Wire Wire Line
	2750 1900 5900 1900
Wire Wire Line
	4800 1900 4800 1350
Wire Wire Line
	3900 1350 3900 1050
Connection ~ 3900 1050
Wire Wire Line
	3900 1650 3900 1900
Connection ~ 3900 1900
Wire Wire Line
	4300 1650 4300 1900
Connection ~ 4300 1900
Wire Wire Line
	4300 600  4300 1350
Connection ~ 4300 1050
Wire Wire Line
	5900 1650 5900 1950
Connection ~ 4800 1900
Wire Wire Line
	5450 1650 5450 1900
Connection ~ 5450 1900
Wire Wire Line
	5200 1050 5900 1050
Wire Wire Line
	5900 950  5900 1350
Wire Wire Line
	5450 1050 5450 1350
Connection ~ 5450 1050
Connection ~ 5900 1050
Connection ~ 5900 1900
Wire Wire Line
	950  1600 1500 1600
Wire Wire Line
	1250 1200 1500 1200
Connection ~ 1450 3700
Connection ~ 1250 3300
Connection ~ 1450 1600
Wire Wire Line
	950  1400 1250 1400
Connection ~ 1250 1400
Wire Wire Line
	1450 3700 1600 3700
Wire Wire Line
	8000 5250 8000 5500
Wire Wire Line
	8000 5350 8250 5350
Connection ~ 8000 5350
Wire Wire Line
	7800 4750 7800 4950
Wire Wire Line
	7650 4850 8000 4850
Wire Wire Line
	8000 4850 8000 4950
Connection ~ 7800 4850
Wire Wire Line
	9900 5600 10050 5600
Wire Wire Line
	10050 5600 10050 5950
Wire Wire Line
	9300 5700 9200 5700
Wire Wire Line
	9200 5700 9200 5900
Wire Wire Line
	9200 5900 10050 5900
Connection ~ 10050 5900
Wire Wire Line
	8900 5500 9300 5500
Wire Wire Line
	9900 5500 10500 5500
Wire Wire Line
	9900 5700 10500 5700
Connection ~ 10050 5500
Connection ~ 10300 5700
Connection ~ 9200 5500
Wire Wire Line
	10300 5250 10300 5700
Wire Wire Line
	10050 5250 10050 5500
Wire Wire Line
	9200 5250 9200 5500
Wire Wire Line
	9200 4950 9200 4850
Wire Wire Line
	9200 4850 10450 4850
Wire Wire Line
	10300 4850 10300 4950
Wire Wire Line
	10050 4700 10050 4950
Connection ~ 10050 4850
Connection ~ 10300 4850
Wire Wire Line
	10750 4850 10850 4850
Wire Wire Line
	10850 4850 10850 5000
Wire Wire Line
	7300 4950 7300 4850
Wire Wire Line
	7300 4850 7350 4850
Wire Wire Line
	1150 7050 1150 7150
Wire Wire Line
	1150 7050 1300 7050
Wire Wire Line
	7700 5400 7800 5400
Wire Wire Line
	7800 5400 7800 5250
Wire Wire Line
	8000 5500 7700 5500
Wire Wire Line
	7800 5650 7800 5600
Wire Wire Line
	7800 5600 7700 5600
Wire Wire Line
	6350 5900 6350 6000
Wire Wire Line
	6350 6000 7050 6000
Wire Wire Line
	7050 6000 7050 5600
Wire Wire Line
	7050 5600 7150 5600
Wire Wire Line
	6650 5900 6650 6000
Connection ~ 6650 6000
Wire Wire Line
	7150 5400 7150 4850
Wire Wire Line
	7150 4850 6350 4850
Wire Wire Line
	6350 4850 6350 5100
Wire Wire Line
	6650 5100 6650 5000
Wire Wire Line
	6650 5000 7050 5000
Wire Wire Line
	7050 5000 7050 5500
Wire Wire Line
	7050 5500 7150 5500
Wire Wire Line
	10850 1100 10850 1300
Wire Wire Line
	10550 1100 10550 1300
Connection ~ 10550 1100
Wire Wire Line
	10550 1600 10550 1800
Connection ~ 10850 1800
Wire Wire Line
	10850 1600 10850 3300
Wire Wire Line
	10550 1800 10850 1800
Wire Wire Line
	7250 1700 8300 1700
Wire Wire Line
	7350 1700 7350 1800
Wire Wire Line
	6950 1700 6850 1700
Wire Wire Line
	6850 1700 6850 2350
Wire Wire Line
	6950 2200 6850 2200
Connection ~ 6850 2200
Wire Wire Line
	7250 2200 7700 2200
Wire Wire Line
	7350 2200 7350 2100
Connection ~ 7350 2200
Connection ~ 7350 1700
Wire Notes Line
	1900 800  1900 2450
Wire Notes Line
	1900 2450 5350 2450
Wire Notes Line
	5350 2450 5350 4350
Wire Notes Line
	5350 4350 4350 4350
Wire Notes Line
	4350 4350 4350 6050
Wire Notes Line
	4350 6050 650  6050
Wire Notes Line
	1900 800  650  800 
$Comp
L D_Bridge_+AA- D1
U 1 1 58F0DEBA
P 3150 1400
F 0 "D1" H 3100 1400 50  0000 L CNN
F 1 "D_Bridge_+AA-" H 3300 1100 50  0001 L CNN
F 2 "w_pth_diodes:bridge_wob" H 3150 1400 50  0001 C CNN
F 3 "" H 3150 1400 50  0001 C CNN
	1    3150 1400
	1    0    0    -1  
$EndComp
$Comp
L LM7805CT U1
U 1 1 58F0F97F
P 4800 1100
F 0 "U1" H 4800 1417 50  0000 C CNN
F 1 "LM2940CT-5.0" H 4800 1326 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Horizontal" H 4800 1200 50  0001 C CIN
F 3 "" H 4800 1100 50  0001 C CNN
	1    4800 1100
	1    0    0    -1  
$EndComp
Text Label 1250 3300 2    60   ~ 0
VAC_N
Text Label 1450 3700 2    60   ~ 0
VAC_L
Wire Wire Line
	3550 3300 3550 4000
Connection ~ 3550 4000
Wire Wire Line
	3200 3700 3400 3700
Wire Wire Line
	3400 3700 3400 3000
Connection ~ 3400 3000
Wire Wire Line
	3850 3350 3850 3000
Connection ~ 3850 3000
Wire Wire Line
	3850 3650 3850 4000
Connection ~ 3850 4000
$Comp
L iotta_logo CASE1
U 1 1 58F16C0B
P 7050 7050
F 0 "CASE1" H 7678 7203 60  0000 L CNN
F 1 "Case" H 7678 7150 60  0001 L CNN
F 2 "iotta_footprints:CASE_KEMO_G085N" H 7678 7097 60  0000 L CNN
F 3 "" H 7050 7050 60  0000 C CNN
	1    7050 7050
	1    0    0    -1  
$EndComp
$Comp
L AP111750 U6
U 1 1 58F26D3E
P 6700 800
F 0 "U6" H 6700 1167 50  0000 C CNN
F 1 "LT1117-5" H 6700 1076 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:SOT-223" H 6700 450 50  0001 C CNN
F 3 "" H 6800 550 50  0001 C CNN
	1    6700 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1800 7700 1800
Wire Wire Line
	7700 1800 7700 2200
$Comp
L GND #PWR016
U 1 1 58F2841B
P 6700 1100
F 0 "#PWR016" H 6700 850 50  0001 C CNN
F 1 "GND" H 6705 927 50  0000 C CNN
F 2 "" H 6700 1100 50  0001 C CNN
F 3 "" H 6700 1100 50  0001 C CNN
	1    6700 1100
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR017
U 1 1 58F2849C
P 7100 750
F 0 "#PWR017" H 7100 600 50  0001 C CNN
F 1 "VCC" H 7117 923 50  0000 C CNN
F 2 "" H 7100 750 50  0001 C CNN
F 3 "" H 7100 750 50  0001 C CNN
	1    7100 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 800  6250 800 
Wire Wire Line
	6250 800  6250 600 
Wire Wire Line
	6250 600  4300 600 
Wire Wire Line
	7000 800  7100 800 
Wire Wire Line
	7100 800  7100 750 
Text Notes 7250 800  0    60   ~ 0
LT1117 Regulator SMD alternative\nfor LM2940 (place either one!)
$Comp
L iotta_logo WIRESTRAP1
U 1 1 58F22411
P 7050 6800
F 0 "WIRESTRAP1" H 7678 7006 60  0000 L CNN
F 1 "2x Ziplock wire strap" H 7678 6900 60  0000 L CNN
F 2 "iotta_footprints:WireStrap_2X" H 7678 6794 60  0000 L CNN
F 3 "" H 7050 6800 60  0000 C CNN
	1    7050 6800
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR018
U 1 1 58F2533F
P 1150 6550
F 0 "#PWR018" H 1150 6400 50  0001 C CNN
F 1 "VCC" H 1167 6723 50  0000 C CNN
F 2 "" H 1150 6550 50  0001 C CNN
F 3 "" H 1150 6550 50  0001 C CNN
	1    1150 6550
	1    0    0    -1  
$EndComp
Text Label 8300 3100 2    60   ~ 0
DBG
Wire Wire Line
	1150 6550 1150 6650
Wire Wire Line
	1150 6650 1300 6650
$EndSCHEMATC
